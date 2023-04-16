#include "System.h"
#include "InGameCreate.h"

int main(void) {
	System sys;
	sys.setWindowPos(Vector2(1280, 720));
	sys.setWindowTitle("made by kuroneko.");
	sys.setSceneSystem("InGame", new InGameCreate());
	//sys.setSceneCreate("InGame", new InGameCreate());
	if (sys.init())sys.run();
	sys.end();
	return 0;
}
