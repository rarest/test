//
// Created by Chen Shuquan on 2020/7/3.
//

#include "common.h"
#include "source.h"
#include <fstream>
#include <sstream>
#include <map>

// trim from start
static inline std::string &ltrim(std::string &s) {
s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
    return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}



int main() {
    const char* filePath = "../src/02_cpp/03_readline/meta.conf";
    std::ifstream is_file(filePath);
//    std::istringstream is_file2(data);
    std::map<std::string, std::string> kv;
    std::string line;

    while (std::getline(is_file,line)){
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {

            key = trim(key);
            if (key.empty() || key.at(0) == '#') continue;

            std::string value;
            if ( std::getline(is_line, value) ) {
                value = trim(value);
                kv[key] = value;
            }
        }
    }
    if (kv.find("keywords") != kv.end()) {
        std::istringstream iss(kv["keywords"]);
        std::string wordstr;
        while (iss >> wordstr) {
            printf("%s\n", wordstr.c_str());
        }
    }

    return 0;
}