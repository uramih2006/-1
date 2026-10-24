#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Point {
    double x, y, z;
};

class Rocket {
private:
    double mass;
    double vx, vy, vz;
    Point position;
public:
    Rocket(double m, double vel_x, double vel_y, double vel_z) 
        : mass(m), vx(vel_x), vy(vel_y), vz(vel_z), position{0.0, 0.0, 0.0} {}

    void updatePosition(double dt) {
        position.x += vx * dt;
        position.y += vy * dt;
        position.z += vz * dt;
    }

    void changeVelocity(double dvx, double dvy, double dvz) {
        vx += dvx;
        vy += dvy;
        vz += dvz;
    }

    Point getPosition() const {
        return position;
    }
};

int main() {
    vector<Rocket> squad;
    squad.reserve(5);

    squad.emplace_back(1000, 10, 0, 50);
    squad.emplace_back(900, 15, -5, 40);
    squad.emplace_back(1100, 5, 10, 60);
    squad.emplace_back(800, 20, 0, 30);
    squad.emplace_back(1200, 0, -15, 55);

    vector<vector<Point>> trajectories(5);

    double T = 10.0;
    double dt = 0.1; 

    for (double t = 0; t <= T; t += dt) {
        for (size_t i = 0; i < squad.size(); ++i) {
            squad[i].updatePosition(dt);
            trajectories[i].push_back(squad[i].getPosition());
        }
    }

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < squad.size(); ++i) {
        Point p = squad[i].getPosition();
        cout << "Ракета " << i + 1 << " (масса " << (i+1)*800 << "): "
             << "X = " << setw(8) << p.x 
             << " | Y = " << setw(8) << p.y 
             << " | Z = " << setw(8) << p.z << endl;
    }

    return 0;
}
