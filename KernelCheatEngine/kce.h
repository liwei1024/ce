

#include "active.h"
#include "kce_api.h"

#ifdef DEBUG
#define dprintf(Format, ...) DbgPrint("KCA: " Format "\n", __VA_ARGS__)
#endif // DEBUG



typedef struct _TARGET_PROCESS_INFO
{
	PEPROCESS Process;
	HANDLE ProcessId;
	HANDLE ProcessHandle;
	PVOID ProcessBaseAddress;

	HANDLE MainThreadId;
	PETHREAD MainThread;
	HANDLE MainThreadHandle;

	BOOLEAN ProcessStatus;

}KCE_TARGET_PROCESS_INFO_STRUCT, *PKCE_TARGET_PROCESS_INFO_STRUCT;

extern KCE_TARGET_PROCESS_INFO_STRUCT g_TargetProcessInfo;

/// dispatch
NTSTATUS KCE_DispatchDeviceControl(
	IN PDEVICE_OBJECT DeviceObject,
	IN PIRP Irp
);


/// <summary>¶ÁÐéÄâÄÚ´æ</summary>
NTSTATUS KCE_ReadVirtualMemory(
	PKCE_READ_VIRTUAL_MEMORY_STRUCT rvms
);
/// <summary>Ð´ÐéÄâÄÚ´æ</summary>
NTSTATUS KCE_WriteVirtualMemory(
	PKCE_WRITE_VIRTUAL_MEMORY_STRUCT wvms
);

