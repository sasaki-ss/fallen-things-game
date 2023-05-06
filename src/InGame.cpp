#include "InGame.h"

#include <DxLib.h>
#include "ItemManager.h"
#include "Player.h"

InGame::InGame(Component* comp) :
	Scene(comp) {

}

bool InGame::init() {
	_itemMgr = std::make_unique<ItemManager>(_comp);
	_player = std::make_unique<Player>(_comp);
	_itemMgr->init();
	_player->init();

	return true;
}

void InGame::end() {

}

void InGame::update() {
	_itemMgr->update();
	_player->update();
}

void InGame::draw() {
	_itemMgr->draw();
	_player->draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hello Game.");
}