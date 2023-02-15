//
// Created by maxng on 2/9/2023.
//

#include <string_view>
#include <filesystem>
#include <fmt/os.h>
#include <iostream>

#ifndef GMADDON_ADDON_TXT_HPP
#define GMADDON_ADDON_TXT_HPP

constexpr static char const* addon_txt_format =
R"("AddonInfo"
{
    "name"         "{0}"
    "version"      "{1}"
    "up_date"      "{2}"
    "author_name"  "{3}"
    "author_email" "{4}"
    "author_url"   "{5}"
    "info"         "{6}"
    "override"     "0"
})";

namespace gmaddon {
    struct addon_txt_fields {
        std::string_view name;
        std::string_view version;
        std::string_view up_date;
        std::string_view author_name;
        std::string_view author_email;
        std::string_view author_url;
        std::string_view info;
    };

    void generate_addon_txt(std::filesystem::path const& base, addon_txt_fields const& fields) {
        auto file = fmt::output_file((base / "addon.txt").string());

        file.print(R"("AddonInfo"
{{
    "name"         "{}"
    "version"      "{}"
    "up_date"      "{}"
    "author_name"  "{}"
    "author_email" "{}"
    "author_url"   "{}"
    "info"         "{}"
    "override"     "0"
}})",
            fields.name,
            fields.version,
            fields.up_date,
            fields.author_name,
            fields.author_email,
            fields.author_url,
            fields.info
        );
    }
}

#endif //GMADDON_ADDON_TXT_HPP
