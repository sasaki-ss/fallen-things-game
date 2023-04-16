#include "System.h"

int main(void) {
	System sys;
	sys.setWindowPos(Vector2(1280, 720));
	sys.setWindowTitle("テストウィンドウ");
	if (sys.init())sys.run();
	sys.end();
	return 0;
}
