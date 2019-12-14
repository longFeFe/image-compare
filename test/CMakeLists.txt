
PROJECT(test_compare)
add_executable(${PROJECT_NAME}  main.cpp)
IF (${RUN_PLATFORM} STREQUAL "Linux")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ldl")
ENDIF ()