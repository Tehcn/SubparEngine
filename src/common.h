#ifndef SE_COMMON_H
#define SE_COMMON_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstdarg>
#include <cstring>

static unsigned long errcode = 0;
#define ERRORNR(msg) do { errcode += 1; std::cerr << "Error #"<< errcode << ": " << msg << '\n'; } while(0)
#define ERRORC(msg, clean) do { errcode += 1; std::cerr << "Error #"<< errcode << ": " << msg << '\n'; clean(); return -1; } while(0)
#define ERRORCNR(msg, clean) do { errcode += 1; std::cerr << "Error #"<< errcode << ": " << msg << '\n'; clean(); } while(0)

namespace utils {
    static const char* log_prefix = "SubparGames ";

    std::string read_file(const char* path);

    void log_info(const char* format, ...);

    void log_error(const char* format, ...);
}

#endif