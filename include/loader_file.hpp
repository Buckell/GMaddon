//
// Created by maxng on 2/9/2023.
//

#ifndef GMADDON_LOADER_FILE_HPP
#define GMADDON_LOADER_FILE_HPP

#include <string_view>
#include <filesystem>
#include <fmt/os.h>
#include <iostream>

namespace gmaddon {
    void generate_loader_file(std::filesystem::path const& base, std::string_view const name) {
        auto file = fmt::output_file((base / fmt::format("{}.lua", name)).string());
        file.print(
R"(--
-- Loader generated by GMaddon.
-- Written by Buckell (https://buckell.dev).
--

include("bk_loader.lua")
BK.IncludeDirectory("{}")
)", name);
    }
}

#endif //GMADDON_LOADER_FILE_HPP
