#ifndef G_INGAME_H
#define G_INGAME_H

#include "Scene.h"

class ItemManager;

class InGame final : public Scene {
private:
	ItemManager* _itemMgr;
public:
	InGame(Component* comp);
	bool init();
	void end();
	void update();
	void draw();
};

#endif // !G_INGAME_H
