/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <map>
#include <list>
#include <string>

#ifndef TRADE_2018_CURRENCY_HPP
#define TRADE_2018_CURRENCY_HPP

/*
 * ENUM SECTION
 */

namespace currency {
    enum Type {
        USDT,   // crypto version of US Dollar
        BTC,    // Bitcoin
        ETH,    // Ether
        USDT_BTC,
        USDT_ETH,
        BTC_ETH
    };
}

/*
 * CLASS SECTION
 */

class Currency {
public:
    Currency(const currency::Type &type);
    ~Currency();

    /*
     * SETTER
     */

    void setType(const currency::Type &type);
    void setValue(const float &value);
    void setAction(const float &action);

    /*
     * GETTER
     */

    currency::Type getType();
    float getValue();
    float getAction();
    std::string getPairReadable();

private:
    currency::Type _type;
    float _value;
    float _action;
};

/*
 * DICTIONARY SECTION
 */

namespace Dictionary {
    static std::map<std::string, currency::Type> Currency {
            {"USDT", currency::USDT},
            {"BTC", currency::BTC},
            {"ETH", currency::ETH}
    };
    static std::map<std::string, currency::Type> Pair {
            {"USDT_BTC", currency::USDT_BTC},
            {"USDT_ETH", currency::USDT_ETH},
            {"BTC_ETH", currency::BTC_ETH}
    };
};

#endif //TRADE_2018_CURRENCY_HPP
