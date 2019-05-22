/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <iostream>
#include "MarketValue.hpp"
#include "Currency.hpp"

#ifndef TRADE_2018_ACTION_HPP
#define TRADE_2018_ACTION_HPP

#define ACTION_ORDER_PATTERN "^action( +)order( +)(.*)"

class Action {
    public:
        Action();
        ~Action();

        size_t getOrder();
        std::list<std::string> getOutput();
        void addOutput(const std::string &output);
        void setOrder(const size_t &order);
        void buy(std::list<MarketValue> currentMarket);
        void sell(std::list<MarketValue> currentMarket);
        void pass();
    private:
        size_t _order;
        std::list<std::string> _output;
};


#endif //TRADE_2018_ACTION_HPP
