//Кафедра "Информационная безопасность"
//ИУ8-32
//Забродина М.П.
//Лабораторная работа №1(Теория систем и системный анализ)
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
     
const double goldenRatio = (1 + sqrt(5)) / 2;
     
double func(double x) {
    return cos(x)*tanh(x);
}
     
int main() {
    double a = 1.5, b = 4;
    double e = 0.1;
    double x1, x2;
    cout <<"1. Sequential search (The golden ratio method):" <<endl;
    cout <<setfill('-') <<setw(76) <<"-" <<endl;
    cout <<"| Start of the |  End of the  |  Length of   |              |              |" <<endl;
    cout <<"|   interval   |   interval   | the interval |     f(ak)    |     f(bk)    |" <<endl;
    cout <<"|     (ak)     |     (bk)     |      (l)     |              |              |" <<endl;
    cout <<setfill('-') <<setw(76) <<"-" <<endl;
    while (fabs(b - a) > e) {
        x1 = b - (b - a) / goldenRatio;
        x2 = a + (b - a) / goldenRatio;
        cout <<setfill(' ') <<"|" <<setw(14) <<fixed <<setprecision(5) <<x1 <<"|" <<setw(14) <<x2 <<"|" <<setw(14) <<abs(b-a) <<"|" <<setw(14) <<func(x1) <<"|" <<setw(14) <<func(x2) <<"|" <<endl;
        if (func(x1) <= func(x2) ) 
            b = x2;
        else a = x1;
    }
    x1 = b - (b - a) / goldenRatio;
    x2 = a + (b - a) / goldenRatio;
    cout <<setfill(' ') <<"|" <<setw(14) <<fixed <<setprecision(5) <<x1 <<"|" <<setw(14) <<x2 <<"|" <<setw(14)  <<abs(b-a) <<"|";
    if (b-a < e) cout <<"         l < epsilon         |" <<endl;
    cout <<setfill('-') <<setw(76) <<"-" <<endl;
    cout <<"Minimum is reached at x = "  <<fixed <<setprecision(3) << (a + b) / 2 <<" +- " <<(b-a)/2 <<endl;
    cout <<endl <<endl;
    cout <<"2. Optimal passive search:" <<endl;
    a = 1.5;
    b = 4;
    int N = 1;
    cout <<setfill('-') <<setw(32) <<"-" <<endl;
    cout << "|  Number of  |   Value of x   |" <<endl;
    cout << "|  points(N)  |   in the min   |" <<endl;
    cout <<setw(32) <<"-" <<endl;
    while ((b - a) / N > e){
        cout <<"|" <<setfill(' ') <<setw(13) <<N <<"|";
        double a1 = a, b1 = b;
        double d = (b1 - a1) / (N + 1);
        while (b1 - a1 > 2 * d){
            x1 = a1 + d;
            x2 = b1 - d;
            if (func(x1) <= func(x2)) {
                b1 = x2;
            } else a1 = x1;
        } cout <<"  " <<(b1 + a1)/2 <<" +- " <<d <<"|" <<endl;
        N++;
    }
    cout <<setfill('-') <<setw(32) <<"-" <<endl;
    return 0;
}
