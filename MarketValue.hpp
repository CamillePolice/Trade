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
        void setLow(const float &low);
        void setHigh(const float &high);
        void setOpen(const float &open);
        void setClose(const float &close);
        void setVolume(const float &volume);

        currency::Type getPair();
        time_t getDate();
        float getLow();
        float getHigh();
        float getOpen();
        float getClose();
        float getVolume();

private:
        currency::Type _pair;
        std::time_t _date;
        float _low;
        float _high;
        float _open;
        float _close;
        float _volume;
    };


#endif //TRADE_2018_MARKETVALUE_HPP
