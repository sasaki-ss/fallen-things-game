#include "InGame.h"

#include <DxLib.h>
#include "Component.h"
#include "Define.h"
#include "ItemManager.h"
#include "Player.h"

InGame::InGame(Component* comp) :
	Scene(comp) {

}

bool InGame::init() {
	_itemMgr = std::make_unique<ItemManager>(_comp);
	_player = std::make_unique<Player>(_comp);
	_score = std::make_unique<Score>(_comp);

	_comp->setObj(OBJ_PLAYER, _player.get());
	_comp->setObj(OBJ_ITEMMGR, _itemMgr.get());
	_comp->setObj(OBJ_SCORE, _score.get());

	_itemMgr->init();
	_player->init();
	_score->init();

	return true;
}

void InGame::end() {
	_comp->releaseObj();
}

void InGame::update() {
	_itemMgr->update();
	_player->update();
}

void InGame::draw() {
	_itemMgr->draw();
	_player->draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hello Game.");
	DrawFormatString(0, 15, GetColor(255, 255, 255), "Score : %d", _score->getScore());
}