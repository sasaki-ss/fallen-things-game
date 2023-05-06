#include "System.h"
#include "InGameCreate.h"

int main(void) {
	System sys;
	sys.setWindowPos(Vector2(1280.0f, 720.0f));
	sys.setWindowTitle("made by kuroneko.");
	if (sys.init()) {
		sys.setSceneSystem("InGame", new InGameCreate());
		sys.run();
	}
	sys.end();
	return 0;
}
