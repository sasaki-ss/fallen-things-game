#include "InGame.h"

#include <DxLib.h>


bool InGame::init() {
	return true;
}

void InGame::end() {

}

void InGame::update() {
	
}

void InGame::draw() {
	DrawFormatString(0, 0, GetColor(255, 255, 255), "Hello Game.");
}