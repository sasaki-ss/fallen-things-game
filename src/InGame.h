#ifndef G_INGAME_H
#define G_INGAME_H

#include <memory>
#include "GameManager.h"
#include "ItemManager.h"
#include "Player.h"
#include "Scene.h"
#include "Score.h"
#include "Timer.h"

class InGame final : public Scene {
private:
	std::unique_ptr<GameManager>	_gameMgr;
	std::unique_ptr<ItemManager>	_itemMgr;
	std::unique_ptr<Player>			_player;
	std::unique_ptr<Score>			_score;
	std::unique_ptr<Timer>			_timer;
public:
	InGame(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_INGAME_H
