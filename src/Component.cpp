#include "Component.h"

Component::Component() {

}

Component::~Component() {
	_objs.clear();
}

/*初期化処理*/
bool Component::init() {
	_keyboard = std::make_unique<Keyboard>(this);
	_sceneMgr = std::make_unique<SceneManager>(this);

	std::random_device rnd;
	_rand.seed(rnd());

	_keyboard->init();

	return true;
}