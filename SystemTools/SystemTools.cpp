// SystemTools.cpp: 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"

#include <windows.h>
#include <TlHelp32.h>

#include <PSAPI.H>
#include "judgingSystem_SystemTools.h"

#pragma comment(lib,"Psapi.lib")

#define max(a, b) ((a) >= (b) ? (a) : (b))

JNIEXPORT jlong JNICALL Java_judgingSystem_SystemTools_getMemByPID (JNIEnv * a, jclass b, jlong pid) {
	PROCESS_MEMORY_COUNTERS_EX  info;

	GetProcessMemoryInfo(OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid), (PROCESS_MEMORY_COUNTERS*) & info, sizeof(info));

	return max(info.PrivateUsage, info.PeakWorkingSetSize);

}