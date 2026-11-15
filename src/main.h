#include "libraries/json.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>


using json = nlohmann::json;



namespace ScriptRun {
    const std::filesystem::path SCRIPT_RUN_FOLDER_PATH {"./scriptrun"};
    const std::filesystem::path SCRIPTS_FOLDER_PATH {"./scriptrun/scripts"};
    const std::filesystem::path BIND_JSON_FILE_PATH {"./scriptrun/bind.json"};
}