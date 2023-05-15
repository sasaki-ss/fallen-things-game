#ifndef G_ORGANIZATION_H
#define G_ORGANIZATION_H

#include "Scene.h"

class Organization final : public Scene {
private:
public:
	Organization(Component* comp);
	bool init()override;
	void end()override;
	void update()override;
	void draw()override;
};

#endif // !G_ORGANIZATION_H

