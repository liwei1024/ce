#include "kce.h"
KCE_TARGET_PROCESS_INFO_STRUCT g_TargetProcessInfo;


/// <summary>(����/����)���̴���</summary>
VOID KCE_ProcessNotify(
	_Inout_  PEPROCESS              Process,
	_In_     HANDLE                 ProcessId,
	_In_opt_ PPS_CREATE_NOTIFY_INFO CreateInfo
) 
{
	UNREFERENCED_PARAMETER(Process);
	UNREFERENCED_PARAMETER(ProcessId);
	UNREFERENCED_PARAMETER(CreateInfo);
}

/// <summary>���������豸</summary>
NTSTATUS KCE_CreateDevice(
	IN PDRIVER_OBJECT DriverObject
)
{
	PDEVICE_OBJECT DeviceObject;
	UNICODE_STRING DeviceName;
	UNICODE_STRING SymbolicLinkName;
	NTSTATUS Status = STATUS_SUCCESS;

	RtlInitUnicodeString(&DeviceName, DEVICE_NAME);
	Status = IoCreateDevice(DriverObject, 0, &DeviceName, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &DeviceObject);
	if (!NT_SUCCESS(Status))return Status;

	RtlInitUnicodeString(&SymbolicLinkName, SYMBOLIC_LINK_NAME);
	Status = IoCreateSymbolicLink(&SymbolicLinkName, &DeviceName);
	if (!NT_SUCCESS(Status)) {
		IoDeleteDevice(DeviceObject);
		return Status;
	}

	DeviceObject->Flags &= (~DO_DEVICE_INITIALIZING);

	return Status;
}

/// <summary>ռ���� ������</summary>
NTSTATUS KCE_DefaultDispatchFunction(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
)
{
	UNICODE_STRING DeviceName;
	UNREFERENCED_PARAMETER(DeviceObject);

	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return STATUS_SUCCESS;
}

/// <summary>ж������</summary>
VOID KCE_DriverUnload(
	IN PDRIVER_OBJECT DriverObject
)
{
	UNICODE_STRING SymbolicLinkName;

	PsSetCreateProcessNotifyRoutineEx(KCE_ProcessNotify, TRUE);

	RtlInitUnicodeString(&SymbolicLinkName, SYMBOLIC_LINK_NAME);
	IoDeleteSymbolicLink(&SymbolicLinkName);

	IoDeleteDevice(DriverObject->DeviceObject);
}

/// <summary>�������</summary>
NTSTATUS DriverEntry(
	IN PDRIVER_OBJECT DriverObject,
	IN PUNICODE_STRING RegistryPath
)
{
	UNREFERENCED_PARAMETER(RegistryPath);

	NTSTATUS Status = STATUS_SUCCESS;
	
	Status = PsSetCreateProcessNotifyRoutineEx(KCE_ProcessNotify, FALSE);// �������̼��ӻص�

	if (NT_SUCCESS(Status)) {
		for (size_t i = 0; i < IRP_MJ_MAXIMUM_FUNCTION; i++)
			DriverObject->MajorFunction[i] = KCE_DefaultDispatchFunction;

		DriverObject->MajorFunction[IRP_MJ_DEVICE_CONTROL] = KCE_DispatchDeviceControl;
		DriverObject->DriverUnload = KCE_DriverUnload;
		DriverObject->Flags |= DO_BUFFERED_IO;

		Status = KCE_CreateDevice(DriverObject);
	}

	return Status;
}