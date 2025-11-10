// MyArchivist.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <filesystem>
#include "Archive.h"
#include <memory>
#include <string>
int main()
{
    std::cout << "MyArchive\n";
    std::unique_ptr<ArchivisationStrategy> a = std::make_unique<PackingStrategy>();
    try {

    Archive archive(std::move(a));
    auto lambda = [](const std::filesystem::path&p) -> bool {
        if (p.extension() == ".txt") {
            return 0;
        }
        return 1;
        // if returns 1 - not included
        };
    archive.setFilter(lambda);
    archive.start("c:/Users/pawel/documents/studia","./");
    }
    catch(std::string err){
        std::cout << err << std::endl;
    };
}
