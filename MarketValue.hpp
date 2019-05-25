/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <ctime>
#include "Currency.hpp"

#ifndef TRADE_2018_MARKETVALUE_HPP
#define TRADE_2018_MARKETVALUE_HPP


class MarketValue {
    public:
        MarketValue();
        ~MarketValue();

        void setPair(const currency::Type &pair);
        void setDate(const time_t &date);
        void setLow(const double &low);
        void setHigh(const double &high);
        void setOpen(const double &open);
        void setClose(const double &close);
        void setVolume(const double &volume);

        currency::Type getPair();
        std::string getPairReadable();
        time_t getDate();
        double getLow();
        double getHigh();
        double getOpen();
        double getClose();
        double getVolume();

private:
        currency::Type _pair;
        std::time_t _date;
        double _low;
        double _high;
        double _open;
        double _close;
        double _volume;
    };


#endif //TRADE_2018_MARKETVALUE_HPP
