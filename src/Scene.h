#ifndef G_SCENE_H
#define G_SCENE_H

#include "Object.h"

class Scene : public Object {
public:
	Scene(Component* comp) :
		Object(comp) {

	}

	virtual bool init()override = 0;
	virtual void end()override = 0;
	virtual void update()override = 0;
	virtual void draw()override = 0;
};

#endif // !G_SCENE_H
