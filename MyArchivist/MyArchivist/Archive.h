#pragma once
#include <memory>
#include "Strategy.h"
#include <functional>
#include <iostream>
#include <filesystem>
#include <vector>
#define ARCHIVE_H
#ifndef ARHIVE_H

class Archive {
	using Filter = std::function<bool(const std::filesystem::path&)>;
private:
	std::unique_ptr<ArchivisationStrategy> strategy;
	 Filter filter;
	 std::vector<std::filesystem::path> filesPaths;

public:
	Archive(std::unique_ptr<ArchivisationStrategy> ptr);
	void setFilter(Filter f);
	void start(const std::filesystem::path& source,const std::filesystem::path& destination);
};




#endif // !1
