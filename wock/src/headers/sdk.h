#pragma once
#include <includes.h>
#include <offsets.h>
#include <ext-funcs.h>

#define getLocalPlayer 0x1E64FCF8

Offsets* offsets = new Offsets();

class Game{
public:
	int* g_LocalPlayer;
};

struct vec2 {
	float x, y;
};

class LocalPlayer: public Game{
public:
	int* g_Inventory;
	void setHealth(int newhp) {
		DWORD procId;
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			WriteProcessMemory(process, (LPVOID)(localplayer + offsets->health), &newhp, sizeof(newhp), 0);
		}
		return;
	}
	void setGhost(bool state) {
		DWORD procId;
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			WriteProcessMemory(process, (LPVOID)(localplayer + offsets->ghost), &state, sizeof(state), 0);
		}
		return;
	}
	void setPosition(vec2* pos) {
		DWORD procId;
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			WriteProcessMemory(process, (LPVOID)(localplayer + offsets->posX), &pos->x, sizeof(pos->x), 0);
			WriteProcessMemory(process, (LPVOID)(localplayer + offsets->posY), &pos->y, sizeof(pos->y), 0);
		}
		return;
	}
	bool getGhost() {
		DWORD procId;
		bool ghost;
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			ReadProcessMemory(process, (LPVOID)(localplayer + offsets->ghost), &ghost, sizeof(ghost), 0);
		}
		return ghost;
	}
	int getHealth() {
		DWORD procId;
		int health;
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			ReadProcessMemory(process, (LPVOID)(localplayer + offsets->health), &health, sizeof(health), 0);
		}
		return health;
	}
	vec2 getPosition() {
		DWORD procId;
		float posx, posy;
		vec2 pos{ };
		if (GetProcessIdByName("Terraria.exe", procId)) {
			HANDLE process = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
			HANDLE getlocalplayer__THREAD = CreateRemoteThread(process, 0, 0, (LPTHREAD_START_ROUTINE)getLocalPlayer, 0, 0, 0);
			WaitForSingleObject(getlocalplayer__THREAD, INFINITE);
			DWORD localplayer;
			GetExitCodeThread(getlocalplayer__THREAD, &localplayer);
			ReadProcessMemory(process, (LPVOID)(localplayer + offsets->posX), &posx, sizeof(posx), 0);
			ReadProcessMemory(process, (LPVOID)(localplayer + offsets->posY), &posy, sizeof(posy), 0);
			pos = { posx, posy };
		}
		return pos;
	}
};

class Inventory: public LocalPlayer {

};