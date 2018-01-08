cmake_minimum_required(VERSION 3.8)
project(RTYPE)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /Ox")

set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include_directories("${PROJECT_BINARY_DIR}" "include")
link_directories("${CMAKE_SOURCE_DIR}/SFML/bin")

set(CMAKE_BUILD_TYPE Release)
find_package(SFML 2 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR} ${PROJECT_SOURCE_DIR})

set(SOURCE_FILES src/Entity.cpp
                 src/Player.cpp
                 src/main.cpp
                 src/Animation.cpp
                 src/Bg.cpp
                 src/Game.cpp
                 src/Level.cpp
                 src/Bullet.cpp
                src/Enemy.cpp )

set(HEADER_FILES include/IEntity.h
                 include/Entity.h
                 include/Player.h
                 include/Animation.h
                 include/Game.h
                 include/Bg.h
                 include/Enum.h
                 include/Level.h
                 include/Bullet.h include/Enemy.h src/TextureManager.cpp include/TextureManager.h src/Weapon.cpp include/Weapon.h)

add_executable(RTYPE ${SOURCE_FILES} ${HEADER_FILES})
target_link_libraries(RTYPE ${SFML_LIBRARIES})

add_custom_command(TARGET RTYPE PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/ressources $<TARGET_FILE_DIR:RTYPE>/ressources
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/SFML/bin $<TARGET_FILE_DIR:RTYPE>)