cmake_minimum_required(VERSION 3.10)
project(client_app)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable Qt's Meta-Object Compiler
set(CMAKE_AUTOMOC ON)

# Find Qt6 modules (standalone or as part of a larger project)
if(NOT TARGET Qt6::Core)
    find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)
endif()

# Source files for the client project
set(CLIENT_SOURCES
        src/client.cpp
)

# Header files for the client project
set(CLIENT_HEADERS
        include/client.h
)

# Define the executable target for the client
add_executable(client_app
        ${CLIENT_SOURCES}
        ${CLIENT_HEADERS}
)

# Link the client executable with Qt libraries
target_link_libraries(client_app PRIVATE Qt6::Core Qt6::Widgets Qt6::Network)

# Set include directories for this target only
target_include_directories(client_app PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)