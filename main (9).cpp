#include <iostream>
#include <cmath>
using namespace std;

// Оголошення функцій
void task1();
void task2();
void task3();
void menu();

bool isValidDouble(double &value);
bool isValidInt(int &value, bool positiveOnly = false);

int main() {
    menu();
    return 0;
}

// Реалізація меню
void menu() {
    while (true) {
        cout << "\nОберіть завдання:\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "3 - Завдання 3\n";
        cout << "4 - Вихід\n";
        cout << "Ваш вибір: ";

        int choice;
        if (!isValidInt(choice)) {
            cout << "Помилка введення. Спробуйте знову.\n";
            continue;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                cout << "Вихід з програми.\n";
                return;
            default:
                cout << "Некоректний вибір. Спробуйте знову.\n";
        }
    }
}

// Завдання 1: Обчислити кількість точок у заданій області
void task1() {
    int n;
    float x, y, r; // Змінні для координат точки і радіуса
    cout << "*********** Point in geometry region 16 ********" << endl;
    cout << "Enter radius r: ";
    cin >> r;

    // Перевірка коректності введення радіуса
    if (!cin || r <= 0) {
        cout << "Radius must be a numeric, positive, non-zero value." << endl;
        return; // Завершення програми, якщо введено некоректне значення
    }

    // Запит координат точки
    cout << "Enter point coordinates (x, y): ";
    cin >> x >> y;

    // Перевірка, чи точка потрапляє в коло
    float distance = sqrt(x * x + y * y); // Відстань від точки (x, y) до центру (0, 0)

    if (distance <= r) {
        cout << "The point (" << x << ", " << y << ") is inside the circle." << endl;
    } else {
        cout << "The point (" << x << ", " << y << ") is outside the circle." << endl;
    }
}

// Завдання 2: Обчислити ряд та вивести непарні елементи
void task2() {
    double x;
    int n;

    // Введення даних
    cout << "Введіть значення x: ";
    cin >> x;
    cout << "Введіть натуральне число n: ";
    cin >> n;

    // Перевірка на коректність введених даних
    if (x <= 2 || x > 5 || n <= 0) {
        cout << "Некоректні значення x або n." << endl;
        return; // Завершення функції при некоректних значеннях
    }

    // Обчислення суми
    double sum = 0;
    for (int k = 0; k <= n; ++k) {
        sum += (k * (k + 1) - pow(x, k)) / pow(x, 2 * k + 1);
    }

    // Виведення результату
    cout << "Сума: " << sum << endl;

    if (n % 2 == 0) { // Якщо n парне
        cout << "Кожен третій елемент суми:" << endl;
        for (int k = 2; k <= n; k += 3) {
            double term = (k * (k + 1) - pow(x, k)) / pow(x, 2 * k + 1);
            cout << term << " ";
        }
    } else { // Якщо n непарне
        cout << "Кожен четвертий елемент суми:" << endl;
        for (int k = 3; k <= n; k += 4) {
            double term = (k * (k + 1) - pow(x, k)) / pow(x, 2 * k + 1);
            cout << term << " ";
        }
    }
    cout << endl;
}

// Завдання 3: Продемонструвати збіжність ряду
void task3() {
    double alpha, epsilon, g, sum = 0, prev_term = 1, term;
    int n = 1;

    // Введення даних
    cout << "Введіть значення alpha: ";
    cin >> alpha;
    cout << "Введіть значення epsilon: ";
    cin >> epsilon;
    cout << "Введіть значення g: ";
    cin >> g;

    // Цикл обчислення суми
    while (true) {
        term = exp(alpha) / pow(n, n / 2.0);
        sum += term;

        if (abs(term) < epsilon) {
            cout << "Ряд збігається. Сума: " << sum << endl;
            break;
        } else if (abs(term) > g) {
            cout << "Ряд розбігається." << endl;
            break;
        }

        
    }
}

// Функція перевірки на коректність введення дробових чисел
bool isValidDouble(double &value) {
    cin >> value;
    return cin.good();
}

// Функція перевірки на коректність введення цілих чисел
bool isValidInt(int &value, bool positiveOnly) {
    cin >> value;
    if (!cin.good()) return false;
    if (positiveOnly && value <= 0) return false;
    return true;
}
 