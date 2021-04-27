//
//  main.cpp
//  vasilenko_cpp_lab_2
//
//  Created by Evgeny Wisealienko on 27.04.2021.
//  данная программа считает сумму ряда вида: 1 - x^2 / 3! + x^4 / 5! - ... для введённого x для elements_count элементов последовательности

#include <iostream>
#include <cmath>
#define elements_count 200
using namespace std;

double get_digit();
double calculate_series_sum(const double x);

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "Введите число x: ";
    const double x = get_digit();
    
    const double series_sum = calculate_series_sum(x);

    cout << "сумма " << elements_count << " элементов ряда для указанного числа x: " << series_sum << "\n";

    return 0;
}


double calculate_series_sum(const double x)
{
    double summand = 1;
    double series_sum = 0;
    int d = 1;
    for (int i = 0; i < elements_count; i++) {
        series_sum += summand;
        d += 2;
        summand *= -1 * x * x / d / (d - 1);
    }
    return series_sum;
}

double get_digit()
{
    while (true)
    {
        double digit;
        cin >> digit;
        if (cin.fail())
        {
            cout << "Не число\n";
            cout << "Введите число х: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return digit;
        }
    }
}

