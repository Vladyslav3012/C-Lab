#include <iostream>
#include <limits>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};

    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;

    string phrase;
    while (true) {
        cout << "Введіть фразу (можна кілька слів): ";
        getline(cin, phrase);
        if (!phrase.empty()) {
            break;
        }
        cout << "Помилка: рядок не може бути порожнім!\n";
    }
    cout << "Ви ввели: " << phrase << endl;

    return 0;
}
