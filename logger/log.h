#ifndef LOG_H
#define LOG_H

#define LOGGING_ENABLE

#include "Logger.h"
#include "FileLogPolicy.h"

static logging::Logger<logging::FileLogPolicy> glogInst("execution.log");

#ifdef LOGGING_ENABLE
#define LOG glogInst.Print<logging::SeverityType::Debug>
#else
#define LOG(...)
#endif

#endif
