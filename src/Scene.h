#ifndef G_SCENE_H
#define G_SCENE_H

class Component;

class Scene {
protected:
	Component* _comp;
public:
	Scene(Component* comp) :
		_comp(comp) {

	}

	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // !G_SCENE_H
