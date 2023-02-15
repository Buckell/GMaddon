#include <addon_txt.hpp>
#include <loader_file.hpp>
#include <bk_loader.hpp>

constexpr static std::string_view header =
R"(   ________  ___          __    __
  / ____/  |/  /___ _____/ /___/ /___  ____
 / / __/ /|_/ / __ `/ __  / __  / __ \/ __ \
/ /_/ / /  / / /_/ / /_/ / /_/ / /_/ / / / /
\____/_/  /_/\__,_/\__,_/\__,_/\____/_/ /_/

--------------------------------------------

     GMaddon - Addon creation utility.

)";

int main(int argc, char** argv) {
    std::filesystem::path base_directory;

    if (argc < 2) {
        base_directory = std::filesystem::canonical(".");
    } else {
        base_directory = std::filesystem::canonical(argv[1]);
    }

    std::cout << header;

    std::cout << "Destination Folder: " << base_directory.string() << "\n" << std::endl;

    std::string id_name;
    std::cout << "Addon Name (snake_case): ";
    std::getline(std::cin, id_name);

    std::string print_name;
    std::cout << "Addon Print Name: ";
    std::getline(std::cin, print_name);

    std::string version;
    std::cout << "Version: ";
    std::getline(std::cin, version);

    std::string up_date;
    std::cout << "Up Date: ";
    std::getline(std::cin, up_date);

    std::string author_name;
    std::cout << "Author: ";
    std::getline(std::cin, author_name);

    std::string author_email;
    std::cout << "Author's Email: ";
    std::getline(std::cin, author_email);

    std::string author_url;
    std::cout << "Author's URL: ";
    std::getline(std::cin, author_url);

    std::string info;
    std::cout << "Description: ";
    std::getline(std::cin, info);

    gmaddon::addon_txt_fields addon_txt_fields {
        .name = print_name,
        .version = version,
        .up_date = up_date,
        .author_name = author_name,
        .author_email = author_email,
        .author_url = author_url,
        .info = info,
    };

    std::filesystem::path addon_directory = base_directory / id_name;

    std::filesystem::create_directory(base_directory / id_name);
    std::filesystem::create_directory(addon_directory / "lua");
    std::filesystem::create_directory(addon_directory / "lua" / "autorun");
    std::filesystem::create_directory(addon_directory / "lua" / id_name);

    gmaddon::generate_addon_txt(addon_directory, addon_txt_fields);
    gmaddon::generate_loader_file(addon_directory / "lua" / "autorun", id_name);
    gmaddon::generate_bk_loader(addon_directory / "lua" / "autorun");

    std::cout << "\n\nAddon templated generated successfully." << std::endl;

    return 0;
}
