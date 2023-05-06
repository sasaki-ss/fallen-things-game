#ifndef G_INGAME_H
#define G_INGAME_H

#include <memory>

#include "ItemManager.h"
#include "Player.h"
#include "Scene.h"
#include "Score.h"

class InGame final : public Scene {
private:
	std::unique_ptr<ItemManager>	_itemMgr;
	std::unique_ptr<Player>			_player;
	std::unique_ptr<Score>			_score;
public:
	InGame(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_INGAME_H
