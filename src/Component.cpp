#include "Component.h"

Component::Component() {

}

Component::~Component() {
	_objs.clear();
}

/*初期化処理*/
bool Component::init() {

	std::random_device rnd;
	_rand.seed(rnd());

	return true;
}