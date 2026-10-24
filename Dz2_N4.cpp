#include <iostream>
#include <vector>
#include<iomanip>
#include <numeric>
using namespace std;

int main() {
    double v0;
    cin >> v0;
    double g = 9.8;
    double dt = 1;
    double t_max = 100;
    vector<double> times,vel;
    for (double t = 0.0; t <= t_max; t += dt){
        double v = v0- g*t;
        if (v < -100){
            break;
        }
        times.push_back(t); vel.push_back(v);
        
    }
    double sum = accumulate(vel.begin(),vel.end(),0.0);
    double avg = sum/vel.size();
    cout << fixed << setprecision(2);
    cout << "Сумма скоростей: " << sum << endl;
    cout << "Средняя скорость: " << avg << " м/с" << endl;
    return 0;
}
