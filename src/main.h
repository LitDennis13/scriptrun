#ifndef MAIN_H
#define MAIN_H

#include <filesystem>


namespace ScriptRun {
    const std::filesystem::path SCRIPT_RUN_FOLDER_PATH {"./scriptrun"};
    const std::filesystem::path SCRIPTS_FOLDER_PATH {"./scriptrun/scripts"};
    const std::filesystem::path BIND_JSON_FILE_PATH {"./scriptrun/bind.json"};
}

#endif // MAIN_H