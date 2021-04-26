//
//  main.cpp
//  vasilenko_cpp_lab_1
//
//  Created by Evgeny Wisealienko on 26.04.2021.
//

#include <iostream>
using namespace std;

double get_number();
double get_not_negative_number();

int main()
{
    setlocale(LC_ALL, "rus");

    cout << " Скорость лодки (км/ч): ";
    double boat_speed = get_not_negative_number();

    cout << " Расстояние между пунктами A и B (км): ";
    double distance = get_not_negative_number();
    
    cout << " Скорость течения реки (км/ч): ";
    double flow_speed = get_not_negative_number();

    cout << "Результат вычислений:\n";
    
    if ((boat_speed == 0) && (flow_speed == 0)) {
        cout << " Лодка стоит на месте ";
    } else {
        if (flow_speed > boat_speed) {
            cout << " К сожалению, Ваша лодка не справляется с течением реки ";
        }
        else {
            if (flow_speed == boat_speed) {
                cout << " К сожалению, Ваша лодка справляясь с течением реки стоит на месте ";
            }
            else {
                const double time_with_flow = distance / (boat_speed + flow_speed);
                const double time_against_flow = distance / (boat_speed - flow_speed);
                const double total_time = time_with_flow + time_against_flow;
                
                int time_mins = (int)floor( total_time * 60.0 );
                int hours = time_mins / 60;
                int minutes = time_mins % 60;
                
                cout << " Общее время Вашей лодки в пути: " << hours << " час(а/ов) " << minutes << " минут(ы)\n";
                cout << " Для провекри, также указано время в пути в десятичном отображении: " << total_time << "\n";
                 }
        }
    }
    return 0;
}

double get_number()
{
    while (true)
    {
        double number;
        cin >> number;
        if (cin.fail())
        {
            cout << "Ошибка, введите число\n";
            cout << "Повторите ввод: ";
            cin.clear();
            cin.ignore(32767, '\n');
        }
        else {
            cin.ignore(32767, '\n');
            return number;
        }
    }
}

double get_not_negative_number()
{
    while (true)
    {
        double not_neg_num = get_number();
        if (not_neg_num < 0) {
            cout << "Извините, но число не может быть отрицательным\n";
            cout << "Повторите ввод: ";
        }
        else {
            return not_neg_num;
        }
    }
}
    
