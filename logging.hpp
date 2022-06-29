//
// Created by IT-Unterrichtsraum on 01.06.2022.
//
#ifndef UNTITLED2_LOGGING_H
#define UNTITLED2_LOGGING_H

#include <iostream>
#include "fstream"
#include "cstdarg"
#include <utility>  // std::forward
#include <ctime>
#include <iomanip>

using namespace std;
ofstream output;
template<typename T, typename... Ts>
constexpr void print_raw(T &&first, Ts &&... rest) noexcept
{


    if constexpr (sizeof...(Ts) == 0)
    {
        std::cout << first;               // for only 1-arguments
        output << first;
    }
    else
    {
        std::cout << first << " ";        // print the 1 argument
        output << first << " ";
        print_raw(std::forward<Ts>(rest)...); // pass the rest further
    }
};
template<typename T, typename... Ts>
constexpr void printf(T &&first, Ts &&... rest) noexcept
{
    std::time_t now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    cout << std::put_time(&tm, "[%Y-%m-%d|%H:%M:%S]: ");
    output << std::put_time(&tm, "[%Y-%m-%d|%H:%M:%S]: ");

    if constexpr (sizeof...(Ts) == 0)
    {
        std::cout << first;               // for only 1-arguments
        output << first;
    }
    else {
        print_raw(first);
        cout << " ";
        output << " ";
        print_raw(std::forward<Ts>(rest)...);
        }
    cout << "\n";
    output << "\n";
};
template<typename T, typename... Ts>
constexpr void print(T &&first, Ts &&... rest) noexcept
{
    std::time_t now = std::time(nullptr);
    auto tm = *std::localtime(&now);
    cout << std::put_time(&tm, "[%Y-%m-%d|%H:%M:%S]: ");
    output << std::put_time(&tm, "[%Y-%m-%d|%H:%M:%S]: ");
    if constexpr (sizeof...(Ts) == 0)
    {
        std::cout << first;               // for only 1-arguments
        output << first;
    }
    else {
        print_raw(first);
        cout << " ";
        output << " ";
        print_raw(std::forward<Ts>(rest)...);
    }
};
#endif //UNTITLED2_LOGGING_H
