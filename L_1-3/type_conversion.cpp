#include <iostream>
#include <iomanip>

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

int main()
{
    unsigned int a = 1;
    double b = 3.6;
    int c = -1;

    // 0 - unsigned int, 1 - double, 2 - int
    data_t data;
    data.values[0] = &a;
    data.values[1] = &b;
    data.values[2] = &c;
    data.types[0] = 0;
    data.types[1] = 1;
    data.types[2] = 2;

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
