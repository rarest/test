//
// Created by Chen Shuquan on 2020/6/4.
//

#ifndef INTERVIEW_LOGGER_H
#define INTERVIEW_LOGGER_H


class ILogger {
public:
    ILogger(void) = default;

    virtual ~ILogger(void) = default;

    ILogger(const ILogger &) = default;

    ILogger &operator=(const ILogger &) = default;

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
    ~Logger(void) = default;
    Logger(const Logger &) = default;
    Logger &operator=(const Logger &) = default;

public:
    void debug(const std::string &msg, const std::string &file, std::size_t line);

    void info(const std::string &msg, const std::string &file, std::size_t line);

    void warn(const std::string &msg, const std::string &file, std::size_t line);

    void error(const std::string &msg, const std::string &file, std::size_t line);

private:
    LogLevel m_level;
    std::mutex m_mutex;
};

#endif //INTERVIEW_LOGGER_H
