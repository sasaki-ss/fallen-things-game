#ifndef G_IMAGE_H
#define G_IMAGE_H

#include <unordered_map>
#include "Resource.h"
#include "Vector2.h"

class Image final : public Resource {
private:
	std::unordered_map<std::string, int> _images;
public:
	Image();
	void end()override;
	bool load(std::string folderPath)override;

	void DrawRotaGraph(Vector2 pos, Vector2 cPos, std::string fileName, double angle = 0.0,
		double extRateX = 1.0, double extRateY = 1.0, int trastFlag = 1, int turnFlagX = 0,
		int turnFlagY = 0);

	void DrawRectRotaGraph(Vector2 pos, Vector2 src, int width, int height,
		Vector2 cPos, std::string fileName, double angle = 0.0, double extRateX = 1.0,
		double extRateY = 1.0,int trastFlag = 1, int turnFlagX = 0, int turnFlagY = 0);
};

#endif // !G_IMAGE_H
