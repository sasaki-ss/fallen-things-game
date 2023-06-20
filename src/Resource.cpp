#include "Resource.h"

#include <DxLib.h>

Resource::Resource() :
	Object() {

}

void Resource::getFileNames(const std::string folderPath,
	std::vector<std::string>& targetFileNames) {
	FILEINFO	fInfo;
	ULONGLONG	fHandle;

	std::string findPath = folderPath + "/*";
	fHandle = FileRead_findFirst(findPath.c_str(), &fInfo);
	if (fHandle != (ULONGLONG)-1) {
		do {
			//ÉtÉ@ÉCÉãÇÃèÍçá
			if (fInfo.DirFlag == FALSE) {
				const char* normalizedName = fInfo.Name;
				std::string fileName = std::string(normalizedName);
				targetFileNames.emplace_back(std::move(fileName));
			}
			
		} while (FileRead_findNext(fHandle, &fInfo) == 0);
	}
	FileRead_findClose(fHandle);
}