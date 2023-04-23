#ifndef G_ISCENECREATE_H
#define G_ISCENECREATE_H

#include <string>

class Scene;
struct Component;

__interface ISceneCreate {
public:
	Scene* createScene(Component* comp);
};

#endif // !ISCENECREATE_H
