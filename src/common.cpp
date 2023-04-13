#include "common.h"

std::string utils::read_file(const char* path) {
    std::string contents;
    std::ifstream fileStream(path, std::ios::in);
    if(fileStream.is_open()) {
        std::stringstream sstr;
        sstr << fileStream.rdbuf();
        contents = sstr.str();
        fileStream.close();
    } else {
        ERRORNR("Unable to read " << path << "\n");
        getchar();
        return 0;
    }
    
    return contents;
}

void utils::log_info(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[4096]; // 4kb buffer (kinda overkill (probably))
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    std::cout << buffer << '\n';
}

void utils::log_error(const char* format, ...) {
    va_list args;
    va_start(args, format);
    char buffer[4096]; // 4kb buffer (kinda overkill (probably))
    std::strcat(buffer, utils::log_prefix);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);
    std::cerr << buffer << '\n';
}