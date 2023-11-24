#include <iostream>
#include <cmath>

using namespace std;

double f_Arc(double x, int n) {
    double rezultat = 0;

    for (int i = 0; i < n; i++) {
        rezultat += pow(-1, i) * pow(x, 2 * i + 1) / (2 * i + 1);
    }

    return rezultat;
}

int main() {
    double a = 0;
    double b = M_PI_4;

    int tocke;
    cout << "Vnesite število točk: ";
    cin >> tocke;

    double xi[tocke];

    for (int i = 0; i < tocke; i++) {
        xi[i] = static_cast<double>(i) * M_PI / (4 * (tocke - 1));
    }

    double vsota = 0;
    for (int i = 1; i < tocke - 1; i++) {
        vsota += exp(3 * xi[i]) * f_Arc(xi[i] / 2, 10);
    }

    double integral = (b - a) / (2 * tocke) * (2 * vsota + exp(3 * a) * f_Arc(a / 2, 10) + exp(3 * b) * f_Arc(b / 2, 10));

    std::cout << "Približna vrednost integrala je: " << integral << std::endl;

    return 0;
}

