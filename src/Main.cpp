#include <memory>
#include "System.h"
#include "GachaCreate.h"
#include "HomeCreate.h"
#include "InGameCreate.h"
#include "OptionCreate.h"
#include "TitleCreate.h"


int main(void) {
	System sys;
	sys.setWindowPos(Vector2(1280.0f, 720.0f));
	sys.setWindowTitle("made by kuroneko.");
	if (sys.init()) {
		sys.setSceneSystem("Title", std::make_unique<TitleCreate>());
		sys.setSceneCreate("InGame", std::make_unique<InGameCreate>());
		sys.setSceneCreate("Home", std::make_unique<HomeCreate>());
		sys.setSceneCreate("Gacha", std::make_unique<GachaCreate>());
		sys.setSceneCreate("Option", std::make_unique<OptionCreate>());

		sys.run();
	}
	sys.end();
	return 0;
}
