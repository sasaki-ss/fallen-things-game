#ifndef G_OPTIONCREATE_H
#define G_OPTIONCREATE_H

#include "ISceneCreate.h"
#include "Option.h"

class OptionCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Option(comp); }
};

#endif // !G_OPTIONCREATE_H
