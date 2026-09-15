#ifndef MAX_UTILS_H
#define MAX_UTILS_H

#include <cstring>
#include <iostream>
#include <string>

template <typename T>
T max_value(T a, T b) {
    return (a > b) ? a : b;
}

template <>
inline const char* max_value<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}

template <typename T>
void print_value(const T& value) {
    std::cout << value << "\n";
}

template <>
inline void print_value<bool>(const bool& value) {
    std::cout << (value ? "так" : "ні") << "\n";
}

#endif
