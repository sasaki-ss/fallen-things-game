#include "Title.h"

#include <DxLib.h>
#include "Component.h"
#include "SceneManager.h"

Title::Title(Component* comp) :
	Scene(comp),
	_kb(nullptr) {

}

bool Title::init() {
	_kb = _comp->getKeyboard();
	return true;
}

void Title::end() {

}

void Title::update() {
	if (_kb->getInputKey(KEY_INPUT_SPACE) == 1) {
		_comp->getSceneMgr()->changeScene("InGame");
	}
}

void Title::draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Title‰æ–Ê‚ð•`‰æ’†");
}