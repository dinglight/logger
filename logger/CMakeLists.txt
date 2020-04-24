add_library(logger FileLogPolicy.cpp)

# state that anybody linking to us needs to include the current source dir
# to find MathFunctions.h, while we don't.
target_include_directories(logger
          INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
          )
