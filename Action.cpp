/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** Display the action
*/

#include "Action.hpp"

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

void Action::buy(std::list<MarketValue> currentMarket) {

}

void Action::sell(std::list<MarketValue> currentMarket) {

}

void Action::pass() {
    std::cout << "pass" << std::endl;
}