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
    std::list<std::string> pairList = split(pairType, '_');
    std::string firstSymbol = pairList.begin()->c_str();
    auto it = pairList.end();
    it--;
    std::string secondSymbol = *it;
    for (auto &it : stackList) {
        if (it.getTypeReadable() == firstSymbol) {
            float stack = it.getValue() / 2;
            if (it.getTypeReadable() == secondSymbol) {
                if (it.getValue() > 0) {
                    throw Error(NONE, "stack not empty", INFO);
                }
            }
            if (0 == stack) {
                std::string s = std::to_string(it.getValue());
                std::string msg = "empty stack to buy "+ secondSymbol + " with " + it.getTypeReadable() + " : " + s;
                throw Error(NONE, msg, INFO);
            }
            float amount = stack / close;
            return (amount);
        }
    }
    throw Error(NONE, "impossible to find first symbol", INFO);
}


void Action::buy(std::list<Currency> stack, MarketValue currentMarket) {
    try {
        std::string pairType = currentMarket.getPairReadable();
        float amount = this->getBuyAmount(pairType, stack, currentMarket.getClose());
        std::string output = "buy " + pairType + " " + std::to_string(amount);
        this->_output.push_back(output);
    } catch (const Error &e) {
        std::cerr << e.getMsg() << std::endl;
    }
}

float Action::getSellAmount(std::string pairType, std::list<Currency> stackList)
{
    std::list<std::string> pairList = split(pairType, '_');
    auto itt = pairList.begin();
    auto it = pairList.end();
    it--;
    std::string secondSymbol = *it;
    for (auto &it : stackList) {
        if (it.getTypeReadable() == secondSymbol) {
            float stack = it.getValue();
            if (0 == stack) {
                std::string msg = "empty stack to sell " + it.getTypeReadable() + " with " +*itt;
                throw Error(NONE, msg, INFO);
            }
            return (stack);
        }
    }
    throw Error(NONE, "impossible to find first symbol", INFO);
}

void Action::sell(std::list<Currency> stack, MarketValue currentMarket) {
    try {
        std::string pairType = currentMarket.getPairReadable();
        float amount = this->getSellAmount(pairType, stack);
        std::string output = "sell " + pairType + " " + std::to_string(amount);
        this->_output.push_back(output);
    } catch (const Error &e) {
        std::cerr << e.getMsg() << std::endl;
    }
}

void Action::clearOutput()
{
    this->_output.clear();
}

void Action::pass() {
    std::string pass = "pass";
    this->_output.push_back(pass);
}