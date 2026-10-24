#include <iostream>
#include <vector>
#include<iomanip>
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
    for (size_t i=0; i<vel.size();i++ ){
        cout<< setw(10) << times[i] << setw(15) << vel[i] << "\n";
    }
    return 0;
}
