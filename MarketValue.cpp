/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "MarketValue.hpp"

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

void MarketValue::setLow(const float &low)
{
    this->_low = low;
}

void MarketValue::setHigh(const float &high)
{
    this->_high = high;
}

void MarketValue::setOpen(const float &open)
{
    this->_open = open;
}

void MarketValue::setClose(const float &close)
{
    this->_close = close;
}

void MarketValue::setVolume(const float &volume)
{
    this->_volume = volume;
}

currency::Type MarketValue::getPair()
{
    return (this->_pair);
}

time_t MarketValue::getDate()
{
    return (this->_date);
}

float MarketValue::getLow()
{
    return (this->_low);
}

float MarketValue::getHigh()
{
    return (this->_high);
}

float MarketValue::getOpen()
{
    return (this->_open);
}

float MarketValue::getClose()
{
    return (this->_close);
}

float MarketValue::getVolume()
{
    return (this->_volume);
}

/*
** Member fcn
*/
