#include "Archive.h"
#include "filesystem"
#include "iomanip"
namespace fs = std::filesystem;

Archive::Archive(std::unique_ptr<ArchivisationStrategy> ptr) : strategy(std::move(ptr)) {
	std::cout << "Archivisation class created" << std::endl;
}
void Archive::setFilter(Filter f) {
	filter = f;
}
void Archive::start(const fs::path& source,const fs::path& destination) {
	if (!std::filesystem::exists(source)) {
		throw std::runtime_error("Source folder didn't exists");
	};

	for (auto path : fs::recursive_directory_iterator(source)) {
		if (filter(path) == false) {
		std::cout << "OK - " << path << std::endl;
		filesPaths.push_back(path);
		}
		else
		{
			std::cout << "X - " << path << std::endl;
		}

	}
	std::cout << std::endl << "Redy for archiving" << std::endl << std::endl;
	for (auto path : filesPaths) {
		std::cout << path << std::endl;
	}
}