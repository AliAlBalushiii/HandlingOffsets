#include <iostream>
#include <Windows.h>
#include <tlhelp32.h>
#include "HandlingOffsets.h"



uintptr_t GetModuleBase(DWORD pid, const wchar_t* gameName) {
    uintptr_t baseAddress = 0;
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, pid);
    MODULEENTRY32 entry;
    entry.dwSize = sizeof(entry);

    if (Module32First(hSnap,&entry))
    {
        do {
            if (!_wcsicmp(entry.szModule, gameName))
            {
                baseAddress = (uintptr_t)entry.modBaseAddr;
                break;
            }

           }while(Module32Next(hSnap,&entry));
    }

    CloseHandle(hSnap);
    return baseAddress;
}

int main()
{
    DWORD pid;
    HWND hwnd = FindWindowA(NULL, "AssaultCube");

    DWORD id = GetWindowThreadProcessId(hwnd, &pid);
    HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

    uintptr_t baseAddress;
    const wchar_t* gameName = L"ac_client.exe";
    baseAddress = GetModuleBase(pid, gameName);

    uintptr_t localPlayer;
    ReadProcessMemory(proc, (LPCVOID)(baseAddress + offsets::LocalPlayer), &localPlayer, sizeof(localPlayer), NULL);

    int health;
    while (true) {
        ReadProcessMemory(proc, (LPCVOID)(localPlayer + offsets::health), &health, sizeof(health), NULL);
        std::cout << health << std::endl;
    }
}
