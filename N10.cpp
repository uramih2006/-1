#include <iostream>
#include <cmath>
using namespace std;
int main() {
   double g = 9.81;
   double h = 1000.0;
   double m = 1000.0;
  double Tmin;
  double Tmax;
  double dT;
    cout << "Введите Tmin, Tmax и шаг dT: ";
    cin >> Tmin >> Tmax >> dT;
    double minTime = 1e9;
    double optimalT = Tmin;
    for (double T = Tmin; T <= Tmax; T += dT) {
        double ay = (T - m * g) / m;
        if (ay > 0) {
            double t = sqrt(2 * h / ay);
            if (t < minTime) {
                minTime = t;
                optimalT = T;
            }
        }
    }
    cout << "Оптимальная тяга: " << optimalT << " Н" << endl;
    cout << "Минимальное время набора высоты: " << minTime << " с" << endl;
    return 0;
}
