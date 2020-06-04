//
// Created by Chen Shuquan on 2020/6/4.
//

#include "Logger.h"
#include <iostream>
static const char black[] = {0x1b, '[', '1', ';', '3', '0', 'm', 0};
static const char red[] = {0x1b, '[', '1', ';', '3', '1', 'm', 0};
static const char yellow[] = {0x1b, '[', '1', ';', '3', '3', 'm', 0};
static const char blue[] = {0x1b, '[', '1', ';', '3', '4', 'm', 0};
static const char normal[] = {0x1b, '[', '0', ';', '3', '9', 'm', 0};

Logger::Logger(LogLevel level)
        : m_level(level) {}

void
Logger::debug(const std::string &msg, const std::string &file, std::size_t line) {
    if (m_level >= LogLevel::debug) {
        std::lock_guard <std::mutex> lock(m_mutex);
        std::cout << "[" << black << "DEBUG" << normal << "][Logger][" << file << ":" << line << "] " << msg
                  << std::endl;
    }
}

void
Logger::info(const std::string &msg, const std::string &file, std::size_t line) {
    if (m_level >= LogLevel::info) {
        std::lock_guard <std::mutex> lock(m_mutex);
        std::cout << "[" << blue << "INFO " << normal << "][Logger][" << file << ":" << line << "] " << msg
                  << std::endl;
    }
}

void
Logger::warn(const std::string &msg, const std::string &file, std::size_t line) {
    if (m_level >= LogLevel::warn) {
        std::lock_guard <std::mutex> lock(m_mutex);
        std::cout << "[" << yellow << "WARN " << normal << "][Logger][" << file << ":" << line << "] " << msg
                  << std::endl;
    }
}

void
Logger::error(const std::string &msg, const std::string &file, std::size_t line) {
    if (m_level >= LogLevel::error) {
        std::lock_guard <std::mutex> lock(m_mutex);
        std::cerr << "[" << red << "ERROR" << normal << "][Logger][" << file << ":" << line << "] " << msg
                  << std::endl;
    }
}