/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <iostream>
#include "Update.hpp"
#include "Currency.hpp"
#include "Error.hpp"

/*
** CTOR & DTOR
*/

Update::Update()
{
    Currency currencyBTC = Currency(currency::BTC);
    Currency currencyETH = Currency(currency::ETH);
    Currency currencyUSDT = Currency(currency::USDT);
    std::list<MarketValue> mvList = {};

    this->_marketValue[currency::USDT_ETH] = mvList;
    this->_marketValue[currency::BTC_ETH] = mvList;
    this->_marketValue[currency::USDT_BTC] = mvList;
    this->_stack.push_back(currencyBTC);
    this->_stack.push_back(currencyETH);
    this->_stack.push_back(currencyUSDT);
}

Update::~Update()
{
    this->_marketValue.clear();
    this->_stack.clear();
}

/*
** Getter & Setter
*/

void Update::setStackByInput(std::list<std::string> &input)
{
    auto in = input.begin();
    std::string type = *in;
    in++;
    if (2 == input.size()) {
        for (auto & it : this->_stack) {
            if (Dictionary::Currency[type] == it.getType()) {
                float value = std::stof(*in);
                it.setValue(value);
                return;
            }
        }
    }
    throw Error(DEFAULT, "update : stacks : bad input", MAJOR);
}

void Update::setNextCandleByInput(std::list<std::string> &input)
{
    auto it = input.begin();
    MarketValue mv;
    if (7 == input.size()) {
        mv.setPair(Dictionary::Pair[*it]);
        it++;
        mv.setDate(std::stoi(*it));
        it++;
        mv.setHigh(std::stof(*it));
        it++;
        mv.setLow(std::stof(*it));
        it++;
        mv.setOpen(std::stof(*it));
        it++;
        mv.setClose(std::stof(*it));
        it++;
        mv.setVolume(std::stof(*it));
    } else {
        throw Error(DEFAULT, "update : next candle : bad input", MAJOR);
    }
    this->_marketValue[mv.getPair()].push_back(mv);
}

std::list<Currency> Update::getStack()
{
    return (this->_stack);
}

std::map<currency::Type, std::list<MarketValue>> Update::getCandleList()
{
    return (this->_marketValue);
}


/*
** Member fcn
*/
void Update::affMarketValueList() {

    for (auto & it : this->_marketValue) {
        std::cout << "Currency > " << it.first << std::endl;
        std::cout << "Value : " << std::endl;
        for (auto &it1 : it.second) {
            std::cout << "\tClose " << it1.getClose() << std::endl;
            std::cout << "\tDate " << it1.getDate() << std::endl;
            std::cout << "\tPair " << it1.getPair() << std::endl;
        }
    }
}
