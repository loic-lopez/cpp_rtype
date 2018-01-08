cmake_minimum_required(VERSION 3.8)
project(r-type)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/SFML/cmake/Modules")

add_subdirectory(SFML)
set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")

include_directories("${PROJECT_BINARY_DIR}" "include")

set(CMAKE_BUILD_TYPE Release)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

find_package(SFML 2 REQUIRED network audio graphics window system)


set(SOURCE_FILES sources/Entity.cpp
                 sources/Player.cpp
                 sources/main.cpp
                 sources/Animation.cpp
                 sources/Bg.cpp
                 sources/Game.cpp
                 sources/Level.cpp
                 sources/Bullet.cpp
                sources/Enemy.cpp )

set(HEADER_FILES include/IEntity.h
                 include/Entity.h
                 include/Player.h
                 include/Animation.h
                 include/Game.h
                 include/Bg.h
                 include/Enum.h
                 include/Level.h
                 include/Bullet.h include/Enemy.h sources/TextureManager.cpp include/TextureManager.h sources/Weapon.cpp include/Weapon.h)


add_executable(r-type ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(r-type ${SFML_LIBRARIES})


add_custom_command(TARGET r-type PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/ressources $<TARGET_FILE_DIR:r-type>/ressources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/SFML/bin $<TARGET_FILE_DIR:r-type>)