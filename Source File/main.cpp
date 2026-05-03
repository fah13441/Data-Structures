#include "../Header/ResidentList.hpp"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    ResidentList testCity;

    cout << "=== SINGLY LINKED LIST IMPLEMENTATION ===" << endl;
    cout << "--- Loading Master Dataset ---" << endl;
    
    testCity.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testCity.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testCity.loadFromCSV("../Resource File/dataset3-cityC.csv");

    cout << "\n[Original Data]" << endl;
    testCity.display(5);

    // This is to test for sorting function, PLEASE SEE THIS CAUSE WE MAY NEED TO CHANGE THIS. This is only a placeholder =======================================================

    cout << "\n--- Sorting Master Dataset By Age ---" << endl;
    clock_t startAge = clock();
    testCity.sortListByAge();
    clock_t endAge = clock();
    double timeAge = double(endAge - startAge) / CLOCKS_PER_SEC;
    testCity.display(5);
    cout << "Execution Time: " << fixed << timeAge << " seconds." << endl;

    cout << "\n--- Sorting Master Dataset By Distance ---" << endl;
    testCity.sortListByDistance();
    testCity.display(5);

    cout << "\n--- Sorting Master Dataset By Carbon Emission ---" << endl;
    testCity.sortListByEmission();
    testCity.display(5);

    // Using this to test the searthing function, PLEASE CHECK THIS OUT ALSO CAUSE WE MAY NEED TO CHANGE THIS ============================================
    cout << "\n--- Testing Search Functions ---" << endl;
    testCity.searchByAgeGroup(20, 25);
    testCity.searchByTransport("Walking");
    
    return 0;
}