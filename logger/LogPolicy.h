#ifndef _LOG_POLICY_H_
#define _LOG_POLICY_H_

#include <string>
namespace logging {
class LogPolicy {
public:
    virtual void OpenOstream(const std::string& fileName) = 0;
    virtual void CloseOstream() = 0;
    virtual void Write(const std::string& msg) = 0;
};
}
#endif
