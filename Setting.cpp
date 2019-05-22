/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "Setting.hpp"

/*
** CTOR & DTOR
*/

Setting::Setting()
{
    /*
     * SET VALUE BY DEFAULT IF SETTINGS IS NOT COMPLETE
     */
    this->_timebank = -1;
    this->_timePerMove = -1;
    this->_botName = DEFAULT_PLAYERNAME;
    this->_candle._given = -1;
    this->_candle._total = -1;
    this->_candle._interval = -1;
    this->_initialStack = -1;
}

Setting::~Setting()
{
    this->_candle._format.clear();
    this->_playerName.clear();
}

/*
** Getter & Setter
*/

void Setting::setBotName(const std::string &botName)
{
    this->_botName = botName;
}

void Setting::setTimebank(const size_t &timebank)
{
    this->_timebank = timebank;
}

void Setting::setTimePerMove(const size_t &timePerMove)
{
    this->_timePerMove = timePerMove;
}

void Setting::addPlayerName(const std::string &name)
{
    this->_playerName.push_back(name);
}

void Setting::setCandle(const candle_t &candle)
{
    this->_candle = candle;
}

void Setting::setInitialStack(const size_t &initialStack)
{
    this->_initialStack = initialStack;
}

void Setting::setFeeTransaction(const float &fee)
{
    this->_fee_transaction = fee;
}

std::string Setting::getBotName()
{
    return (this->_botName);
}

size_t Setting::getTimebank()
{
    return (this->_timebank);
}

size_t Setting::getTimePerMove()
{
    return (this->_timePerMove);
}

std::vector<std::string> Setting::getPlayerName()
{
    return (this->_playerName);
}

candle_t Setting::getCandle()
{
    return (this->_candle);
}

size_t Setting::getInitialStack()
{
    return (this->_initialStack);
}

float Setting::getFeeTransaction()
{
    return (this->_fee_transaction);
}

/*
** Member fcn
*/