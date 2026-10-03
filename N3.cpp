#include <iostream>
using namespace std;
int main() {
    float m;
    cout << "Введите массу самолета m: ";
    cin >> m;
    float L;
    cout << "Введите подъёмную силу L: ";
    cin >> L;
    float D;
    cout << "Введите сопротивление D: ";
    cin >> D;
    float T;
    cout << "Введите тягу двигателя T: ";
    cin >> T;
    float g = 9.81;
    float a = (T-D)/m;
    float ay = (L-m*g)/m;
    cout <<"Ускорение по курсу движения a = (T-D)/m=" << a << endl;
    cout <<"Вертикальное ускорение ay = (L-mg)/m=" << ay << endl;
    return 0;
}
