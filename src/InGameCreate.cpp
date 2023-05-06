#include "InGameCreate.h"
#include "InGame.h"

Scene* InGameCreate::createScene(Component* comp) {
	return new InGame(comp);
}