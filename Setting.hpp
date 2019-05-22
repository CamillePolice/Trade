/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include <map>
#include <list>
#include <vector>
#include <string>

#ifndef TRADE_2018_SETTING_HPP
#define TRADE_2018_SETTING_HPP

#define SETTING_TIMEBANK_PATTERN "^settings( +)timebank( +)(.*)"
#define SETTING_TIMEPERMOVE_PATTERN "^settings( +)time_per_move( +)(.*)"
#define SETTING_PLAYERNAMES_PATTERN "^settings( +)player_names( +)(.*)"
#define SETTING_YOURBOT_PATTERN "^settings( +)your_bot( +)(.*)"
#define SETTING_CANDLEINTERVAL_PATTERN "^settings( +)candle_interval( +)(.*)"
#define SETTING_CANDLETOTAL_PATTERN "^settings( +)candles_total( +)(.*)"
#define SETTING_CANDLESGIVEN_PATTERN "^settings( +)candles_given( +)(.*)"
#define SETTING_CANDLEFORMAT_PATTERN "^settings( +)candle_format( +)(.*)"
#define SETTING_INITIALSTACK_PATTERN "^settings( +)initial_stack( +)(.*)"
#define SETTING_FEE_TRANSACTION_PATTERN "^settings( +)transaction_fee_percent( +)(.*)"

#define DEFAULT_PLAYERNAME "player"

namespace candle {
    enum Format {
        pair,
        date,
        high,
        low,
        open,
        close,
        volume
    };
};

typedef struct s_candle {
    size_t _interval;
    size_t _total;
    size_t _given;
    std::list<candle::Format> _format;
}candle_t;

class Setting {
    public:
        Setting();
        ~Setting();

        /*
         * SETTER
         */

        void setTimebank(const size_t &timebank);
        void setTimePerMove(const size_t &timePerMove);
        void addPlayerName(const std::string &name);
        void setBotName(const std::string &botName);
        void setCandle(const candle_t &candle);
        void setInitialStack(const size_t &initialStack);
        void setFeeTransaction(const float &fee);

        /*
         * GETTER
         */

        size_t getTimebank();
        size_t getTimePerMove();
        std::vector<std::string> getPlayerName();
        std::string getBotName();
        candle_t getCandle();
        size_t getInitialStack();
        float getFeeTransaction();

    protected:
        size_t _timebank;
        size_t _timePerMove;
        std::vector<std::string> _playerName;
        std::string _botName;
        candle_t _candle;
        size_t _initialStack;
        float _fee_transaction;
};

namespace Dictionary {
    static std::map<std::string, candle::Format> candleFormat = {
            {"pair", candle::pair},
            {"date", candle::date},
            {"high", candle::high},
            {"low", candle::low},
            {"open", candle::open},
            {"close", candle::close},
            {"volume", candle::volume}
    };
}

#endif //TRADE_2018_SETTING_HPP