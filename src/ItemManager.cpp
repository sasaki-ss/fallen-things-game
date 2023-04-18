#include "ItemManager.h"

#include "Define.h"
#include "Item.h"

/*�R���X�g���N�^*/
ItemManager::ItemManager() {

}

/*�f�X�g���N�^*/
ItemManager::~ItemManager() {

}

/*����������*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i)_items.emplace_back(nullptr);

	return false;
}

/*�I������*/
void ItemManager::end() {
	//�I�u�W�F�N�g���������
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] != nullptr) {
			_items[i]->end();
			delete _items[i];
		}
	}
	_items.clear();
}

/*�X�V����*/
void ItemManager::update() {
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