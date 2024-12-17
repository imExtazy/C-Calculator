#include <iostream>
#include <cmath>
#include <limits>

using namespace std;

double get_float_input(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Проверка на некорректный ввод (если введен не числовой тип)
        if (cin.fail()) {
            cin.clear(); // Очищаем флаги ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Игнорируем некорректный ввод
            cout << "Некорректный ввод, попробуйте еще раз." << endl;
        } else {
            break;
        }
    }
    return value;
}

void find_roots(double a, double b, double c) {
    double D = b * b - 4.0 * a * c; // Дискриминант

    if (D < 0) {
        cout << "Нет действительных корней." << endl;
    } else if (D == 0) {
        double root = -b / (2.0 * a);
        cout << "Один корень: " << root << endl;
    } else {
        double root1 = (-b + sqrt(D)) / (2 * a);
        double root2 = (-b - sqrt(D)) / (2 * a);
        cout << "Два корня: " << root1 << " и " << root2 << endl;
    }
}

int main() {
    double a = get_float_input("Введите коэффициент A: ");
    double b = get_float_input("Введите коэффициент B: ");
    double c = get_float_input("Введите коэффициент C: ");

    find_roots(a, b, c);

    return 0;
}