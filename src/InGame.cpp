#include "InGame.h"

#include <DxLib.h>
#include "Component.h"
#include "Define.h"
#include "Image.h"

InGame::InGame(Component* comp) :
	Scene(comp) {

}

bool InGame::init() {
	_gameMgr = std::make_unique<GameManager>(_comp);
	_itemMgr = std::make_unique<ItemManager>(_comp);
	_player = std::make_unique<Player>(_comp);
	_score = std::make_unique<Score>(_comp);
	_timer = std::make_unique<Timer>();

	_comp->setObj(OBJ_PLAYER, _player.get());
	_comp->setObj(OBJ_ITEMMANAGER, _itemMgr.get());
	_comp->setObj(OBJ_SCORE, _score.get());
	_comp->setObj(OBJ_TIMER, _timer.get());

	_itemMgr->init();
	_player->init();
	_score->init();
	_gameMgr->init();
	_timer->init();

	return true;
}

void InGame::end() {
	_comp->releaseObj(OBJ_PLAYER);
	_comp->releaseObj(OBJ_ITEMMANAGER);
	_comp->releaseObj(OBJ_SCORE);
	_comp->releaseObj(OBJ_TIMER);
}

void InGame::update() {
	_itemMgr->update();
	_player->update();
	_timer->update();
	_gameMgr->update();
}

void InGame::draw() {
	//DrawBox(0, 0, 1040, 650, GetColor(255, 255, 255), TRUE);
	//DrawGraph(0, 0, test, TRUE);
	Image* img = _comp->getObj<Image>(OBJ_IMAGE);
	img->DrawRotaGraph(Vector2(0, 0), Vector2(0, 0), 0, "background.png", 0.5, 0.5);

	_itemMgr->draw();
	_player->draw();
	DrawFormatString(0, 0, GetColor(0, 0, 0), "Hello Game.");
	DrawFormatString(0, 15, GetColor(0, 0, 0), "Score : %d", _score->getScore());
	DrawFormatString(0, 30, GetColor(0, 0, 0), "TimeLeft : %d", _timer->getTimeLeft());
}