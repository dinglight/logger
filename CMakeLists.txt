cmake_minimum_required(VERSION 3.5)

# set the project name and version
project(logtest)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the logger library
add_subdirectory(logger)
list(APPEND EXTRA_LIBS logger)
list(APPEND EXTRA_INCLUDES "${PROJECT_SOURCE_DIR}/logger")

# add the executable
add_executable(${PROJECT_NAME} test.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(${PROJECT_NAME} PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           ${EXTRA_INCLUDES}
                           )
