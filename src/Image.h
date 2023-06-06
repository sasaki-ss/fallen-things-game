#ifndef G_IMAGE_H
#define G_IMAGE_H

#include <unordered_map>
#include "Resource.h"
#include "Vector2.h"

struct ImageData {
	int				handle;
	ResourceType	type;
};

class Image final : public Resource {
private:
	std::unordered_map<std::string, ImageData> _images;
public:
	Image();
	void end()override;
	bool load(ResourceType type = ResourceType::Permanence)override;

	void DrawRotaGraph(Vector2 pos, Vector2 cPos, double angle, std::string fileName,
		double extRateX = 1.0, double extRateY = 1.0, int trastFlag = 1, int turnFlagX = 0,
		int turnFlagY = 0);
};

#endif // !G_IMAGE_H
