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
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		_items.emplace_back(nullptr);
	}

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
		_items[i].reset();
	}
	_items.clear();
}

/*�X�V����*/
void ItemManager::update() {
	//��A�N�e�B�u�ɂȂ����I�u�W�F�N�g���������
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

/*�`�揈��*/
void ItemManager::draw() {
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->draw();
	}
}

/*��������*/
void ItemManager::GenItem() {
	float x = (_comp->getRand() % 8 + 1) * 100.0f;

	if (!_isEmp)return;

	//�A�C�e���𐶐�
	_items[_next] = std::make_unique<AqItem>(Vector2(x, -50.0f), _comp);
	_items[_next]->init();
	_isGen = true;

	//�󂢂Ă��郁��������������
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr) {
			_next = i;
			return;
		}
	}

	_isEmp = false;
}