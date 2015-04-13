#ifndef __LEVEL_H_DEFINED__
#define __LEVEL_H_DEFINED__

#include <vector>
#include "Window.h"
#include "Camera.h"
#include "PugiXML.h"
#include "Sprite.h"
#include "EntityCollection.h"
#include "MovingEntity.h"

#define SIL_LAYER	0	// Silhouette layer
#define BG_LAYER	1	// Background layer
#define GAME_LAYER	2	// Game layer
#define FG_LAYER	3	// Foreground layer

#define LAYER_COUNT 4

#define SPAWN_LEFT	0
#define SPAWN_RIGHT 1

struct Exit {
	std::string level;
	int spawnpoint;
};

class Level
{
	public:
		Level(Window *window, Camera *camera, EntityCollection<Entity> *collection);
		~Level();

		void load(std::string level_name);
		void update(Entity *entity);
		void render(int layer);
		SDL_Rect collides(Entity *entity, bool inair);

		int getTile(int x, int y);
		SDL_Rect pointToTile(int x, int y);
		int getLevelWidth();
		Exit *getCurrentDoor();

		SDL_Point getRightSpawn();
		SDL_Point getLeftSpawn();
		SDL_Point getStartSpawn();

		std::string getRightmostLevel();
		std::string getLeftmostLevel();

		std::string signText, tooltip;
		//bool collides(Entity *entity);

	private:
		Window *window;
		Camera *camera;
		EntityCollection<Entity> *collection;

		pugi::xml_document levelDocument;
		pugi::xml_parse_result result;
		pugi::xml_node SilhouetteLayer, BackgroundLayer, GameLayer, ForegroundLayer;
		pugi::xml_node triggerNode, actorNode;

		int levelWidth, levelHeight;
		int tileSize;
		Exit *currentDoor, *leftExit, *rightExit;

		Sprite *levelTileSheet;
		std::vector<std::vector<int>> SilhouetteData, BackgroundData, GameData, ForegroundData;

		SDL_Point leftSpawn, rightSpawn, startSpawn;
};

#endif //__LEVEL_H_DEFINED__