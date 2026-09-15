#ifndef PAIR_BOX_H
#define PAIR_BOX_H

#include <iostream>
#include <string>
#include <typeinfo>
#include "signaling.h"

template <typename T1, typename T2>
class PairBox {
private:
    T1 first;
    T2 second;

public:
    PairBox(const T1& a, const T2& b) : first(a), second(b) {}
    ~PairBox() {}

    T1 get_first() const { return first; }
    T2 get_second() const { return second; }

    void print_pair() const {
        std::cout << "[PairBox<" << typeid(T1).name() << ", "
                  << typeid(T2).name() << ">]\n";
        std::cout << "  first:  " << first << "\n";
        std::cout << "  second: " << second << "\n";
    }
};

template <typename T>
class PairBox<T, T> {
private:
    T first;
    T second;

public:
    PairBox(const T& a, const T& b) : first(a), second(b) {}
    ~PairBox() {}

    T get_first() const { return first; }
    T get_second() const { return second; }

    void print_pair() const {
        std::cout << "[PairBox<T, T> partial] обидва елементи одного типу\n";
        std::cout << "  first:  " << first << "\n";
        std::cout << "  second: " << second << "\n";
        std::cout << "  більший: " << ((first > second) ? first : second) << "\n";
    }
};

template <>
class PairBox<bool, std::string> {
private:
    bool hasWireless;
    std::string alertMethod;

public:
    PairBox(bool wireless, const std::string& method)
        : hasWireless(wireless), alertMethod(method) {}
    ~PairBox() {}

    bool get_first() const { return hasWireless; }
    std::string get_second() const { return alertMethod; }

    void print_pair() const {
        std::cout << "[PairBox<bool, string> full] поля сигналізації\n";
        std::cout << "  бездротові: " << (hasWireless ? "так" : "ні") << "\n";
        std::cout << "  оповіщення: " << alertMethod << "\n";
    }
};

#endif
