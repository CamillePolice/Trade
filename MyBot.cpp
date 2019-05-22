/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "MyBot.hpp"
#include "Currency.hpp"
#include "Setting.hpp"
#include "Update.hpp"
#include "Action.hpp"
#include "Error.hpp"

/*
** CTOR & DTOR
*/

MyBot::MyBot()
{
}

MyBot::~MyBot()
{
}

/*
** Getter & Setter
*/

/*
** Member fcn
*/

void MyBot::run()
{
    std::string in;
    while (std::getline(std::cin, this->_input)) {
        if (QUIT == this->_input) {
            return;
        }
        if (!this->saveInput()) {
            throw Error(DEFAULT, "bad input", MAJOR);
        }
    }
}
/*
 * INPUT SECTION
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

bool MyBot::isSetting()
{
    std::smatch m;
    std::regex pattern { SETTING_TIMEBANK_PATTERN };
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setTimebank((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        return (true);
    }
    pattern = (SETTING_TIMEPERMOVE_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setTimePerMove((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        return (true);
    }
    pattern = (SETTING_PLAYERNAMES_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.addPlayerName(*it);
        return (true);
    }
    pattern = (SETTING_YOURBOT_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setBotName(*it);
        return (true);
    }
    candle_t candle = this->_setting.getCandle();
    pattern = (SETTING_CANDLEINTERVAL_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle_t candle = this->_setting.getCandle();
        candle._interval = ((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_CANDLETOTAL_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle._total = ((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_CANDLESGIVEN_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle._given = ((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_CANDLEFORMAT_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        std::list<std::string> candleFormatList = split(tmp, ',');
        for (auto it = candleFormatList.begin() ; it != candleFormatList.end() ; it++) {
            candle._format.push_back(Dictionary::candleFormat[*it]);
        }
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_INITIALSTACK_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setInitialStack(((size_t)std::strtol(tmp.c_str(), nullptr, 10)));
        return (true);
    }
    pattern = (SETTING_FEE_TRANSACTION_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setInitialStack(((size_t)std::strtol(tmp.c_str(), nullptr, 10)));
        return (true);
    }
    return (false);
}

bool MyBot::isUpdate()
{
    std::smatch m;
    std::regex pattern { UPDATE_NEXTCANDLE_PATTERN };
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        return (this->setNextCandle(tmp));
    }
    pattern = ( UPDATE_STACKS_PATTERN );
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        return (this->setStack(tmp));
    }
    return (false);
}

bool MyBot::setNextCandle(std::string haystack)
{
    std::list<std::string> haystackList = split(haystack, ';');

    if (haystackList.empty()) {
        return (false);
    }
    for (auto it  = haystackList.begin() ; it != haystackList.end() ; it++) {
        std::list<std::string> needleList = split(*it, ',');
        try {
            this->_update.setNextCandleByInput(needleList);
        } catch (const Error &e) {
            if (MAJOR == e.getErrLevel()) {
                e.printMsg();
                return (false);
            }
        }
    }
    return (true);
}

bool MyBot::setStack(const std::string& haystack)
{
    std::list<std::string> haystackList = split(haystack, ',');

    if (haystackList.empty()) {
        return (false);
    }
    for (auto it = haystackList.begin() ; it != haystackList.end() ; it++) {
        std::string needle = it->c_str();
        std::list<std::string> needleList = split(needle, ':');
        try {
            this->_update.setStackByInput(needleList);
        } catch (const Error &e) {
            if (MAJOR == e.getErrLevel()) {
                e.printMsg();
                return (false);
            }
        }
    }
    return (true);
}

bool MyBot::isAction()
{
    std::smatch m;
    std::regex pattern { ACTION_ORDER_PATTERN };
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle_t candle = this->_setting.getCandle();
        candle._total -= 1;
        this->_setting.setCandle(candle);
        this->_action.setOrder((size_t)std::strtol(tmp.c_str(), nullptr, 10));
        if (this->_setting.getCandle()._total <= this->_setting.getCandle()._given) {
            this->trade();
        }
        return (true);
    }
    return (false);
}

bool MyBot::saveInput()
{
    if (this->isSetting()) {
        return (true);
    } else if (this->isUpdate()) {
        return (true);
    }
    return (this->isAction());
}

/*
 * ALGORITHM SECTION
 */
void MyBot::buy(std::list<MarketValue> marketValue) {
    // Si candle.close > average + stardardDeviation
    if (marketValue.back().getClose() > this->average(marketValue) + this->standardDeviation(marketValue)) {
        // Affichage + on achète acheter
        //this->_action.buy();
    }
}

void MyBot::sell(std::list<MarketValue> marketValue) {
    // Si candle.close < average - stardardDeviation
    if (marketValue.back().getClose() < this->average(marketValue) - this->standardDeviation(marketValue)) {
        // Affichage + on vend
        //this->_action.sell();
    }
}

void MyBot::pass() {
    this->_action.pass();
}

void MyBot::trade()
{
    // Le dernier jour on vend tout pour n'avoir que des dollars
    if (1 == this->_setting.getCandle()._total) {
        //this->_action.sell(this->_update.getStack());
        this->_setting.setInitialStack(0);
    }
    // On fait l'algo sur les 3 devises sur lesquelles on doit trader
    for (auto & it : this->_update.getCandleList()) {
        this->sell(it.second);
        this->buy(it.second);
        // Si on a pas acheté ou vendu, on passe
        if (this->_action.getOutput().empty())
            this->pass();
        else {
            // Affichage pour le bot
            int i = 0;
            auto itOutput = this->_action.getOutput().begin();
            for (; itOutput != this->_action.getOutput().end() ; itOutput++) {
                if (i > (int)this->_action.getOutput().size() - 1)
                    break;
                std::cout << *itOutput + ";";
            }
            std::cout << *itOutput << std::endl;
        }
    }
}

// On fait la moyenne || la variance || l'écart-type sur la valeur close des candle
double MyBot::average(std::list<MarketValue> list) {

    float total = 0.0;

    for (auto & it : list) {
        total += it.getClose();
    }
    return (total / list.size());
}

/*
 * variance : (values sum + (currentValue²)) / total - average²
 */
double MyBot::variance(std::list<MarketValue> list) {
    float total = 0.0;

    for (auto & it : list) {
        total = total + (it.getClose() * it.getClose());
    }
    return (total / list.size() - (this->average(list) * this->average(list)));
}

/*
 * Square root of the variance
 */
double MyBot::standardDeviation(std::list<MarketValue> list)
{
    return sqrt(this->variance(list));
}
