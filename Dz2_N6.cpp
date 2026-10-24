#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
void printHeights(const vector<double>& vec) {
    if (vec.empty()) {
        cout << "Вектор пуст" << endl;
        return;
    }
    for (double h : vec) {
        cout << h << " ";
    }
    cout << endl;
}
int main() {
    vector<double> heights = {5.5, 15.0, 8.2, 25.1, 9.9, 30.0, 10.0, 2.0};
    auto new_end = remove_if(heights.begin(), heights.end(), [](double h) { 
        return h < 10.0; 
    });
    heights.erase(new_end, heights.end());
    cout << "После удаления (< 10): ";
    printHeights(heights);
    return 0;
}
