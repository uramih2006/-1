#include <iostream>
using namespace std;
void fun(float S, float V, double ro, double Cd) {
    double Ld =  (0.5*ro*(V*V)*S*Cd);
    cout << "Аэродинамическое сопротивление:" << Ld << endl;
}
int main() {
    float S;
    float V;
    double ro;
    double Cd;
    cout <<"Введите площадь крыла самолета:";
    cin >> S;
    cout <<"Введите скорость самолета:";
    cin >> V;
    cout <<"Введите плотность воздуха:";
    cin >> ro;
    cout <<"Введите коэффициент сопротивления:";
    cin >> Cd;
    fun(S,V,ro,Cd);
    return 0;
}
