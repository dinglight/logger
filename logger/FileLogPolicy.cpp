#include "FileLogPolicy.h"
namespace logging {
FileLogPolicy::FileLogPolicy()
: _outStream(new std::ofstream)
{}

FileLogPolicy::~FileLogPolicy()
{
    if (_outStream) {
        CloseOstream();
    }
}

void FileLogPolicy::OpenOstream(const std::string& fileName)
{
    _outStream->open(fileName.c_str(), std::ios_base::binary|std::ios_base::out);
    if (!_outStream->is_open()) {
        throw(std::runtime_error("LOGGER: Unable to open an output stream"));
    }
}

void FileLogPolicy::CloseOstream()
{
    if (_outStream) {
        _outStream->close();
    }
}

void FileLogPolicy::Write(const std::string& msg)
{
    (*_outStream)<<msg<<std::endl;
}
}
