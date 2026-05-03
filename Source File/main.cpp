#include "../Header/ResidentArray.hpp"
#include <iostream>

using namespace std;

int main() {
    ResidentArray testCity;

    cout << "--- Loading Master Dataset ---" << endl;
    testCity.loadFromCSV("Resource File/dataset1-cityA.csv");
testCity.loadFromCSV("Resource File/dataset2-cityB.csv");
testCity.loadFromCSV("Resource File/dataset3-cityC.csv");

    cout << "\n[Original Data]" << endl;
    testCity.display(5);

    return 0;
}