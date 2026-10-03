#include <iostream>
using namespace std;
int main() {
    double T;
    double L;
    double D;
    double m;
    double g = 9.81;
    cout << "Введите тягу (T): ";
    cin >> T;
    cout << "Введите подъемную силу (L): ";
    cin >> L;
    cout << "Введите сопротивление (D): ";
    cin >> D;
    cout << "Введите массу самолета (m): ";
    cin >> m;
    double a = (L - m * g) / m;
    cout << "\nВертикальное ускорение: " << a << " м/с^2" << endl;
    if (a > 0.5) {
        cout << "Режим полета: НАБОР ВЫСОТЫ" << endl;
    } else if (a >= 0 && a <= 0.5) {
        cout << "Режим полета: ГОРИЗОНТАЛЬНЫЙ ПОЛЕТ" << endl;
    } else {
        cout << "Режим полета: СНИЖЕНИЕ" << endl;
    }
    return 0;
}
