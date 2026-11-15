#include "libraries/json.hpp"

#include <iostream>
#include <fstream>
#include <filesystem>
#include <cstdlib>


using json = nlohmann::json;

int main(int argv, char* argc[]) {

    std::ifstream bind_json("./scriptrun/bind.json");
    
    json bind_data = json::parse(bind_json);

    std::cout << bind_data["build"] << '\n';

    std::cout << argv << '\n';
    // if the command "scriptrun" is run with flag "--generate", it should generate a 
    if (argv > 1) {
        std::string_view script_name { argc[1] };
        std::string script_path { bind_data[script_name] };
        std::cout << '|' << script_name << "|\n";
        std::cout << '|' << argc[1] << "|\n";

        std::system(script_path.c_str());
        std::cout << "runs " << script_name << '\n';

    }
    
    std::cout << "Current Path is: " << std::filesystem::current_path() << '\n';

    return 0;
}