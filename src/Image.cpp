#include "Image.h"

#include <DxLib.h>
#include "ErrorProc.h"

Image::Image() :
	Resource() {

}

void Image::end() {
	for (const auto& image : _images) {
		DeleteGraph(image.second.handle);
	}
	_images.clear();
}

bool Image::load(ResourceType type) {
	std::vector<std::string> filePaths;

	getFilePaths(filePaths);

	for (const auto& filePath : filePaths) {
		int imageHandle = LoadGraph(filePath.c_str());
		if (imageHandle == -1) {
			return false;
		}

		std::string fileName = filePath.substr(filePath.find(_targetFileName) +
			_targetFileName.length()).c_str();
		ImageData imageData;
		imageData.handle = imageHandle;
		imageData.type = type;
		_images.emplace(std::move(fileName), std::move(imageData));
	}

	filePaths.clear();

	return true;
}

void Image::DrawRotaGraph(Vector2 pos, Vector2 cPos, double angle, std::string fileName,
	double extRateX, double extRateY, int trastFlag, int turnFlagX, int turnFlagY) {
	DrawRotaGraph3F(pos.x, pos.y, cPos.x, cPos.y, extRateX, extRateY, angle,
		_images[fileName].handle, trastFlag, turnFlagX, turnFlagY);
}
