// DOMAČA NALOGA 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _USE_MATH_DEFINES
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <omp.h>
#include <ctime>

using namespace std;

int main() {
    // poimenujemo + preberemo datoteko
    std::string filename = "\\Users\\matijamacus\\Downloads\\DN5\\datoteka_A_b.txt";
    
    std::ifstream infile;
    infile.open(filename);
    
    
    // matrika A
    vector<vector<double>> A;

    //vektor b;
    vector<double> b;

    // velikost matrike A 
    std::string string_first_line;
    std::getline(infile, string_first_line);

    // ('A: n=256') in '=' zamenjamo z . z ' '
    std::replace(string_first_line.begin(), string_first_line.end(), '=', ' ');

    // definiramo stringstream, s katerim je nekoliko lazje shranjevati + podatke iz string-a, ce so loceni z ' '
    std::istringstream iss(string_first_line);
    std::string del_del1; // string 'A:' 1. vrstice
    std::string del_del2; // string 'n' 1. vrstice
    int n; // velikost matrike A

    // istringstream loci glede na ' ', trenutno imamo 'A: n 256'
    iss >> del_del1;
    iss >> del_del2;
    iss >> n;

    std::cout << "Velikost matrike A: " << n << "x" << n << std::endl;;


    // iteracija, ki prebere in zapolni matriko A
    for (int iiA = 0; iiA < n; iiA++)
    {
     
        std::string line;
        std::getline(infile, line);
        
        std::replace(line.begin(), line.end(), ';', ' ');

       
        std::istringstream iss_column(line);

        
        vector<double> row;

        // iteriramo po elementih v iss_column
        for (int column = 0; column < n; column++)
        {
            double element_a = 0;
            iss_column >> element_a;
            row.push_back(element_a);
        }

        //vektor za vrstico damo v A
        A.push_back(row);
    }

    // Naslednja vrstica je prazna
    std::string empty_line;
    std::getline(infile, empty_line);

    // preberemo še vektor b
    std::string string_line_b;
    std::getline(infile, string_line_b);

  
    std::replace(string_line_b.begin(), string_line_b.end(), '>', ' ');
    std::istringstream iss_b(string_line_b);
    int n_b; 

    iss_b >> del_del1;
    iss_b >> del_del2;
    iss_b >> n_b;

    std::cout << "Velikost vektorja b: " << n_b << std::endl;;

  
    for (int iib = 0; iib < n_b; iib++)
    {
        // preberemo vrstico + shranimo element v vrstici v vektor b
        std::string line_b_element;
        std::getline(infile, line_b_element);
        std::istringstream iss_b_element(line_b_element);

        double b_element = 0;
        iss_b_element >> b_element;

        b.push_back(b_element);
    }

    // Sedaj imamo A in b. 
    //Zapišemo Gauss-Seidel metodo. Najprej
    // inicializiramo vektor resitve T, npr. na 120 stopinj.
    vector<double> T;
    for (int iiT = 0; iiT < n_b; iiT++)
    {
        T.push_back(120);
    }

    auto start_time = std::chrono::high_resolution_clock::now();
    for (int ii = 0; ii < 2000; ii++)
    {
        // Gauss-Seidelova metoda
        for (int jj = 0; jj < n; jj++)
        {
            double d = b[jj];
            for (int ii2 = 0; ii2 < n; ii2++)
            {
                if (jj != ii2)
                {
                    d = d - A[jj][ii2] * T[ii2];
                }
            }
            T[jj] = d / A[jj][jj];
        }
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_duration = end_time - start_time;
    std::cout << "Cas z Gauss-Seidel metodo: " << time_duration.count() << " [s]" << std::endl;

    auto start_time_omp = std::chrono::high_resolution_clock::now();
#pragma omp parallel for
    for (int ii = 0; ii < 2000; ii++) {
        for (int i = 0; i < n; i++) {
            double d = b[i];

            for (int j = 0; j < n; j++) {
                if (i != j) {
                    d -= A[i][j] * T[j];
                }
            }

            double tempT = d / A[i][i];

#pragma omp critical
            T[i] = tempT;
        }
    }
    auto end_time_omp = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time_duration_omp = end_time_omp - start_time_omp;
    std::cout << "Cas z Gauss-Seidel - OpenMP : " << time_duration_omp.count() << " [s]" << std::endl;

    // max vrednost
    double max_T = 0;
    for (int iiT = 0; iiT < n_b; iiT++)
    {
        cout << T[iiT] << endl;

        if (T[iiT] > max_T) {
            max_T = T[iiT];
        }
    }
    std::cout << "Serijski cas: " << time_duration.count() << " [s]" << std::endl;
    cout << "Mxa temperatura: " << max_T << " [deg C]." << endl;



    return 0;
}
