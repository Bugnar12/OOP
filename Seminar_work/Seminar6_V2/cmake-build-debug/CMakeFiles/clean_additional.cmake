# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\Seminar6_V2_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\Seminar6_V2_autogen.dir\\ParseCache.txt"
  "Seminar6_V2_autogen"
  )
endif()
