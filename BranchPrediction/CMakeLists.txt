# CMakeList.txt : CMake project for BranchPrediction, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (BranchPrediction "BranchPrediction.cpp" "BranchPrediction.h" "BufferEntry.h" "Buffer.h" "PatternHistoryTable.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BranchPrediction PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
