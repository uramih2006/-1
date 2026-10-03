#include <iostream>
using namespace std;
int main() {
    float S;
    float V;
    double ro;
    double Cl;
    cout <<"Введите площадь крыла самолета:";
    cin >> S;
    cout <<"Введите скорость самолета:";
    cin >> V;
    cout <<"Введите плотность воздуха:";
    cin >> ro;
    cout <<"Введите коэффициент подъёмной силы:";
    cin >> Cl;
    float L;
    L = 0.5*ro*(V*V)*S*Cl;
    cout << L << endl;
    return 0;
}
