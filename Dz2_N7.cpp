#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
int main() {
    vector<double> heights = {2.0,5.0,10.0,20.0,40.0,0.0};
    vector<double> times = {1.0,2.0,3.0,4.0,5.0,6.0};
    auto it = find_if(heights.begin(), heights.end(), [](double h) {
        return h <= 0.0;
    });
    if (it == heights.end()){
        cout << "Падения не было" << endl;
    }
    else {
        size_t idx = distance(heights.begin(),it);
        double t_fall = times[idx];
        cout << "Время падения: " << t_fall  << " с, Высота: " << heights[idx] << " м" << endl;
    }
    return 0;
}
