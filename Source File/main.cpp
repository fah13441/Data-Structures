#include "ResidentArray.hpp"
#include <iostream>

using namespace std;

int main() {
    ResidentArray testCity;

    cout << "--- Loading Master Dataset ---" << endl;
    testCity.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testCity.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testCity.loadFromCSV("../Resource File/dataset3-cityC.csv");

    cout << "\n[Original Unsorted Master Data]" << endl;
    testCity.display(5);

    cout << "--- Sorting Master Dataset By Age ---" << endl;
    testCity.sortArrayByAge();
    testCity.display(5);

    cout << "--- Sorting Master Dataset By Distance ---" << endl;
    testCity.sortArrayByDistance();
    testCity.display(5);

    cout << "--- Sorting Master Dataset By Carbon Emission ---" << endl;
    testCity.sortArrayByEmission();
    testCity.display(5);

    cout << "--- Testing Search Functions on Master Dataset ---" << endl;
    testCity.searchByAgeGroup(20, 40);
    testCity.searchByTransport("Car");
    testCity.searchByDistanceGreaterThan(25.0);

    return 0;
}