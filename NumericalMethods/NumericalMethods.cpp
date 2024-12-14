
#include <iostream>
#include <cmath>

using namespace std;

const int ITERATIONS = 10000;
const double TARGET_VALUE = pow(0.2, 3); 
const double PI = 3.14159265358979323846;
const double EPSILON = 1e-8;

// У МЕНЯ ВТОРОЙ ВАРИАНТ // 


//метод простых итераций

double g(double x) {
    return x - (x - 10 * sin(x)) / 11.0;
}

void simpleIteration(double initialGuess) {
    double x = initialGuess;
    for (int i = 0; i < ITERATIONS; ++i) {
        double x_new = g(x);

        if (fabs(x_new - x) < EPSILON) {
            cout << "Приближенное значение x: " << x_new << " радиан" << endl;
            return;
        }
        x = x_new;
    }
    cout << "Метод не сошелся за " << ITERATIONS << " итераций." << endl;
}


//метод половинного деления


double f(double x) {
    return x - 10 * sin(x);
}

void bisectionMethod(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Функция не меняет знак на данном интервале." << endl;
        return;
    }
    double c;
    for (int i = 0; i < ITERATIONS; i++) {
        c = (a + b) / 2;
        if (fabs(f(c)) < EPSILON) {
            break;
        }
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        if (fabs(b - a) < EPSILON) {
            break;
        }
    }
    cout << "Приближенное значение x: " << c << " радиан" << endl;
}

int main()
{
    setlocale(LC_ALL, "rus");
    double a = -10.0;
    double b = 20.0;

    cout << "\n\n";
    cout << "метод простых итераций" << endl;
    double initialGuess = 8.0;
    simpleIteration(initialGuess);


    cout << "\n\n";
    cout << "метод половиного деления. " << endl;
    bisectionMethod(a, b);

    return 0;
}