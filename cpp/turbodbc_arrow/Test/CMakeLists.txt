include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(SYSTEM $ENV{GOOGLETEST_INCLUDE_DIR})
include_directories(SYSTEM "${CMAKE_SOURCE_DIR}/pybind11/include")


file(GLOB_RECURSE TEST_FILES "*.cpp")

link_directories($ENV{GOOGLETEST_LIB_DIR})

add_executable(turbodbc_arrow_test ${TEST_FILES})
add_dependencies(turbodbc_arrow_test googletest_build)

add_dependencies(turbodbc_arrow_test
    refresh_cmake_configuration
)

target_link_libraries(turbodbc_arrow_test
    turbodbc
    turbodbc_arrow_support
    cpp_odbc
    ${Odbc_LIBRARIES}
    ${PYTHON_LIBRARY}
    gmock_main
    gtest
    gmock
    pthread
)

add_test(NAME turbodbc_arrow_unit_test
         COMMAND turbodbc_arrow_test --gtest_output=xml:${CMAKE_BINARY_DIR}/turbodbc_arrow_test.xml)

