#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

const int SIZE = 3;

struct data_t {
    void* values[SIZE];
    int types[SIZE];
};

void print_data(struct data_t* data_ptr)
{
    for (int i = 0; i < SIZE; i++) {
        if (data_ptr->types[i] == 0)
            cout << "a = " << *(unsigned int*)data_ptr->values[i] << endl;
        else if (data_ptr->types[i] == 1)
            cout << "b = " << *(double*)data_ptr->values[i] << endl;
        else if (data_ptr->types[i] == 2)
            cout << "c = " << *(int*)data_ptr->values[i] << endl;
    }
}

void input_data(unsigned int& a, double& b, int& c)
{
    while (true) {
        cout << "Введіть a (unsigned int, >= 0): ";
        if (cin >> a) {
            break;
        }
        cout << "Помилка: некоректне значення для a!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Введіть b (double): ";
        if (cin >> b) {
            break;
        }
        cout << "Помилка: некоректне значення для b!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    while (true) {
        cout << "Введіть c (int): ";
        if (cin >> c) {
            break;
        }
        cout << "Помилка: некоректне значення для c!\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main()
{
    unsigned int a = 1;
    double b = 3.6;
    int c = -1;

    cout << "=== Лаб. №1-3: введення даних структури з клавіатури ===\n";
    input_data(a, b, c);

    // 0 - unsigned int, 1 - double, 2 - int
    data_t data;
    data.values[0] = &a;
    data.values[1] = &b;
    data.values[2] = &c;
    data.types[0] = 0;
    data.types[1] = 1;
    data.types[2] = 2;

    cout << "\nВведені дані:\n";
    print_data(&data);

    // (a < c ? a : c) * b
    double implicit_result = (a < c ? a : c) * b;

    double explicit_result =
        (static_cast<int>(a) < c ? static_cast<double>(a) : static_cast<double>(c)) * b;

    cout << fixed << setprecision(3);
    cout << "implicit_result = " << implicit_result << endl;
    cout << "explicit_result = " << explicit_result << endl;

    return 0;
}
