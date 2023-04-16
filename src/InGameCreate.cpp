#include "InGameCreate.h"
#include "InGame.h"

Scene* InGameCreate::createScene() {
	return new InGame();
}