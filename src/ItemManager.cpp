#include "ItemManager.h"

#include "Define.h"
#include "Item.h"

/*コンストラクタ*/
ItemManager::ItemManager() {

}

/*デストラクタ*/
ItemManager::~ItemManager() {

}

/*初期化処理*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i)_items.emplace_back(nullptr);

	return false;
}

/*終了処理*/
void ItemManager::end() {
	//オブジェクトを解放する
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] != nullptr) {
			_items[i]->end();
			delete _items[i];
		}
	}
	_items.clear();
}

/*更新処理*/
void ItemManager::update() {
	for (auto item : _items) {
		if (item != nullptr)item->update();
	}
}

/*描画処理*/
void ItemManager::draw() {
	for (auto item : _items) {
		if (item != nullptr)item->draw();
	}
}