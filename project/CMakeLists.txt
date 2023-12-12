cmake_minimum_required(VERSION 3.25)
project(address-book)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(nlohmann_json 3.11.3 REQUIRED)
find_package(stduuid 1.2.3 REQUIRED)
find_package(tabulate 1.5 REQUIRED)

file(GLOB_RECURSE SRCS CONFIGURE_DEPENDS "src/*.cpp" "src/*.hpp")

add_executable(${PROJECT_NAME} ${SRCS})
target_include_directories(${PROJECT_NAME} PRIVATE src)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE 
    nlohmann_json::nlohmann_json 
    stduuid::stduuid
    tabulate::tabulate
)
