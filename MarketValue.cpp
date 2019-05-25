/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "MarketValue.hpp"
#include "Error.hpp"

/*
** CTOR & DTOR
*/

MarketValue::MarketValue()
{}

MarketValue::~MarketValue()
{}

/*
** Getter & Setter
*/
void MarketValue::setPair(const currency::Type &pair)
{
    this->_pair = pair;
}

void MarketValue::setDate(const time_t &date)
{
    this->_date = date;
}

void MarketValue::setLow(const double &low)
{
    this->_low = low;
}

void MarketValue::setHigh(const double &high)
{
    this->_high = high;
}

void MarketValue::setOpen(const double &open)
{
    this->_open = open;
}

void MarketValue::setClose(const double &close)
{
    this->_close = close;
}

void MarketValue::setVolume(const double &volume)
{
    this->_volume = volume;
}

currency::Type MarketValue::getPair()
{
    return (this->_pair);
}

std::string MarketValue::getPairReadable()
{
    std::string pair;

    for (auto &it : Dictionary::Pair) {
        if (it.second == this->_pair) {
            std::string pair = it.first;
            return (pair);
        }
    }
    throw Error(NONE, "impossible to find pair", INFO);
}

time_t MarketValue::getDate()
{
    return (this->_date);
}

double MarketValue::getLow()
{
    return (this->_low);
}

double MarketValue::getHigh()
{
    return (this->_high);
}

double MarketValue::getOpen()
{
    return (this->_open);
}

double MarketValue::getClose()
{
    return (this->_close);
}

double MarketValue::getVolume()
{
    return (this->_volume);
}

/*
** Member fcn
*/
