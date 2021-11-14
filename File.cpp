//
// Created by Evan Wieland on 11/13/21.
//

#include "File.h"
#include <filesystem>

std::string File::getCWD()
{
    auto cwd = std::filesystem::current_path();
    return cwd.string();
}
