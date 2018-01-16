cmake_minimum_required(VERSION 3.8)
project(r-type)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})


if (WIN32)
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML")
    link_directories("${CMAKE_SOURCE_DIR}/SFML/bin")
elseif (APPLE)
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-osx-clang")
    set(CMAKE_MACOSX_RPATH 1)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -gdwarf-3")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-3")
    set(CMAKE_CXX_FLAGS_RELWITHDEBINFO  "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} -gdwarf-3")
    set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} -gdwarf-3")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
    set(SFML_ROOT "${CMAKE_SOURCE_DIR}/SFML-Linux")
    link_directories("${CMAKE_SOURCE_DIR}/SFML-Linux/lib")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
endif (WIN32)


set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
include_directories("${PROJECT_BINARY_DIR}" "include")

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
        src/Core/MenuCore.cpp
        src/Level/Level.cpp
        src/Bullet.cpp
        src/Enemy.cpp
        src/Handler/MenuHandler.cpp
        src/Weapon.cpp
        src/TextureManager.cpp
        src/Parsing.cpp
        src/HUD.cpp
        src/Button.cpp
        src/SplashScreen.cpp
        src/Core/GameCore.cpp
        src/Handler/GameHandler.cpp src/Level/ALevel.cpp)

file(GLOB SOURCE_SELBA ${PROJECT_SOURCE_DIR}/src/SelbaWardSrc/*.cpp ${PROJECT_SOURCE_DIR}/src/SelbaWardSrc/*.inl)
file(GLOB SOURCE_SELBA_HPP ${PROJECT_SOURCE_DIR}/include/SelbaWard/*.hpp)

set(HEADER_FILES
        include/IEntity.h
        include/Entity.h
        include/Player.h
        include/Animation.h
        include/Core/MenuCore.hpp
        include/Bg.h
        include/Enum.h
        include/Level/Level.h
        include/Bullet.h
        include/Enemy.h
        include/TextureManager.h
        include/Weapon.h
        include/Handler/MenuHandler.h
        include/WindowProperties.h
        include/HUD.h
        include/Parsing.h
        include/Button.h
        include/SelbaWard.hpp
        include/SplashScreen.h
        include/Core/GameCore.h
        include/Handler/GameHandler.h
        include/Core/GameOverScreenCore.h
        src/Core/GameOverScreenCore.cpp
        src/Handler/GameOverScreenHandler.cpp
        include/Handler/GameOverScreenHandler.h include/Level/ALevel.h)


add_executable(r-type ${SOURCE_FILES} ${HEADER_FILES} ${SOURCE_SELBA} ${SOURCE_SELBA_HPP})
target_link_libraries(r-type ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

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
