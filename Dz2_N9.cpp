#include <iostream>
#include <vector>
#include <iomanip>
#include <random> 
using namespace std;
vector<double> smoothTrajectory(const vector<double>& h) {
    size_t n = h.size();
    vector<double> smoothed(n); 
    if (n == 0) return smoothed;
    if (n == 1) {
        smoothed[0] = h[0];
        return smoothed;
    }
    smoothed[0] = h[0];
    smoothed[n - 1] = h[n - 1];
    for (size_t i = 1; i + 1 < n; ++i) {
        smoothed[i] = (h[i - 1] + h[i] + h[i + 1]) / 3.0;
    }
    return smoothed;
}

int main() {
    vector<double> ideal_heights;
    for (int i = 0; i <= 10; ++i) {
        double t = i * 1.0;
        ideal_heights.push_back(50.0 * t - 4.9 * t * t);
    }
    vector<double> noisy_heights = ideal_heights;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-3.0, 3.0); 
    for (double& h : noisy_heights) {
        h += dis(gen); 
    }

    vector<double> smoothed = smoothTrajectory(noisy_heights);

    cout << fixed << setprecision(2);
    cout << setw(10) << "С шумом" << setw(16) << "Сглаженная" << "\n";
    cout << "--------------------------\n";

    for (size_t i = 0; i < noisy_heights.size(); ++i) {
        cout << setw(10) << noisy_heights[i] 
             << setw(15) << smoothed[i] << "\n";
    }

    return 0;
}
