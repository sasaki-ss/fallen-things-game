#include "InGame.h"

#include <DxLib.h>
#include "ItemManager.h"

InGame::InGame(Component* comp) :
	Scene(comp),
	_itemMgr(nullptr) {

}

bool InGame::init() {
	_itemMgr = new ItemManager(_comp);
	_itemMgr->init();

	return true;
}

void InGame::end() {
	delete _itemMgr;
}

void InGame::update() {
	_itemMgr->update();
}

void InGame::draw() {
	_itemMgr->draw();
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hello Game.");
}