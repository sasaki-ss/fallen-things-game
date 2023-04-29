#include "ItemManager.h"

#include "AqItem.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"

#include <DxLib.h>

/*�R���X�g���N�^*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next(),
	_cnt(),
	_isEmp(true),
	_isGen(true) {

}

/*�f�X�g���N�^*/
ItemManager::~ItemManager() {

}

/*����������*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i)_items.emplace_back(nullptr);
	_next = 0;
	_cnt = 0;
	_isEmp = true;
	_isGen = false;

	return false;
}

/*�I������*/
void ItemManager::end() {
	//�I�u�W�F�N�g���������
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->end();
		delete _items[i];
	}
	_items.clear();
}

/*�X�V����*/
void ItemManager::update() {
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		if (!_items[i]->getIsActive())
			delete _items[i];
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

	for (auto item : _items) {
		if (item != nullptr)item->update();
	}
}

/*�`�揈��*/
void ItemManager::draw() {
	for (auto item : _items) {
		if (item != nullptr)item->draw();
	}
}

/*��������*/
void ItemManager::GenItem() {
	//int genRate = _comp->rand() % 100 + 1;
	float x = (_comp->rand() % 8 + 1) * 100.0f;

	if (_isEmp) {
		_items[_next] = new AqItem(Vector2(x, -50.0f), _comp);
		_items[_next]->init();
		_isGen = true;
	}

	//if (genRate <= GEN_ITEM_RATE && _isEmp) {

	//}

	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr) {
			_next = i;
			return;
		}
	}

	_isEmp = false;
}