
#include <iostream>
#include <cmath>   // Для sqrt()
using namespace std;
struct Plane {
    double m;      
    double S;  
    double T;    
    double Cd;       
    double Cl;        
};
double ro = 1.225; 
 double V = 100.0;   
 double G = 9.81;    
 double h = 1000.0;  
double funL(Plane& plane) {
    return 0.5 * ro * V * V * plane.S * plane.Cl; 
}
double funLd(Plane& plane) {
    return 0.5 * ro * V * V * plane.S * plane.Cd;
}
double funa(Plane& plane, double D) {
    return (plane.T - D) / plane.m;
}

double funh(Plane& plane, double lift) {
    double ay = (lift - plane.m * G) / plane.m;
    if (ay <= 0) {
        return 1.0; 
    }
    return sqrt(2 * h / ay); 
}
int main() {
    Plane planes[3];
    for (int i = 0; i < 3; i++) {
        cout << "\nСамолет номер " << (i + 1) << ":" << endl;
        cout << "Введите массу : ";
        cin >> planes[i].m;
        cout << "Введите площадь крыла : ";
        cin >> planes[i].S;
        cout << "Введите тягу : ";
        cin >> planes[i].T;
        cout << "Введите коэффициент сопротивления Cd: ";
        cin >> planes[i].Cd;
        cout << "Введите коэффициент подъемной силы Cl: ";
        cin >> planes[i].Cl;
    }
    cout << "\n=== Результаты расчетов ===" << endl;
    double minTime = 1e5; 
    int fastest = -1;
    for (int i = 0; i < 3; i++) {
        double L = funL(planes[i]);
        double D = funLd(planes[i]);
        double a = funa(planes[i], D);
        double t = funh(planes[i], L);

        cout << "\nСамолет " << (i + 1) << ":" << endl;
        cout << "  Подъемная сила (L): " << L << " Н" << endl;
        cout << "  Сопротивление (D): " << D << " Н" << endl;
        cout << "  Ускорение (a): " << a << " м/с^2" << endl;

        if (t > 0) {
            cout << "  Время набора высоты " << h << " м: " << t << " с" << endl;
            if (t < minTime) {
                minTime = t;
                fastest = i;
            }
        } else {
            cout << "  Не может набрать высоту (подъемная сила слишком мала)." << endl;
        }
    }
    if (fastest != -1) {
        cout << "Быстрее всех наберет высоту " << h<< " м Самолет " 
             << (fastest + 1) << " за " << minTime << " секунд." << endl;
    } else {
        cout << "Ни один из самолетов не может набрать высоту." << endl;
    }

    return 0;
}
