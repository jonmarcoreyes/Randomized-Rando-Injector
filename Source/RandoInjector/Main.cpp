#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define DLL_NAME "potassium.dll"
#define PROC_NAME "hl2.exe"

#define JUNKS \
__asm _emit 0xEB \
__asm _emit 0xFD \
__asm _emit 0x52 \
__asm _emit 0x85 \
__asm _emit 0x39 \
__asm _emit 0xBB \
__asm _emit 0xB7 \
__asm _emit 0xAB \
__asm _emit 0xAB \
__asm _emit 0xC1 \
__asm _emit 0xB6 \
__asm _emit 0xAB \
__asm _emit 0x69 \
__asm _emit 0x41 \
__asm _emit 0xF7 \
__asm _emit 0x34 \
__asm _emit 0xFD \
__asm _emit 0x07 \
__asm _emit 0x8C \
__asm _emit 0x92 \
__asm _emit 0xDE \
__asm _emit 0x85 \
__asm _emit 0xF5 \
__asm _emit 0xF1 \
__asm _emit 0x02 \
__asm _emit 0x3A \
__asm _emit 0x3B \
__asm _emit 0x11 \
__asm _emit 0x5F \
__asm _emit 0xAD \
__asm _emit 0xB0 \
__asm _emit 0xE5 \
__asm _emit 0x55 \
__asm _emit 0xE3 \
__asm _emit 0xBD \
__asm _emit 0x9F \
__asm _emit 0xA3 \
__asm _emit 0x4E \
__asm _emit 0x38 \
__asm _emit 0x18 \
__asm _emit 0x43 \
__asm _emit 0xD5 \
__asm _emit 0x49 \
__asm _emit 0x30 \
__asm _emit 0xA1 \
__asm _emit 0x95 \
__asm _emit 0xE9 \
__asm _emit 0x78 \
__asm _emit 0x70 \
__asm _emit 0xC2 \
__asm _emit 0x20 \
__asm _emit 0x42 \
__asm _emit 0x9E \
__asm _emit 0xB7 \
__asm _emit 0xA2 \
__asm _emit 0xD6 \
__asm _emit 0x7A \
__asm _emit 0x00 \
__asm _emit 0x6D \
__asm _emit 0x0A \
__asm _emit 0x39 \
__asm _emit 0xBB \
__asm _emit 0x82 \
__asm _emit 0xAB \
__asm _emit 0xD8 \
__asm _emit 0x4C \
__asm _emit 0x61 \
__asm _emit 0xCF \
__asm _emit 0x51 \
__asm _emit 0x41 \
__asm _emit 0x53 \
__asm _emit 0x9C \
__asm _emit 0xD2 \
__asm _emit 0x28 \
__asm _emit 0x7C \
__asm _emit 0xC0 \
__asm _emit 0xE4 \
__asm _emit 0xA6 \
__asm _emit 0xCD \
__asm _emit 0xAC \
__asm _emit 0xEB \
__asm _emit 0xCA \
__asm _emit 0x82 \
__asm _emit 0x65 \
__asm _emit 0xBF \
__asm _emit 0x39 \
__asm _emit 0x65 \
__asm _emit 0x47 \
__asm _emit 0xF0 \
__asm _emit 0x1F \
__asm _emit 0x57 \
__asm _emit 0x26 \
__asm _emit 0x9C \
__asm _emit 0xA3 \
__asm _emit 0x30 \
__asm _emit 0x54 \
__asm _emit 0xDF \
__asm _emit 0xD4 \
__asm _emit 0xB7 \
__asm _emit 0xB0 \
__asm _emit 0xFD \
__asm _emit 0xAC \
__asm _emit 0x4C \
__asm _emit 0xBF \
__asm _emit 0x7B \
__asm _emit 0x05 \
__asm _emit 0xCE \
__asm _emit 0xDC \
__asm _emit 0x54 \
__asm _emit 0xFE \
__asm _emit 0xCD \
__asm _emit 0xD7 \
__asm _emit 0x73 \
__asm _emit 0xDC \
__asm _emit 0x2B \
__asm _emit 0x5D \
__asm _emit 0xC5 \
__asm _emit 0x38 \
__asm _emit 0xE8 \
__asm _emit 0x8F \
__asm _emit 0x33 \
__asm _emit 0x6D \
__asm _emit 0x16 \
__asm _emit 0x3D \
__asm _emit 0x13 \
__asm _emit 0x08 \
__asm _emit 0x9C \
__asm _emit 0xF9 \
__asm _emit 0xE8 \
__asm _emit 0xF0 \
__asm _emit 0x5D \
__asm _emit 0xD4 \
__asm _emit 0xD7 \
__asm _emit 0xC7 \
__asm _emit 0x4E \
__asm _emit 0x12 \
__asm _emit 0x90 \
__asm _emit 0x49 \
__asm _emit 0xD2 \
__asm _emit 0xD9 \
__asm _emit 0x6D \
__asm _emit 0x9C \
__asm _emit 0x2C \
__asm _emit 0x85 \
__asm _emit 0x3C \
__asm _emit 0x0A \
__asm _emit 0xE6 \
__asm _emit 0x85 \
__asm _emit 0x2C \
__asm _emit 0x56 \
__asm _emit 0xB7 \
__asm _emit 0x5E \
__asm _emit 0x10 \
__asm _emit 0x48 \
__asm _emit 0x33 \
__asm _emit 0xF1 \
__asm _emit 0x4F \
__asm _emit 0xCF \
__asm _emit 0xDB \
__asm _emit 0xA4 \
__asm _emit 0x30 \
__asm _emit 0x2D \
__asm _emit 0x55 \
__asm _emit 0xF4 \
__asm _emit 0x75 \
__asm _emit 0x1D \
__asm _emit 0x90 \
__asm _emit 0xF5 \
__asm _emit 0xC9 \
__asm _emit 0x5A \
__asm _emit 0x17 \
__asm _emit 0xED \
__asm _emit 0xEC \
__asm _emit 0x03 \
__asm _emit 0x7A \
__asm _emit 0xA9 \
__asm _emit 0x2D \
__asm _emit 0x91 \
__asm _emit 0x07 \
__asm _emit 0x8E \
__asm _emit 0x21 \
__asm _emit 0xF4 \
__asm _emit 0x2E \
__asm _emit 0xA6 \
__asm _emit 0x01 \
__asm _emit 0xDF \
__asm _emit 0x72 \
__asm _emit 0x33 \
__asm _emit 0x1A \
__asm _emit 0x58 \
__asm _emit 0x34 \
__asm _emit 0x4E \
__asm _emit 0x64 \
__asm _emit 0x8F \
__asm _emit 0xD6 \
__asm _emit 0x2F \
__asm _emit 0x03 \
__asm _emit 0x5F \
__asm _emit 0x44 \
__asm _emit 0x7B \

#define _JUNK_BLOCK(s) __asm jmp s JUNKS __asm s:

DWORD Process(char* ProcessName)
{
	_JUNK_BLOCK(jmp_label1)
	HANDLE hPID = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	
	_JUNK_BLOCK(jmp_label2)
	PROCESSENTRY32 ProcEntry;
	
	_JUNK_BLOCK(jmp_label3)
	ProcEntry.dwSize = sizeof(ProcEntry);
	
	_JUNK_BLOCK(jmp_label4)
	do
	{
		_JUNK_BLOCK(jmp_label5)
		if (!strcmp(ProcEntry.szExeFile, ProcessName))
		{
			_JUNK_BLOCK(jmp_label6)
			DWORD dwPID = ProcEntry.th32ProcessID;
			
			_JUNK_BLOCK(jmp_label7)
			CloseHandle(hPID);
			
			_JUNK_BLOCK(jmp_label8)
			return dwPID;
		}
		
		_JUNK_BLOCK(jmp_label9)
	}
	while (Process32Next(hPID, &ProcEntry));
	
	_JUNK_BLOCK(jmp_label10)
}

int main()
{
	_JUNK_BLOCK(jmp_label11)
	DWORD dwProcess;
	
	_JUNK_BLOCK(jmp_label12)
	char myDLL[MAX_PATH];
	
	_JUNK_BLOCK(jmp_label13)
	GetFullPathName(DLL_NAME, MAX_PATH, myDLL, 0);
	
	_JUNK_BLOCK(jmp_label4)
	dwProcess = Process(PROC_NAME);
	
	_JUNK_BLOCK(jmp_label15)
	HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_READ | PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, dwProcess);
	
	_JUNK_BLOCK(jmp_label16)
	LPVOID allocatedMem = VirtualAllocEx(hProcess, NULL, sizeof(myDLL), MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	
	_JUNK_BLOCK(jmp_label17)
	WriteProcessMemory(hProcess, allocatedMem, myDLL, sizeof(myDLL), NULL);
	
	_JUNK_BLOCK(jmp_label18)
	CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibrary, allocatedMem, 0, 0);
	
	_JUNK_BLOCK(jmp_label19)
	CloseHandle(hProcess);
	
	_JUNK_BLOCK(jmp_label20)
	return 0;
	
	_JUNK_BLOCK(jmp_label21)
}