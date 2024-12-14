
#include <iostream>
#include <cmath>
using namespace std;

// Константы
const double EPSILON = 1e-8;


//// Комбинированный метод
double f(double x) {
    return cos(x) + 0.3 * x;
}

double f_prime(double x) {
    return -sin(x) + 0.3;
}

double combinedMethod(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Функция не изменяет знак на отрезке [" << a << ", " << b << "]\n";
        return NAN;
    }
    double x0 = a;
    double x1 = b;
    double x_next;


    while (true) {
        x_next = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));

        if (fabs(f(x_next)) < EPSILON || fabs(x_next - x1) < EPSILON) {
            break;
        }

        x0 = x1;
        x1 = x_next;
    }
    double x_refined = x_next;

    while (true) {
        double derivative = f_prime(x_refined);
        if (fabs(derivative) < EPSILON) {
            cout << "Производная слишком мала, решить уравнение не удалось.\n";
            return NAN;
        }
        double x_new = x_refined - f(x_refined) / derivative;

        if (fabs(f(x_new)) < EPSILON || fabs(x_new - x_refined) < EPSILON) {
            return x_new;
        }
        x_refined = x_new;
    }
}


//// метод касательных
void tangentMethod(double x0) {
    double x_next;

    while (true) {

        double derivative = f_prime(x0);
        if (fabs(derivative) < EPSILON) {
            cout << "Производная слишком мала, решить уравнение не удалось.\n";
            return;
        }

        x_next = x0 - f(x0) / derivative;

        if (fabs(f(x_next)) < EPSILON || fabs(x_next - x0) < EPSILON) {
            cout << "Приближенное значение x: " << x_next << "\n";
            return;
        }

        x0 = x_next;
    }
}

//// метод хорд
void chordMethod(double a, double b) {
    if (f(a) * f(b) >= 0) {
        cout << "Функция не изменяет знак на отрезке [" << a << ", " << b << "]\n";
        return;
    }
    double x0 = a;
    double x1 = b;
    double x_next;
    while (true) {
        x_next = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        if (fabs(f(x_next)) < EPSILON || fabs(x_next - x1) < EPSILON) {
            cout << "Приближенное значение x: " << x_next << " на отрезке ["
                << a << ", " << b << "]\n";
            return;
        }
        x0 = x1;
        x1 = x_next;
    }
}

int main()
{
	setlocale(LC_ALL, "rus");

    //// это комбинированный метод 
    double a = 2.8;
    double b = 3.5;
    double result = combinedMethod(a, b);
    if (!isnan(result)) {
        cout << "Приближенное значение x: " << result << " радиан" << endl;
    }
    else {
        cout << "Метод не сошелся." << endl;
    }

    //// это метод касательных 
    double x = 1.6;
    double g = 1.7;
    double initialGuess = (x + g) / 2; // Начальное приближение
    tangentMethod(initialGuess);


    //// это метод хорд 
    double q = 1.8;
    double e = 2.5;
    chordMethod(q, e);

    return 0;
}

