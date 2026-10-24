#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

struct Point{
    double t;
    double x;
    double y;
    double z;
};

int main() {
    double vx = 30.0;
    double vy = 20.0;
    double vz = 40.0;
    double dt = 1.0;
    double t_max = 10;
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;
    vector <Point> traj;
    traj.reserve(static_cast<size_t>(t_max / dt) + 1);
     for (double t = 0.0; t <= t_max; t += dt) {
        traj.push_back({t, x, y, z});
        x += vx * dt;
        y += vy * dt;
        z += vz * dt;
    }
    cout << setw(10) << "Время (t)" 
         << setw(10) << "X" 
         << setw(10) << "Y" 
         << setw(10) << "Z" << "\n";
    cout << "----------------------------------------\n";
    for (const auto& p : traj) {
        cout << setw(10) << p.t 
             << setw(10) << p.x 
             << setw(10) << p.y 
             << setw(10) << p.z << "\n";
    }
    return 0;
}
