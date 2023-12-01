#include <fstream>
#include <vector>
#include <iostream>




double centralna_razlika(const std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (data[idx + 1].second - data[idx - 1].second) / (2 * dx);
}


double razlika_nazaj(const std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (3 * data[idx].second - 4 * data[idx - 1].second + data[idx - 2].second) / (2 * dx);
}

double razlika_naprej(const std::vector<std::pair<double, double>>& data, int idx, double dx) {
    return (-3 * data[idx].second + 4 * data[idx + 1].second - data[idx + 2].second) / (2 * dx);
}




int main() {
    std::ifstream inputFile("poly.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Neuspešno odpranje datoteke: Poly.txt\n";
        return 1;
    }

    int numOfValues;
    inputFile >> numOfValues;

    std::vector<std::pair<double, double>> data(numOfValues);
    for (int i = 0; i < numOfValues; ++i) {
        inputFile >> data[i].first >> data[i].second;
    }

    inputFile.close();

    double dx = 0.0294117647058822; // ∆x

    std::ofstream outputFile("diff_poly.txt");
    if (!outputFile.is_open()) {
        std::cerr << "Neuspešen preizkus kreiranja datoteke: diff_poly.txt\n";
        return 1;
    }

    for (int i = 0; i < numOfValues; ++i) {
        double derivative = (i == 0) ? razlika_naprej(data, i, dx) : ((i == numOfValues - 1) ? razlika_nazaj(data, i, dx) : centralna_razlika(data, i, dx));
        outputFile << "Odvod f'(" << data[i].first << ") = " << derivative << std::endl;
    }

    outputFile.close();

    std::cout << "Rezultati odvodov so uspešno shranjeni v datoteki: diff_poly.txt\n";

    return 0;
}
