#ifndef G_HOME_H
#define G_HOME_H

#include "Scene.h"

class Home final : public Scene {
private:
public:
	Home(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_HOME_H
