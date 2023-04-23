#include "ItemManager.h"

#include "AqItem.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"

#include <DxLib.h>

/*コンストラクタ*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next() {


}

/*デストラクタ*/
ItemManager::~ItemManager() {

}

/*初期化処理*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i)_items.emplace_back(nullptr);
	_next = 0;

	_items[_next] = new AqItem(Vector2(200, 0), _comp);
	_items[_next]->init();

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
	//ここに生成処理

	DrawFormatString(0, 25, GetColor(255, 255, 255), "%d", _comp->rand() % 10);

	//生成処理
	_items[_next] = new AqItem(Vector2(200, 0), _comp);
	_items[_next]->init();
	
	//アイテム生成後に実行する
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr) {
			_next = i;
			break;
		}
	}

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