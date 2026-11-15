#include "main.h"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>

using json = nlohmann::json;


int main(int argv, char* argc[]) {

    const std::filesystem::path CURRENT_PATH {std::filesystem::current_path()};

    const bool SCRIPTRUN_FOLDER_EXISTS {std::filesystem::is_directory(ScriptRun::SCRIPT_RUN_FOLDER_PATH)};
    const bool SCRIPTS_FOLDER_EXISTS {std::filesystem::is_directory(ScriptRun::SCRIPTS_FOLDER_PATH)};
    const bool BIND_JSON_FILE_EXISTS {std::filesystem::exists(ScriptRun::BIND_JSON_FILE_PATH) && std::filesystem::is_regular_file(ScriptRun::BIND_JSON_FILE_PATH)};

    const bool FILES_FOLDERS_IN_PLACE {SCRIPTRUN_FOLDER_EXISTS && SCRIPTS_FOLDER_EXISTS && BIND_JSON_FILE_EXISTS};

    const std::string_view MISSING_FOLDER_FILE_HELP_MSG{"Run \'scriptrun --generate\' to create the scriptrun folder (which contains the \'scripts\' folder and \'bind.json\' file) in the current directory."};

    if (!FILES_FOLDERS_IN_PLACE) {
        if (!SCRIPTRUN_FOLDER_EXISTS) {
            std::cout << "The \'scriptrun\' folder cannot be found in the current directory " << CURRENT_PATH << ".\n" 
                << MISSING_FOLDER_FILE_HELP_MSG << '\n';
            return 1; 
        }
        else if (!SCRIPTS_FOLDER_EXISTS) {
            std::cout << "The \'scripts\' folder cannot be found in the \'scriptrun\' folder in the current directory " << CURRENT_PATH << ".\n" 
                << MISSING_FOLDER_FILE_HELP_MSG << '\n';
            return 1; 
        }
        else {
            std::cout << "The \'bind.json\' file cannot be found in the \'scriptrun\' folder in the current directory " << CURRENT_PATH << ".\n" 
                << MISSING_FOLDER_FILE_HELP_MSG << '\n';
            return 1; 
        }
    }


    std::ifstream bind_json(ScriptRun::BIND_JSON_FILE_PATH);

    

    json bind_data = json::parse(bind_json);
    std::cout << bind_data["build"] << '\n';


    /*
    std::cout << argv << '\n';
    // if the command "scriptrun" is run with flag "--generate", it should generate a 
    if (argv > 1) {
        std::string_view script_name { argc[1] };
        std::string script_path { bind_data[script_name] };

        std::system(script_path.c_str());
        std::cout << "runs " << script_name << '\n';

    }
    
    std::cout << "Current Path is: " << std::filesystem::current_path() << '\n';
*/
    return 0;
}

