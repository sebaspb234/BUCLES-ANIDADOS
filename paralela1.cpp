
#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
#define MAX 5000


int main()
{
    std::vector<double> y(MAX, 0.0);
    std::vector<double> x(MAX, 0.0);
    std::vector<std::vector<double>> A(MAX, std::vector<double>(MAX, 0.0));

    auto start = std::chrono::system_clock::now();
    // primer loop

    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            y[i] += A[i][j]*x[j];

    auto end = std::chrono::system_clock::now();


    auto start2 = std::chrono::system_clock::now();
    // segundo loop

    for (int j = 0; j < MAX; j++)
        for (int i = 0; i < MAX; i++)
            y[i] += A[i][j]*x[j];

    auto end2 = std::chrono::system_clock::now();

    std::chrono::duration<float, std::milli> duration = end - start;
    std::chrono::duration<float, std::milli> duration2 = end2 - start2;

    cout << "Duracion del primer loop: " << duration.count() << " milisegundos" << endl;
    cout << "Duracion del segundo loop: " << duration2.count() << " milisegundos" << endl;

}