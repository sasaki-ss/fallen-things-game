#ifndef G_TITLE_H
#define G_TITLE_H

#include "Scene.h"

class Keyboard;

class Title final : public Scene {
private:
	Keyboard* _kb;
public:
	Title(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_TITLE_H
