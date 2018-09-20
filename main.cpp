#include <iostream>
#include <fstream>
#include <random>
#include <ctime>

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << "Amazing Chloe" << endl;
    return 0;
}

void createFile() {
    ofstream fout:
    fout.open("Readings.txt");
}

int maxInt(){
    int maxInt;

    random_device rd;
    mt19937 intGenerator(rd());
    uniform_int_distribution<> intDistribution(512,1024);

    maxInt = intDistribution(intGenerator);

    return maxInt;
}

double createDouble() {
    double currDouble;

    default_random_engine doubleGenerator(time(nullptr));
    uniform_real_distribution<double> doubleDistribution(50,90);
    currDouble = doubleDistribution(doubleGenerator);

    return currDouble;
}