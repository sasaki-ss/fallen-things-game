#include "Keyboard.h"

#include <DxLib.h>
#include "Define.h"

Keyboard::Keyboard(Component* comp) :
	Object(comp) {

}

Keyboard::~Keyboard() {

}

bool Keyboard::init() {
	for (int i = 0; i < KEY_NUM; ++i) {
		_keyPressCnt.emplace_back(0);
		_keyReleaseCnt.emplace_back(0);
	}

	return false;
}

void Keyboard::end() {
	_keyPressCnt.clear();
	_keyReleaseCnt.clear();
}

void Keyboard::update() {
	char buf[KEY_NUM];
	GetHitKeyStateAll(buf);

	for (int i = 0; i < KEY_NUM; i++) {
		//buf[i]‚ª‰Ÿ‚³‚ê‚Ä‚¢‚éê‡
		if (buf[i] != 0) {
			++_keyPressCnt[i];
			_keyReleaseCnt[i] = 0;
		}
		//‰Ÿ‚³‚ê‚Ä‚È‚¢ê‡
		else {
			++_keyReleaseCnt[i];
			_keyPressCnt[i] = 0;
		}
	}
}

int Keyboard::getInputKey(int keycode, KeyInputType inputType) {
	if (!(keycode >= 0 && keycode < KEY_NUM))return -1;

	switch (inputType){
	case KeyInputType::Press:
		return _keyPressCnt[keycode];
	case KeyInputType::Release:
		return _keyReleaseCnt[keycode];
	}

	return -1;
}