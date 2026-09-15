#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <iostream>
#include <typeinfo>

template <typename T>
class Repository {
private:
    T m_value;

public:
    explicit Repository(const T& value) : m_value(value) {}
    ~Repository() {}

    T get() const { return m_value; }

    void print() const {
        std::cout << "[Repository<" << typeid(T).name() << ">] "
                  << m_value << "\n";
    }
};

template <typename T>
class Repository<T*> {
private:
    T* m_value;

public:
    explicit Repository(T* value) : m_value(value) {}
    ~Repository() {}

    T* get() const { return m_value; }

    void print() const {
        std::cout << "[Repository<T*> partial] адреса=" << m_value;
        if (m_value != nullptr) {
            std::cout << ", значення=" << *m_value;
        }
        std::cout << "\n";
    }
};

template <>
class Repository<bool> {
private:
    bool m_value;

public:
    explicit Repository(bool value) : m_value(value) {}
    ~Repository() {}

    bool get() const { return m_value; }

    void print() const {
        std::cout << "[Repository<bool> full] бездротові сенсори: "
                  << (m_value ? "є" : "немає") << "\n";
    }
};

#endif
