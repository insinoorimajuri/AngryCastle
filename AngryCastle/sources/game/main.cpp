#include "..//engine//Input.h"
#include "..//engine//StateManager.h"
#include "..//game//GameState.h"
#include "..//engine//Window.h"

#define SCREEN_TITLE "Escape From Earth"
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define SCREEN_LOGICAL_WIDTH 400
#define SCREEN_LOGICAL_HEIGHT 240

int main(int argc, char* args[]) {
	SDL::init();

	Window window(SCREEN_WIDTH, 
				SCREEN_HEIGHT, 
				SCREEN_LOGICAL_WIDTH,
				SCREEN_LOGICAL_HEIGHT,
				SCREEN_TITLE, 
				false);


	StateManager manager(&window);

	manager.run();

	SDL::exit();
	return 0;
}