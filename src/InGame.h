#ifndef G_INGAME_H
#define G_INGAME_H

#include "Scene.h"

class InGame : public Scene {
private:
	
public:
	bool init();
	void end();
	void update();
	void draw();
};

#endif // !G_INGAME_H
