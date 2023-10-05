include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

set(TEST_FILES WarriorTest.cpp TeamTest.cpp HealthTest.cpp ScoreTest.cpp MoneyTest.cpp)

add_executable(Google_Tests_run ${TEST_FILES})
add_library(FILE STATIC ../Source/Time/Time.h ../Source/Time/Time.cpp ../Source/Team/Warrior/Warrior.cpp ../Source/Team/Warrior/Warrior.h ../Source/Team/Warrior/Score/Score.cpp
        ../Source/Team/Warrior/Score/Score.h ../Source/Team/Warrior/Money/Money.cpp ../Source/Team/Warrior/Money/Money.h ../Source/Team/Warrior/Health/Health.cpp
        ../Source/Team/Warrior/Health/Health.h ../Source/Team/Weapon/Weapon.cpp ../Source/Team/Weapon/Weapon.h ../Source/Team/Weapon/WeaponsData.cpp
        ../Source/Team/Weapon/WeaponsData.h ../Source/Team/Team.cpp ../Source/Team/Team.h ../Source/Time/Time.cpp ../Source/Time/Time.h ../Source/GameFeatures/Exception/Exception.cpp
        ../Source/GameFeatures/Exception/Exception.h ../Source/GameFeatures/ControlCenter/ControlCenter.cpp
        ../Source/GameFeatures/ControlCenter/ControlCenter.h ../Source/GameFeatures/Configuration/Configuration.cpp
        ../Source/GameFeatures/Configuration/Configuration.h)

target_link_libraries(Google_Tests_run GTest::gtest GTest::gtest_main FILE)
