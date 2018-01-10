cmake_minimum_required(VERSION 3.8)
project(r-type)
set(CMAKE_CXX_STANDARD 17)



if (WIN32)
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")
elseif (APPLE)
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-osx-clang")
    set(CMAKE_MACOSX_RPATH 1)
endif (WIN32)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include_directories("${PROJECT_BINARY_DIR}" "include")
link_directories("${CMAKE_SOURCE_DIR}/SFML/bin")

set(CMAKE_BUILD_TYPE Release)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/thor-v2.0-sdk/thor-v2.0-sdk/include
        ${CMAKE_SOURCE_DIR}/thor-v2.0-sdk/thor-v2.0-sdk/extlibs/aurora/include)

set(SOURCE_FILES
        src/Entity.cpp
        src/Player.cpp
        src/main.cpp
        src/Animation.cpp
        src/Bg.cpp
        src/Game.cpp
        src/Level.cpp
        src/Bullet.cpp
        src/Enemy.cpp
        src/Menu.cpp
        src/Weapon.cpp
        src/TextureManager.cpp
        src/Parsing.cpp
        src/HUD.cpp)

set(HEADER_FILES
        include/IEntity.h
        include/Entity.h
        include/Player.h
        include/Animation.h
        include/Game.h
        include/Bg.h
        include/Enum.h
        include/Level.h
        include/Bullet.h
        include/Enemy.h
        include/TextureManager.h
        include/Weapon.h
        include/Menu.h
        include/WindowProperties.h
        include/HUD.h
        include/Parsing.h)

add_executable(r-type ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(r-type ${SFML_LIBRARIES})

add_subdirectory(thor-v2.0-sdk/thor-v2.0-sdk)

target_link_libraries(r-type thor)

add_custom_command(TARGET r-type PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/ressources $<TARGET_FILE_DIR:r-type>/ressources)

if (WIN32)
    add_custom_command(TARGET r-type PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/SFML/bin $<TARGET_FILE_DIR:r-type>)
endif ()
