/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <list>
#include "Currency.hpp"
#include "MarketValue.hpp"

#ifndef TRADE_2018_UPDATE_HPP
#define TRADE_2018_UPDATE_HPP

#define UPDATE_NEXTCANDLE_PATTERN "^update( +)game( +)next_candles( +)(.*)"
#define UPDATE_STACKS_PATTERN "^update( +)game( +)stacks( +)(.*)"

class Update {
    public:
        Update();
        ~Update();

        /*
         * SETTER
         */

        void setStackByInput(std::list<std::string> &input);
        void setNextCandleByInput(std::list<std::string> &input);

        /*
         * GETTER
         */

        std::map<currency::Type, std::list<MarketValue>> getCandleList();
        std::list<Currency> getStack();

    private:
        std::map <currency::Type, std::list<MarketValue>> _marketValue;
        std::list<Currency> _stack;
};

#endif //TRADE_2018_UPDATE_HPP
