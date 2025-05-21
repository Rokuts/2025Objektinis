#pragma once

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cctype> // darbas su simboliais
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include <chrono>

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
using std::mt19937;
using std::chrono::system_clock;
using std::uniform_int_distribution;
using std::to_string;
using std::ceil;
using std::log10;
using std::chrono::high_resolution_clock;
using std::chrono::duration;



inline bool fs_exists(const std::filesystem::path& p) {
    return std::filesystem::exists(p);
}

using std::ofstream;

void meniu();