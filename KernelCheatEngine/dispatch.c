#include "kce.h"

NTSTATUS KCE_DispatchDeviceControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
)
{
	NTSTATUS Status = STATUS_SUCCESS;
	PIO_STACK_LOCATION Stack;
	PKCE_READ_VIRTUAL_MEMORY_STRUCT rvms;
	PKCE_WRITE_VIRTUAL_MEMORY_STRUCT wvms;
	ULONG IoControlCode;

	//得到当前堆栈
	Stack = IoGetCurrentIrpStackLocation(Irp);

	if (Stack && Irp->AssociatedIrp.SystemBuffer) {
		IoControlCode = Stack->Parameters.DeviceIoControl.IoControlCode;
		switch (IoControlCode)
		{
		case KCE_READ_VIRTUAL_MEMORY: 
			{
				rvms = (PKCE_READ_VIRTUAL_MEMORY_STRUCT)Irp->AssociatedIrp.SystemBuffer;
				if (rvms)
				{
					Status = KCE_ReadVirtualMemory(rvms);
				}
				Irp->IoStatus.Information = sizeof(KCE_READ_VIRTUAL_MEMORY_STRUCT);
			}
			break;
		case KCE_WRITE_VIRTUAL_MEMORY:
			{
				wvms = (PKCE_WRITE_VIRTUAL_MEMORY_STRUCT)Irp->AssociatedIrp.SystemBuffer;
				if (wvms)
				{
					Status = KCE_WriteVirtualMemory(wvms);
				}
				Irp->IoStatus.Information = sizeof(KCE_WRITE_VIRTUAL_MEMORY_STRUCT);
			}
			break;
		case KCE_PROTECT_PROCESS:
			{
				
			}
			break;
		default:
			break;
		}
	}

	Irp->IoStatus.Status = Status;
	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return Status;
}