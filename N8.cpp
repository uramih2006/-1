#include <iostream>
#include <cmath>
using namespace std;
struct Aircraft {
    double m;
    double T;
    double Cl;
    double Cd;
    double ay;
    double t;
};
int main() {
  double g = 9.81;
  double rho = 1.225;
  double V = 100.0;
  double S = 20.0;
  double h = 1000.0;
 int N = 3;
    Aircraft planes[N];
    for (int i = 0; i < N; i++) {
        cout << "Самолет " << (i + 1) << ":" << endl;
        cout << "Введите массу (m): ";
        cin >> planes[i].m;
        cout << "Введите тягу (T): ";
        cin >> planes[i].T;
        cout << "Введите Cl: ";
        cin >> planes[i].Cl;
        cout << "Введите Cd: ";
        cin >> planes[i].Cd;
    }
    for (int i = 0; i < N; i++) {
        double L = 0.5 * rho * V * V * S * planes[i].Cl;
        double D = 0.5 * rho * V * V * S * planes[i].Cd;
        planes[i].ay = (L - planes[i].m * g) / planes[i].m;
        if (planes[i].ay > 0) {
            planes[i].t = sqrt(2 * h / planes[i].ay);
        } else {
            planes[i].t = 1e9;
        }
    }
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (planes[j].t > planes[j + 1].t) {
                Aircraft temp = planes[j];
                planes[j] = planes[j + 1];
                planes[j + 1] = temp;
            }
        }
    }
    cout << "\nРезультаты :" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Самолет " << (i + 1) << ": " 
             << "Ускорение = " << planes[i].ay << " м/с^2, "
             << "Время = " << planes[i].t << " с" << endl;
    }
    return 0;
}
