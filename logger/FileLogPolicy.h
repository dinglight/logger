#ifndef _FILE_LOG_POLICY_H_
#define _FILE_LOG_POLICY_H_

#include "LogPolicy.h"
#include <memory>
#include <fstream>
namespace logging {
class FileLogPolicy : public LogPolicy {
public:
    FileLogPolicy();
    ~FileLogPolicy();
public:
    void OpenOstream(const std::string& fileName) override;
    void CloseOstream() override;
    void Write(const std::string& msg) override;
private:
    std::unique_ptr<std::ofstream> _outStream;
};
}
#endif
