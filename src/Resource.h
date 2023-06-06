#ifndef G_RESOURCE_H
#define G_RESOURCE_H

#include <string>
#include "Object.h"

enum class ResourceType {
	Temp,
	Permanence
};

class Resource : public Object {
protected:
	std::string _targetFilePath;
	std::string _targetFileName;
public:
	Resource();
	bool init()override { return true; }
	void end()override = 0;
	virtual bool load(ResourceType type) = 0;

	void setFilePath(const std::string& targetFilePath);
	void getFilePaths(std::vector<std::string>& targetFilePaths);
};

#endif // !G_RESOURCE_H
