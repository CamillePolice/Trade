/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Display the action
*/

#include <regex>
#include "Action.hpp"
#include "Error.hpp"

/*
** CTOR & DTOR
*/

Action::Action() {
    this->_order = -1;
}

Action::~Action() = default;

/*
** Getter & Setter
*/

size_t Action::getOrder() {
    return (this->_order);
}

void Action::setOrder(const size_t &order) {
    this->_order = order;
}

std::list<std::string> Action::getOutput()
{
    return (this->_output);
}

/*
** Member fcn
*/

static std::list<std::string> split(const std::string &s, char delim)
{
    std::list<std::string> list;
    std::stringstream ss(s);
    std::string toAdd;

    while (getline (ss, toAdd, delim)) {
        list.push_back (toAdd);
    }
    return (list);
}

float Action::getBuyAmount(std::string pairType, std::list<Currency> stackList, float close)
{
    std::list<std::string> pairList = split(pairType, ':');
    std::string firstSymbol = pairList.begin()->c_str();

    for (auto &it : stackList) {
        if (it.getTypeReadable() == firstSymbol) {
            float stack = it.getValue();
            return (stack * close);
        }
    }
    throw Error(NONE, "impossible to find first symbol", INFO);
}


void Action::buy(std::list<Currency> stack, MarketValue currentMarket) {
    try {
        std::string pairType = currentMarket.getPairReadable();
        float amount = this->getBuyAmount(pairType, stack, currentMarket.getClose());
        if (0 < amount) {
            std::string output = "buy " + pairType + " " + std::to_string(amount);
            this->_output.push_back(output);
        }
    } catch (const Error &e) {
        return;
    }
}

float Action::getSellAmount(std::string pairType, std::list<Currency> stackList)
{
    std::list<std::string> pairList = split(pairType, ':');
    std::string firstSymbol = pairList.begin()->c_str();

    for (auto &it : stackList) {
        if (it.getTypeReadable() == firstSymbol) {
            float stack = it.getValue();
            return (stack);
        }
    }
    throw Error(NONE, "impossible to find first symbol", INFO);
}

void Action::sell(std::list<Currency> stack, MarketValue currentMarket) {
    try {
        std::string pairType = currentMarket.getPairReadable();
        float amount = this->getSellAmount(pairType, stack);
        if (0 < amount) {
            std::string output = "sell " + pairType + " " + std::to_string(amount);
            this->_output.push_back(output);
        }
    } catch (const Error &e) {
        return;
    }
}

void Action::pass() {
    std::string pass = "pass";
    this->_output.push_back(pass);
}