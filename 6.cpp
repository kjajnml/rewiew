#include <iostream>
#include <vector>

using namespace std;
bool is_same_sign(const vector<double>& arr) {
    if (arr.empty()) return false;
    int sign;
    if (arr[0] > 0) sign = 1;
    else if (arr[0] < 0) sign = -1;
    else return false;

    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] == 0) continue;

        if (arr[i] > 0 && sign != 1) return false;
        if (arr[i] < 0 && sign != -1) return false;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "Russian");
    vector<vector<double>> arrays(5);
    for (int i = 0; i < 5; i++) {
        int size;
        cout << "Введите размер массива " << i + 1 << " (1..100): ";
        cin >> size;
        while (size < 1 || size > 100) {
            cout << "Размер должен быть от 1 до 100. Повторите: ";
            cin >> size;
        }

        arrays[i].resize(size);
        cout << "Введите " << size << " элементов массива " << i + 1 << ": ";
        for (int j = 0; j < size; j++) {
            cin >> arrays[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Массив " << i + 1 << ": ";
        for (double x : arrays[i]) cout << x << " ";
        cout << endl;
    }
    cout << endl;

    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (is_same_sign(arrays[i])) {
            cout << "Массив " << i + 1 << " состоит из элементов одного знака." << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Отрицательный ответ: массивов, состоящих из элементов одного знака, нет." << endl;
    }

    return 0;
}