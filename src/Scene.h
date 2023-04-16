#ifndef G_SCENE_H
#define G_SCENE_H

class Scene {
private:

public:
	virtual bool init() = 0;
	virtual void end() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};

#endif // !G_SCENE_H
