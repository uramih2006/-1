#include <iostream>
using namespace std;

int main() 
{
    double S = 20;
    int N = 5;
    double Cl = 0.4;
    double V[5];
    double ro[5];
    double L[5];
    cout << "Введите 5 значений скорости (V):" << endl;
    for(int i = 0; i < 5;i++){
        cout << "V[" << i+1 << "]=";
        cin >> V[i];
    }
    cout << "Введите 5 значений плотности воздуха(ro):" << endl;
    for(int i = 0; i < 5;i++){
        cout << "ro[" << i+1 << "]=";
        cin >> ro[i];
    }
    for (int i = 0; i < N; i++){
         L[i] = 0.5 * ro[i] * V[i] * V[i] * S * Cl;
    }
    cout << "| Шаг | Скорость | Плотность | Подъемная сила | " << endl;
    for (int i = 0; i < 5; i++){
        cout << "| " << i << " | " << V[i] << " | " << ro[i] << " | " << L[i] << "|" << endl;
    }
}
