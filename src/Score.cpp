#include "Score.h"

Score::Score(Component* comp) :
	Object(comp),
	_score() {

}

bool Score::init() {
	_score = 0;

	return true;
}

void Score::end() {

}