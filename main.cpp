/*
** EPITECH PROJECT, 2019
** trade_2018
** File description:
** TODO: add description
*/

#include "MyBot.hpp"
#include "Error.hpp"

int main()
{
    try {
        MyBot bot = MyBot();
        bot.run();
    } catch (const Error &e) {
        if (INFO != e.getErrLevel()) {
            e.printMsg();
            return (e.getErrNum());
        }
    }
    return (0);
}