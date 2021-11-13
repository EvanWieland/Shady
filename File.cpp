//
// Created by Evan Wieland on 11/13/21.
//

#include "File.h"

#include <filesystem>

std::string File::getCWD()
{
    std::__fs::filesystem::path cwd = std::__fs::filesystem::current_path();
    return cwd.string();
}
