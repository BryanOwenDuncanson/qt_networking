cmake_minimum_required(VERSION 3.18)
project(qt_network_widgets)

# Enable C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt6 globally
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

# Add subdirectories for subprojects
add_subdirectory(shared)
add_subdirectory(client)
add_subdirectory(server)

