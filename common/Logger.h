//
// Created by Chen Shuquan on 2020/6/4.
//

#ifndef INTERVIEW_LOGGER_H
#define INTERVIEW_LOGGER_H

#include <string>
#include <mutex>

class ILogger {
public:
    ILogger() = default;

    virtual ~ILogger() = default;

    ILogger(const ILogger &) = delete;

    ILogger &operator=(const ILogger &) = delete;

public:
    virtual void debug(const std::string &msg, const std::string &file, std::size_t line) = 0;

    virtual void info(const std::string &msg, const std::string &file, std::size_t line) = 0;

    virtual void warn(const std::string &msg, const std::string &file, std::size_t line) = 0;

    virtual void error(const std::string &msg, const std::string &file, std::size_t line) = 0;
};

class Logger : public ILogger {
public:
    enum class LogLevel {
        error = 0,
        warn = 1,
        info = 2,
        debug = 3
    };

public:
    explicit Logger(LogLevel level = LogLevel::info);

    ~Logger() override = default;

public:
    void debug(const std::string &msg, const std::string &file, std::size_t line) override;

    void info(const std::string &msg, const std::string &file, std::size_t line) override;

    void warn(const std::string &msg, const std::string &file, std::size_t line) override;

    void error(const std::string &msg, const std::string &file, std::size_t line) override;

private:
    LogLevel m_level;
    std::mutex m_mutex;
};

#endif //INTERVIEW_LOGGER_H
