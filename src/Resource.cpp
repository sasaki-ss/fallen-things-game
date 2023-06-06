#include "Resource.h"

#include <fstream>
#include "ErrorProc.h"

Resource::Resource() :
	Object(),
	_targetFilePath("") {

}

void Resource::setFilePath(const std::string& targetFilePath) {
	_targetFilePath = targetFilePath;

	std::string relativePath = _targetFilePath.substr(6).c_str();
	_targetFileName = relativePath.substr(0, relativePath.find(".bin")) + "/";
}

void Resource::getFilePaths(std::vector<std::string>& targetFilePaths) {
	std::ifstream ifs(_targetFilePath, std::ios_base::in, std::ios_base::binary);
	if (!ifs) {
		ErrorProc::ErrorExit("File open error: " + _targetFilePath);
	}

	int64_t fileNum = 0;
	ifs.read(reinterpret_cast<char*>(&fileNum), sizeof(fileNum));
	if (!ifs) {
		ErrorProc::ErrorExit("File read error: " + _targetFilePath);
	}

	for (int i = 0; i < fileNum; ++i) {
		int64_t size;
		ifs.read(reinterpret_cast<char*>(&size), sizeof(size));
		std::string path(size, ' ');
		ifs.read(path.data(), size);
		if (!ifs) {
			ErrorProc::ErrorExit("File read error: " + _targetFilePath);
		}

		targetFilePaths.emplace_back(std::move(path));
	}

	ifs.close();
	if(!ifs) {
		ErrorProc::ErrorExit("File close error: " + _targetFilePath);
	}
}