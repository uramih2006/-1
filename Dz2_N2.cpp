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
    if (heights.empty()){
        cout << "Нет данных" << endl;
        return 1;
    }
    size_t idx_max = 0;
    for(size_t i =1; i < heights.size(); i++){
        if (heights[i] > heights[idx_max]){
            idx_max = i;
        }
    }
    cout << "Максимальная высота: " << heights[idx_max] 
         << " м, достигнута на " << times[idx_max] << " секунде." << endl;
    return 0;
}
