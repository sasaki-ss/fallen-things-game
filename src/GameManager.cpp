#include "GameManager.h"

#include "Component.h"
#include "Define.h"
#include "Timer.h"

GameManager::GameManager(Component* comp) :
	Object(comp),
	_timer(nullptr) {

}

bool GameManager::init() {
	_timer = _comp->getObj<Timer>(OBJ_TIMER);
	return true;
}

void GameManager::end() {

}

void GameManager::update() {
	if (_timer->getTimeLeft() == 0) {
		//ゲームオーバーの状態を追加
		printf("%s\n", "GameOver");
	}
}