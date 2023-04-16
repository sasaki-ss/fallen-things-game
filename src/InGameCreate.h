#ifndef G_INGAMECREATE_H
#define G_INGAMECREATE_H

#include "ISceneCreate.h"

class InGameCreate final : public ISceneCreate {
public:
	Scene* createScene();
};

#endif // !G_INGAMECREATE_H
