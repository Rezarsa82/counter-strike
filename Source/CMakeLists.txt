cmake_minimum_required(VERSION 3.21)
project(counter_strike)

set(CMAKE_CXX_STANDARD 14)

find_package(Protobuf REQUIRED)
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS Data.proto)

add_executable(counter_strike main.cpp Team/Warrior/Warrior.cpp Team/Warrior/Warrior.h Team/Warrior/Score/Score.cpp
        Team/Warrior/Score/Score.h Team/Warrior/Money/Money.cpp Team/Warrior/Money/Money.h Team/Warrior/Health/Health.cpp
        Team/Warrior/Health/Health.h Team/Weapon/Weapon.cpp Team/Weapon/Weapon.h Team/Weapon/WeaponsData.cpp
        Team/Weapon/WeaponsData.h Team/Team.cpp Team/Team.h Time/Time.cpp Time/Time.h GameFeatures/Exception/Exception.cpp
        GameFeatures/Exception/Exception.h GameFeatures/ControlCenter/ControlCenter.cpp
        GameFeatures/ControlCenter/ControlCenter.h GameFeatures/Configuration/Configuration.cpp
        GameFeatures/Configuration/Configuration.h ${PROTO_SRCS} ${PROTO_HDRS})

target_link_libraries(counter_strike ${Protobuf_LIBRARIES})
