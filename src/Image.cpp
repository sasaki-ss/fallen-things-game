#include "Image.h"

#include <DxLib.h>
#include "ErrorProc.h"

Image::Image() :
	Resource() {

}

void Image::end() {
	InitGraph();
	_images.clear();
}

bool Image::load(std::string folderPath) {
	std::vector<std::string> fileNames;

	getFileNames(folderPath, fileNames);
	for (const auto& fileName : fileNames) {
		std::string path = folderPath + "/" + fileName;
		int imgHandle = LoadGraph(path.c_str());
		if (imgHandle == -1) {
			return false;
		}

		_images.emplace(fileName, std::move(imgHandle));
	}

	fileNames.clear();
	return true;
}

void Image::DrawRotaGraph(Vector2 pos, Vector2 cPos, std::string fileName, double angle,
	double extRateX, double extRateY, int trastFlag, int turnFlagX, int turnFlagY) {
	DrawRotaGraph3F(pos.x, pos.y, cPos.x, cPos.y, extRateX, extRateY, angle,
		_images[fileName], trastFlag, turnFlagX, turnFlagY);
}

void Image::DrawRectRotaGraph(Vector2 pos,Vector2 src,int width,int height,
	Vector2 cPos,std::string fileName,double angle,double extRateX,double extRateY,
	int trastFlag, int turnFlagX, int turnFlagY) {
	DrawRectRotaGraph3F(pos.x, pos.y, (int)src.x, (int)src.y, width, height, cPos.x, cPos.y,
		extRateX, extRateY, angle, _images[fileName], trastFlag, turnFlagX, turnFlagY);
}
