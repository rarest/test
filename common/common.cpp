//
// Created by HFX on 2020/5/9.
//

#include "common.h"
#include <thread>
#include <iostream>
#include <sstream>

#include <memory>

BEGIN_INTERVIEW_NS
    shared_ptr<uint8_t> init_matrix(int w, int h) {
        shared_ptr<uint8_t> matrix(new uint8_t[h * w]);
        for (int i = 0; i < h * w; i++) {
            matrix.get()[i] = i;
        }
        return matrix;
    }

    void print_matrix(uint8_t *matrix, int w, int h) {
        cout.setf(std::ios::right);
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::cout << right << setw(2) << (int) matrix[i * w + j] << " ";
            }
            std::cout << endl;
        }
        std::cout << endl;
    }

    std::string get_tid() {
        std::stringstream tmp;
        tmp << std::this_thread::get_id();
        return tmp.str();
    }


    std::unique_ptr<ILogger> active_logger = std::make_unique<Logger>(Logger::LogLevel::debug);


    void
    debug(const std::string &msg, const std::string &file, std::size_t line) {
        if (active_logger)
            active_logger->debug(msg, file, line);
    }

    void
    info(const std::string &msg, const std::string &file, std::size_t line) {
        if (active_logger)
            active_logger->info(msg, file, line);
    }

    void
    warn(const std::string &msg, const std::string &file, std::size_t line) {
        if (active_logger)
            active_logger->warn(msg, file, line);
    }

    void
    error(const std::string &msg, const std::string &file, std::size_t line) {
        if (active_logger)
            active_logger->error(msg, file, line);
    }

END_INTERVIEW_NS