#include <iostream>
#include <cmath>
using namespace std;
int main() {
    float ay;
    float h;
    cout << "Введите вертикальное ускорение: ";
    cin >> ay;
    if (ay <= 0){
        cout << "Неверное условие" << endl;
        return 1;
    }
    cout << "Введите требуемую высоту:" << endl;
    cin >> h;
    if (h < 0){
        cout << "Неверное условие" << endl;
        return 1;
    }
    float t = sqrt(h*2/ay);
    cout << "Время на подъём:" <<  t << endl;
    return 0;
}
