#ifndef DEVICE_FRIEND_H
#define DEVICE_FRIEND_H

#include "microphone.h"
#include "speaker.h"
#include <string>
#include <vector>

// Запис у каталозі (вектор структур)
struct catalog_item_t {
    std::string type;
    std::string model;
    int power;
    double price;
    std::string extra;
};

class DeviceFriend {
private:
    std::vector<catalog_item_t> items;

public:
    DeviceFriend();
    ~DeviceFriend();

    // введення даних у об'єкти (доступ до private через friend)
    void inputMicrophone(Microphone& mic, std::string model, int power,
                         double price, bool wireless, std::string pattern);
    void inputSpeaker(Speaker& sp, std::string model, int power,
                      double price, int diameter, int impedance);

    void inputMicrophoneFromKeyboard(Microphone& mic);
    void inputSpeakerFromKeyboard(Speaker& sp);

    // виведення даних (читає private-поля напряму)
    void printMicrophone(Microphone& mic) const;
    void printSpeaker(Speaker& sp) const;
    void printBase(SoundDevice& device) const;

    // додавання знімка даних у вектор структур
    void addToCatalog(Microphone& mic);
    void addToCatalog(Speaker& sp);

    void displayCatalog() const;
    double totalPrice() const;
    int count() const;
    double maxPrice() const;
};

#endif
