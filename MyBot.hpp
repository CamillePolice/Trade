/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/
#ifndef TRADE_2018_MYBOT_HPP
#define TRADE_2018_MYBOT_HPP

#include <stdio.h>
#include <regex>
#include <iostream>
#include <tgmath.h>

#include "Setting.hpp"
#include "Update.hpp"
#include "Action.hpp"
#include "Currency.hpp"
#include "Error.hpp"
#include "MarketValue.hpp"

#define QUIT "quit"

template<char delimiter>
class WordDelimitedBy : public std::string
{};

/*
 * Enum SECTION
 */

namespace input {
    enum Type {
        SETTING,
        UPDATE,
        ACTION
    };
}

/*
 * Class SECTION
 */

class MyBot {
    public:
        MyBot();
        ~MyBot();

        void run();
        double average(std::list<MarketValue> list);
        double standardDeviation(std::list<MarketValue> list);
        double variance(std::list<MarketValue> list);
        void trade();

        /*
         *  INPUT PARSER SECTION
         */

        bool saveInput();
        bool isSetting();
        bool isUpdate();
        bool setNextCandle(std::string value);
        bool setStack(const std::string& value);
        bool isAction();

        void buy(std::list<MarketValue> marketValue);
        void sell(std::list<MarketValue> marketValue);
        void printOutput();
        void close();

    private:
        Setting _setting;
        Update _update;
        Action _action;
        std::string _input;
        float _standardDeviation;
        float _variance;
};

#endif //TRADE_2018_MYBOT_HPP
