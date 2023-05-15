#ifndef G_ORGCREATE_H
#define G_ORGCREATE_H

#include "ISceneCreate.h"
#include "Organization.h"

class OrgCreate final : public ISceneCreate {
public:
	Scene* createScene(Component* comp) { return new Organization(comp); }
};

#endif // !G_ORGCREATE_H
