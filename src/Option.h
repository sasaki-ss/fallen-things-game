#ifndef G_OPTION_H
#define G_OPTION_H

#include "Scene.h"

class Option final : public Scene {
private:

public:
	Option(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_OPTION_H
