#include <ext-funcs.h>

bool GetProcessIdByName(const std::string& processName, DWORD& procID) {
    // Enumerate processes
    DWORD processList[1024], bytesNeeded;
    if (!EnumProcesses(processList, sizeof(processList), &bytesNeeded)) {
        return false;
    }

    for (unsigned int i = 0; i < (bytesNeeded / sizeof(DWORD)); i++) {
        DWORD pid = processList[i];
        if (pid == 0) continue;

        // Open the process to get its filename
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, pid);
        if (hProcess) {
            char processPath[MAX_PATH];
            if (GetModuleFileNameExA(hProcess, NULL, processPath, sizeof(processPath) / sizeof(char))) {
                // Compare process file name with "Terraria.exe"
                if (std::string(processPath).find("Terraria.exe") != std::string::npos) {
                    procID = pid;
                    CloseHandle(hProcess);
                    return true;
                }
            }
            CloseHandle(hProcess);
        }
    }

    return false;
}