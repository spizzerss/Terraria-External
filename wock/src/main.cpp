#include <includes.h>
#include <sdk.h>
Game* game = new Game();

void initMenu() {
	LocalPlayer* lplr = reinterpret_cast<LocalPlayer*>(game->g_LocalPlayer);
	printf("\033[H");
	printf("--=STATS=--\nhealth: %d\nghost = %d\n-------------\n[F1] toggle ghost\n[F5] save position\n[F6] load position\n[F9] exit", lplr->getHealth(), lplr->getGhost());
}

vec2 savedPos { };
int main() {
	initMenu();
	while (true) {
		initMenu();
		LocalPlayer* lplr = reinterpret_cast<LocalPlayer*>(game->g_LocalPlayer);
		if (GetAsyncKeyState(VK_F1)) {
		    lplr->setGhost(!lplr->getGhost());
			Sleep(160);
		}
		if (GetAsyncKeyState(VK_F5)) {
			LocalPlayer* lplr = reinterpret_cast<LocalPlayer*>(game->g_LocalPlayer);
			savedPos = lplr->getPosition();
		}

		if (GetAsyncKeyState(VK_F6)) {
			LocalPlayer* lplr = reinterpret_cast<LocalPlayer*>(game->g_LocalPlayer);
			lplr->setPosition(&savedPos);
		}

		if (GetAsyncKeyState(VK_F9)) {
			exit(0);
		}
	}
}