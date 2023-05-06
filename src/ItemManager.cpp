#include "ItemManager.h"

#include "AqItem.h"
#include "Collision.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"
#include "Player.h"
#include "Score.h"


/*コンストラクタ*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next(),
	_cnt(),
	_isEmp(true),
	_isGen(true),
	_player(nullptr),
	_score(nullptr) {

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

	_player = _comp->getObj<Player>(OBJ_PLAYER);
	_score = _comp->getObj<Score>(OBJ_SCORE);

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

	//オブジェクトの生成処理
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

	Vector2 pPos = _player->getLeftTopPos();
	float pWidth = _player->getWidth();
	float pHeight = _player->getHeight();
	//各オブジェクトの更新
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->update();
		if (Collision::isHitBoxToBox(_items[i]->getLeftTopPos(), _items[i]->getWidth(),
			_items[i]->getHeight(), pPos, pWidth, pHeight)) {
			_score->add(static_cast<AqItem*>(_items[i].get())->Acquisition());
		}
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
	_items[_next] = std::make_unique<AqItem>(Vector2(x, -50.0f), 100, _comp);
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