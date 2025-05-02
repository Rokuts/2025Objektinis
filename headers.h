#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cstdlib>  //random
#include <cctype> // darbas su simboliais
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>

using std::string;
using std::sort;
using std::cout;
using std::cin;
using std::endl;
using std::max;
using std::left;
using std::setw;
using std::vector;
using std::numeric_limits;
using std::streamsize;
using std::fixed;
using std::setprecision;
using std::ostream;
using std::ifstream;
using std::filesystem::path;
using std::getline;
using std::stringstream;

inline bool fs_exists(const std::filesystem::path& p) {
    return std::filesystem::exists(p);
}

using std::ofstream;