#include "Component.h"

Component::Component() {

}

Component::~Component() {
	_objs.clear();
}

/*‰Šú‰»ˆ—*/
bool Component::init() {

	std::random_device rnd;
	_rand.seed(rnd());

	return true;
}