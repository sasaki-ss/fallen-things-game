#ifndef G_INGAME_H
#define G_INGAME_H

#include <memory>

#include "Scene.h"
#include "Player.h"
#include "ItemManager.h"

class InGame final : public Scene {
private:
	std::unique_ptr<ItemManager>	_itemMgr;
	std::unique_ptr<Player>			_player;
public:
	InGame(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_INGAME_H
