#include <iostream>
using namespace std;
struct Aircraft {
    double m;
    double S;
    double T;
    double Cd;
    double Cl;
    double L;
    double D;
    double a;
};
int main() {
  double rho = 1.225;
  double V = 100.0;
    int N;
      int maxn = 0;
    cout << "Введите количество самолетов: ";
    cin >> N;
    Aircraft* planes = new Aircraft[N];
    for (int i = 0; i < N; i++) {
        cout << "Самолет " << (i + 1) << ":" << endl;
        cout << "Введите массу: ";
        cin >> planes[i].m;
        cout << "Введите площадь крыла: ";
        cin >> planes[i].S;
        cout << "Введите тягу: ";
        cin >> planes[i].T;
        cout << "Введите Cd: ";
        cin >> planes[i].Cd;
        cout << "Введите Cl: ";
        cin >> planes[i].Cl;
    }
    for (int i = 0; i < N; i++) {
        planes[i].L = 0.5 * rho * V * V * planes[i].S * planes[i].Cl;
        planes[i].D = 0.5 * rho * V * V * planes[i].S * planes[i].Cd;
        planes[i].a = (planes[i].T - planes[i].D) / planes[i].m;
    }
    for (int i = 1; i < N; i++) {
        if (planes[i].a > planes[maxIdx].a) {
            maxIdx = i;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << "Самолет " << (i + 1) << ": "
             << "Подъемная сила = " << planes[i].L << " Н, "
             << "Сопротивление = " << planes[i].D << " Н, "
             << "Ускорение = " << planes[i].a << " м/с^2" << endl;
    }
    cout << "Наибольшее ускорение у самолета " << (maxn + 1) 
         << " (" << planes[maxn].a << " м/с^2)" << endl;
    delete[] planes;
    return 0;
}
