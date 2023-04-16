#ifndef G_ISCENECREATE_H
#define G_ISCENECREATE_H

#include <string>

class Scene;

__interface ISceneCreate {
public:
	Scene* createScene();
};

#endif // !ISCENECREATE_H
