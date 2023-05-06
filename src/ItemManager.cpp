#include "ItemManager.h"

#include "AqItem.h"
#include "Collision.h"
#include "Component.h"
#include "Define.h"
#include "Item.h"
#include "Player.h"
#include "Score.h"


/*�R���X�g���N�^*/
ItemManager::ItemManager(Component* comp) :
	Object(comp),
	_next(),
	_cnt(),
	_isEmp(true),
	_isGen(true),
	_player(nullptr),
	_score(nullptr) {

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

	_player = _comp->getObj<Player>(OBJ_PLAYER);
	_score = _comp->getObj<Score>(OBJ_SCORE);

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

	//�I�u�W�F�N�g�̐�������
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
	//�e�I�u�W�F�N�g�̍X�V
	for (int i = 0; i < MAX_DROP_ITEM; ++i) {
		if (_items[i] == nullptr)continue;

		_items[i]->update();
		if (Collision::isHitBoxToBox(_items[i]->getLeftTopPos(), _items[i]->getWidth(),
			_items[i]->getHeight(), pPos, pWidth, pHeight)) {
			_score->add(static_cast<AqItem*>(_items[i].get())->Acquisition());
		}
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
	_items[_next] = std::make_unique<AqItem>(Vector2(x, -50.0f), 100, _comp);
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