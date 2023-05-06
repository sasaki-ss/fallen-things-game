#include "ItemManager.h"

#include "AqItem.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"

#include <DxLib.h>

/*コンストラクタ*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next(),
	_cnt(),
	_isEmp(true),
	_isGen(true) {

}

/*デストラクタ*/
ItemManager::~ItemManager() {

}

/*初期化処理*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		_items.emplace_back(nullptr);
	}

	_next = 0;
	_cnt = 0;
	_isEmp = true;
	_isGen = false;

	return false;
}

/*終了処理*/
void ItemManager::end() {
	//オブジェクトを解放する
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->end();
		_items[i].reset();
	}
	_items.clear();
}

/*更新処理*/
void ItemManager::update() {
	//非アクティブになったオブジェクトを解放する
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		if (!_items[i]->getIsActive()) {
			_items[i] = nullptr;
			_isEmp = true;
		}
	}

	if (!_isGen) {
		GenItem();
	}
	else {
		if (_cnt == 90) {
			_isGen = false;
			_cnt = 0;
		}
		else {
			++_cnt;
		}
	}

	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->update();
	}
}

/*描画処理*/
void ItemManager::draw() {
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->draw();
	}
}

/*生成処理*/
void ItemManager::GenItem() {
	float x = (_comp->getRand() % 8 + 1) * 100.0f;

	if (!_isEmp)return;

	//アイテムを生成
	_items[_next] = std::make_unique<AqItem>(Vector2(x, -50.0f), _comp);
	_items[_next]->init();
	_isGen = true;

	//空いているメモリを検索する
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr) {
			_next = i;
			return;
		}
	}

	_isEmp = false;
}