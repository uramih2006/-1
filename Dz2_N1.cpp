#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

int main() {
    double v0 = 50.0;
    double g = 9.8;
    double dt = 1;
    vector <double> times;
    vector <double> heights;
    for (double t = 0.0; t <= 1000.0; t += dt) {
        double h = v0*t-0.5*g*t*t;
        if (h < 0){
            break;
    }
        times.push_back(t);
        heights.push_back(h);
    }
    std::cout << std::setw(10) << "Время (с)" << std::setw(15) << "Высота (м)" << "\n";
    std::cout << "------------------------------\n";
    for (size_t i=0; i<times.size();i++ ){
        cout<< setw(10) << times[i] << setw(15) << heights[i] << "\n";
    }
    return 0;
}
