cmake_minimum_required(VERSION 3.14)
project(trade_2018)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(trade_2018
        Action.cpp
        Action.hpp
        Currency.cpp
        Currency.hpp
        Error.cpp
        Error.hpp
        Main.cpp
        MarketValue.cpp
        MarketValue.hpp
        MyBot.cpp
        MyBot.hpp
        Setting.cpp
        Setting.hpp
        Update.cpp
        Update.hpp)
