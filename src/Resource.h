#ifndef G_RESOURCE_H
#define G_RESOURCE_H

#include <string>
#include "Object.h"

class Resource : public Object {
protected:
public:
	Resource();
	bool init()override { return true; }
	void end()override = 0;
	virtual bool load(std::string folderPath) = 0;

	void getFileNames(const std::string folderPath,
		std::vector<std::string>& targetFileNames);
};

#endif // !G_RESOURCE_H
