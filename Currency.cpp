/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "Currency.hpp"

/*
** CTOR & DTOR
*/

Currency::Currency(const currency::Type &type) : _type(type)
{
    this->_type = type;
    this->_value = 0.00000000;
    this->_action = 0.00000000;
}

Currency::~Currency()
{
}

/*
** Getter & Setter
*/

void Currency::setType(const currency::Type &type)
{
    this->_type = type;
}

void Currency::setValue(const double &value)
{
    this->_value = value;
}

void Currency::setAction(const double &action)
{
    this->_action = action;
}

currency::Type Currency::getType()
{
    return (this->_type);
}

double Currency::getValue()
{
    return (this->_value);
}

double Currency::getAction()
{
    return (this->_action);
}

std::string Currency::getTypeReadable()
{
    std::string name = "";

    for (auto &it : Dictionary::Currency) {
        if (this->_type == it.second) {
            name = it.first;
        }
    }
    if ("" == name) {
        for (auto &it : Dictionary::Pair) {
           if (this->_type == it.second) {
               name = it.first;
           }
        }
    }
    return (name);
}

/*
** Member fcn
*/