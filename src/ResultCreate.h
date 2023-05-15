#ifndef G_RESULTCREATE_H
#define G_RESULTCREATE_H

#include "ISceneCreate.h"
#include "Result.h"

class ResultCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Result(comp); }
};

#endif // !G_RESULTCREATE_H
