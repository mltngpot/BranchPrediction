# CMakeList.txt : CMake project for BranchPrediction, include source and define
# project specific logic here.
#

project(BranchPrediction)
include_directories(include)
file(GLOB SOURCES "src/*.cpp")

# Add source to this project's executable.
add_executable (BranchPrediction ${SOURCES} "src/include/PredictStats.h" "src/PredictStats.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BranchPrediction PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
