#ifndef G_GACHA_H
#define G_GACHA_H

#include "Scene.h"

class Gacha final : public Scene {
private:

public:
	Gacha(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_GACHA_H
