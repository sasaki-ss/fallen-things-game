#include "ItemManager.h"

#include "AqItem.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"

#include <DxLib.h>

/*�R���X�g���N�^*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next() {


}

/*�f�X�g���N�^*/
ItemManager::~ItemManager() {

}

/*����������*/
bool ItemManager::init() {
	_items.reserve(MAX_DROP_ITEM);
	for (int i = 0; i < MAX_DROP_ITEM; ++i)_items.emplace_back(nullptr);
	_next = 0;

	_items[_next] = new AqItem(Vector2(200, 0), _comp);
	_items[_next]->init();

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
	//�����ɐ�������

	DrawFormatString(0, 25, GetColor(255, 255, 255), "%d", _comp->rand() % 10);

	//��������
	_items[_next] = new AqItem(Vector2(200, 0), _comp);
	_items[_next]->init();
	
	//�A�C�e��������Ɏ��s����
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

/*�`�揈��*/
void ItemManager::draw() {
	for (auto item : _items) {
		if (item != nullptr)item->draw();
	}
}