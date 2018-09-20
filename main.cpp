#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

vector<double> doubleVector;


void createFile() {
    ofstream fout;
    fout.open("Readings.txt");
}

int createInt(){
    int maxInt;

    random_device rd;
    mt19937 intGenerator(rd());
    uniform_int_distribution<> intDistribution(512,1024);

    maxInt = intDistribution(intGenerator);

    return maxInt;
}

double createDouble() {
    double currDouble;

    random_device rd;
    mt19937 doubleGenerator(rd());
    uniform_real_distribution<> intDistribution(50.000,90.000);

    currDouble = intDistribution(doubleGenerator);

    return currDouble ;
}

void writeFile(){
    ofstream fout;
    fout.open("Readings.txt");
    int indexMax = createInt();
    int i{0};
    while(i < indexMax) {
        fout << i << " " << setprecision(3)<< fixed << createDouble() << endl;
        i++;
    }
}

void readFile() {
    string line;
    double doubleValue{0};
    int integer{0};

    ifstream fin;
    fin.open("Readings.txt");

    while (getline(fin, line)) {
        istringstream iss(line);
        iss >> integer >> doubleValue;
        doubleVector.push_back(doubleValue);
    }
}


void calculate() {
    int vectorSize = doubleVector.size();
    double sumOfElements{0};
    double median = doubleVector.at(vectorSize/2);

    for(double value:doubleVector){
        sumOfElements += value;
    }
    double average = (sumOfElements/(double) vectorSize);

    sort(doubleVector.begin(), doubleVector.end());


    cout << "There are " << doubleVector.size() << " readings in the file." << endl;
    cout << "The average reading is " << average << endl;
    cout << "The highest reading is " << doubleVector.at(vectorSize - 1) << endl;
    cout << "THe lowest reading is " << doubleVector.at(0) << endl;
    cout << "The median reading is " << median << endl;
}




int main() {
    createFile();
    writeFile();
    readFile();
    calculate();
    return 0;
}