#ifndef _LOGGER_H_
#define _LOGGER_H_

#include <string>
#include <sstream>
#include <mutex>

namespace logging {

enum class SeverityType {
    Debug,
    Warning,
    Error
};

template<typename LogPolicy>
class Logger {
public:
    Logger(const std::string& fileName);
    ~Logger();
    template<SeverityType severity, typename...Args>
    void Print(Args...args);
private:
    template<typename First, typename...Rest>
    void PrintImpl(First parm1, Rest...parm);

    void PrintImpl();
private:
    std::mutex _writeMutex;
    std::stringstream _logStream;
    LogPolicy* _policy;
};

template<typename LogPolicy>
Logger<LogPolicy>::Logger(const std::string& fileName)
{
    _policy = new LogPolicy;
    _policy->OpenOstream(fileName);
}
template<typename LogPolicy>
Logger<LogPolicy>::~Logger()
{
    if (_policy) {
        _policy->CloseOstream();
        delete _policy;
    }
}

template<typename LogPolicy>
    template<SeverityType severity, typename...Args>
void Logger<LogPolicy>::Print(Args...args)
{
    _writeMutex.lock();
    switch (severity) {
        case SeverityType::Debug:
            _logStream<<"/D:";
            break;
        case SeverityType::Warning:
            _logStream<<"/W:";
            break;
        case SeverityType::Error:
            _logStream<<"/E:";
            break;
    }
    PrintImpl(args...);
    _writeMutex.unlock();
}

template<typename LogPolicy>
void Logger<LogPolicy>::PrintImpl()
{
    _policy->Write(_logStream.str());
    _logStream.str("");
}

template<typename LogPolicy>
    template<typename First, typename...Rest>
void Logger<LogPolicy>::PrintImpl(First parm1, Rest...parm)
{
    _logStream<<parm1;
    PrintImpl(parm...);
}

}
#endif
