#include "../Header/ResidentList.hpp"
#include "../Header/ResidentArray.hpp"
#include <iostream>
#include <ctime>
#include "../analysis.h"
using namespace std;

int main() {
    ResidentList testCity;
    ResidentArray testArray(5000);

    cout << "=== SINGLY LINKED LIST IMPLEMENTATION ===" << endl;
    cout << "--- Loading Master Dataset ---" << endl;
    
    testCity.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testCity.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testCity.loadFromCSV("../Resource File/dataset3-cityC.csv");

    testArray.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testArray.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testArray.loadFromCSV("../Resource File/dataset3-cityC.csv");
//Member 3
    cout << "\n=== MEMBER 3: CARBON EMISSION ANALYSIS ===" << endl;

analyzeArray(testArray.getArray(), testArray.getSize(), "Master Dataset");
analyzeLinkedList(testCity.getHead(), "Master Dataset");
//Member 3
    cout << "\n[Original Data]" << endl;
    testCity.display(5);
    testCity.traversal();

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

    // Member 5: Performance Search Testing
    testCity.searchByAgeRangeLL(18, 25);
    testCity.searchByTransportLL("Car");
    testCity.searchByDistanceLL(15.0);
    testArray.searchByAgeRange(18, 25);
    testArray.searchByTransport("Car");
    testArray.searchByDistance(15.0);
    
    return 0;
}