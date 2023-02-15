//
// Created by maxng on 2/9/2023.
//

#ifndef GMADDON_BK_LOADER_HPP
#define GMADDON_BK_LOADER_HPP

#include <string_view>
#include <filesystem>
#include <fmt/os.h>
#include <iostream>

namespace gmaddon {
    void generate_bk_loader(std::filesystem::path const& base) {
        auto file = fmt::output_file((base / "bk_loader.lua").string());
        file.print(
R"(--
-- BK Loader - An easy-to-use batch-inclusion utility.
-- Written by Buckell (https://buckell.dev).
--

AddCSLuaFile()

BK = BK or {{}}

function BK.ClientInclude(file)
    if SERVER then
        AddCSLuaFile(file)
    else
        include(file)
    end
end

function BK.SharedInclude(file)
    if SERVER then
        AddCSLuaFile(file)
    end

    include(file)
end

function BK.ServerInclude(file)
    if SERVER then
        include(file)
    end
end

function BK.Include(file)
    local file_name = string.match(file, "[%w_-]+%.lua")
    local realm_specifier = string.sub(file_name, 1, 3)

    if realm_specifier == "sh_" then
        BK.SharedInclude(file)
        return
    elseif realm_specifier == "cl_" then
        BK.ClientInclude(file)
        return
    elseif realm_specifier == "sv_" then
        BK.ServerInclude(file)
    end
end

function BK.IncludeDirectory(dir, type)
    local files = file.Find(dir .. "/*", "LUA")

    if not type then
        for _,f in pairs(files) do
            BK.Include(dir .. "/" .. f)
        end
    elseif type == "SHARED" then
        for _,f in pairs(files) do
            BK.SharedInclude(dir .. "/" .. f)
        end
    elseif type == "CLIENT" then
        for _,f in pairs(files) do
            BK.ClientInclude(dir .. "/" .. f)
        end
    elseif type == "SERVER" then
        for _,f in pairs(files) do
            BK.ServerInclude(dir .. "/" .. f)
        end
    end
end)"
        );
    }
}

#endif //GMADDON_BK_LOADER_HPP
