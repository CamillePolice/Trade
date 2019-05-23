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
        this->_setting.setTimebank((size_t)std::stof(tmp));
        return (true);
    }
    pattern = (SETTING_TIMEPERMOVE_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setTimePerMove((size_t)std::stof(tmp));
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
        candle._interval = ((size_t)std::stof(tmp));
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_CANDLETOTAL_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle._total = ((size_t)std::stof(tmp));
        this->_setting.setCandle(candle);
        return (true);
    }
    pattern = (SETTING_CANDLESGIVEN_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        candle._given = ((size_t)std::stof(tmp));
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
        this->_setting.setInitialStack((size_t)std::stof(tmp));
        return (true);
    }
    pattern = (SETTING_FEE_TRANSACTION_PATTERN);
    if (std::regex_search(this->_input, m, pattern)) {
        auto it = m.end() - 1;
        std::string tmp = *it;
        this->_setting.setInitialStack((size_t)std::stof(tmp));
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
    for (auto it = haystackList.begin() ; it != haystackList.end() ; it++) {
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
        this->_action.setOrder((size_t)std::stof(tmp));
        this->trade();
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
    // strategies of purchase based on 1 superior standard deviation
    float value = this->_average + this->_standardDeviation;
    float close = marketValue.back().getClose();
        if (close > value) {
        this->_action.buy(this->_update.getStack(), marketValue.back());
    }
}

void MyBot::sell(std::list<MarketValue> marketValue) {
    // strategies of purchase based on 1 inferior standard deviation
    float value = this->_average - this->_standardDeviation;
    float close = marketValue.back().getClose();

    if (close < value) {
        this->_action.sell(this->_update.getStack(), marketValue.back());
    }
}

void MyBot::close()
{
    // Sell ETH BTC TO MAKE MONEY!!!
    for (auto &it : this->_update.getCandleList()) {
        this->_action.sell(this->_update.getStack(), it.second.back());
    }
}

void MyBot::printOutput()
{
    int counter = 0;
    int size = (int)this->_action.getOutput().size();

    for (auto &it : this->_action.getOutput()) {
        std::cout << it;
        if (counter < size - 1) {
            std::cout << ";";
        }
        counter++;
    }
    std::cout << std::endl;
}

void MyBot::trade()
{
    // check the last day before closure
    if (1 == this->_setting.getCandle()._total) {
        this->close();
    } else {
        // check for good deals for each market places
        for (auto & it : this->_update.getCandleList()) {
            this->calculateAverage(it.second);
            this->calculateStandardDeviation(it.second);
            this->sell(it.second);
            this->buy(it.second);
        }
    }
    // by default pass
    if (this->_action.getOutput().empty()) {
        this->_action.pass();
    }

    this->printOutput();
    this->_action.clearOutput();
}

void MyBot::calculateAverage(std::list<MarketValue> list) {

    float total = 0.0;
    float average;

    for (auto & it : list) {
        total += it.getClose();
    }
    average = total / list.size();
    this->_average = average;
}

/*
 * Variance = moyenne (vi2) - moy2
 */
void MyBot::calculateVariance(std::list<MarketValue> list) {
    float total = 0.0;
    float variance;

    for (auto & it : list) {
        total = total + (it.getClose() * it.getClose());
    }
    variance = total / list.size() - (this->_average * this->_average);
    this->_variance = variance;
}

/*
 * Square root of the variance
 */
void MyBot::calculateStandardDeviation(std::list<MarketValue> list)
{
    this->calculateVariance(list);
    float standardDeviation = sqrt(this->_variance);
    this->_standardDeviation = standardDeviation;
}
