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
        void buy(std::list<Currency> stack, MarketValue currentMarket);
        void sell(std::list<Currency> stack, MarketValue currentMarket);
        void pass();

        float getBuyAmount(std::string pairType, std::list<Currency> stackList, float close);
        float getSellAmount(std::string pairType, std::list<Currency> stackList);
        void clearOutput();
    private:
        size_t _order;
        std::list<std::string> _output;
};


#endif //TRADE_2018_ACTION_HPP
