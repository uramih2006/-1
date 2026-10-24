#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <iterator> // Для std::distance
using namespace std;
struct RocketStats {
    double max_height = 0.0;
    double time_of_max = 0.0;
    double time_of_fall = -1.0;
};
RocketStats analyzeRocket(const vector<double>& heights, const vector<double>& times) {
    RocketStats stats;
    if (heights.empty()) return stats;
    auto max_it = max_element(heights.begin(), heights.end());
    stats.max_height = *max_it; 
    size_t idx_max = distance(heights.begin(), max_it);
    stats.time_of_max = times[idx_max];
    auto fall_it = find_if(heights.begin(), heights.end(), [](double h) {
        return h <= 0.0;
    });
    if (fall_it != heights.end()) {
        size_t idx_fall = distance(heights.begin(), fall_it);
        stats.time_of_fall = times[idx_fall];
    }
    return stats;
}
int main() {
    vector<double> heights1 = {0, 20, 45, 50, 40, 0};
    vector<double> times1   = {0,  1,  2,  3,  4, 5};
    vector<double> heights2 = {0, 15, 30, 35, 30, 20};
    vector<double> times2   = {0,  1,  2,  3,  4,  5};
    RocketStats r1 = analyzeRocket(heights1, times1);
    RocketStats r2 = analyzeRocket(heights2, times2);

    cout << fixed << setprecision(1);
    cout << setw(15) << "Параметр" 
         << setw(15) << "Ракета 1" 
         << setw(15) << "Ракета 2" << "\n";
    cout << "---------------------------------------------\n";
    
    cout << setw(15) << "Макс. высота" 
         << setw(15) << r1.max_height 
         << setw(15) << r2.max_height << "\n";
         
    cout << setw(15) << "Время макс." 
         << setw(15) << r1.time_of_max 
         << setw(15) << r2.time_of_max << "\n";
    cout << setw(15) << "Время падения";
    if (r1.time_of_fall == -1.0) cout << setw(15) << "В воздухе";
    else cout << setw(15) << r1.time_of_fall;
    
    if (r2.time_of_fall == -1.0) cout << setw(15) << "В воздухе\n";
    else cout << setw(15) << r2.time_of_fall << "\n";

    cout << "---------------------------------------------\n";
    if (r1.max_height > r2.max_height) {
        cout << "Ракета 1 поднялась выше." << endl;
    } else if (r2.max_height > r1.max_height) {
        cout << "Ракета 2 поднялась выше." << endl;
    } else {
        cout << "Обе ракеты поднялись на одинаковую высоту." << endl;
    }

    // Сравниваем время в воздухе
    // Если время == -1, значит ракета еще летит (бесконечное время)
    if (r1.time_of_fall == -1.0 && r2.time_of_fall != -1.0) {
        cout << "Ракета 1 все еще в воздухе (летит дольше)." << endl;
    } else if (r2.time_of_fall == -1.0 && r1.time_of_fall != -1.0) {
        cout << "Ракета 2 все еще в воздухе (летит дольше)." << endl;
    } else if (r1.time_of_fall == -1.0 && r2.time_of_fall == -1.0) {
        cout << "Обе ракеты все еще в воздухе." << endl;
    } else {
        // Обе упали, сравниваем числа
        if (r1.time_of_fall > r2.time_of_fall) {
            cout << "Ракета 1 находилась в воздухе дольше." << endl;
        } else if (r2.time_of_fall > r1.time_of_fall) {
            cout << "Ракета 2 находилась в воздухе дольше." << endl;
        } else {
            cout << "Обе ракеты упали одновременно." << endl;
        }
    }
    return 0;
}
