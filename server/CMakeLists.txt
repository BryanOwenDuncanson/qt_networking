cmake_minimum_required(VERSION 3.16)
project(serverApp)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt's Meta-Object Compiler
set(CMAKE_AUTOMOC ON)

# Set the path to Qt (adjust if necessary)
set(CMAKE_PREFIX_PATH "/opt/homebrew/lib/cmake/Qt6")

# Find Qt modules (standalone or as part of a larger project)
if(NOT TARGET Qt6::Core)
    find_package(Qt6 REQUIRED COMPONENTS Core Network)
endif()

# Source files for the server project
set(SERVER_SOURCES
        src/server_daemon.cpp
        src/api_handler.cpp
        main.cpp
)

# Header files for the server project (for organization, not mandatory in add_executable)
set(SERVER_HEADERS
        include/server_daemon.h
        include/api_handler.h
)

# Define the executable target for the server
add_executable(server_app
        ${SERVER_SOURCES}
)

# Link the server executable with Qt libraries
target_link_libraries(serverApp PRIVATE Qt6::Core Qt6::Network)

# Set include directories for this target only
target_include_directories(serverApp PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
