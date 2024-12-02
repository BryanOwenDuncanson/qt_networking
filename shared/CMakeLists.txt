project(shared)

# Include directories for header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# Source files for the shared library
set(SHARED_SOURCES
        src/utils.cpp
)

# Header files for the shared library
set(SHARED_HEADERS
        include/utils.h
)

# Create a static library for shared code
add_library(shared STATIC ${SHARED_SOURCES} ${SHARED_HEADERS})

# Link against Qt5
target_link_libraries(shared Qt6:Core)

# Add include directory for the shared library
target_include_directories(shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
