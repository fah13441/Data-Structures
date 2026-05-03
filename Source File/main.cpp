#include "../Header/ResidentList.hpp"
#include "../Header/ResidentArray.hpp"
#include "../Header/analysis.hpp"
#include <iostream>
#include <ctime>

using namespace std;

int main() {
    ResidentList testCity;
    ResidentArray testArray(5000);

    cout << "=== DATA STRUCTURES: INTEGRATED ASSIGNMENT RUN ===" << endl;
    cout << "--- Loading Master Dataset ---" << endl;
    
    testCity.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testCity.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testCity.loadFromCSV("../Resource File/dataset3-cityC.csv");

    testArray.loadFromCSV("../Resource File/dataset1-cityA.csv");
    testArray.loadFromCSV("../Resource File/dataset2-cityB.csv");
    testArray.loadFromCSV("../Resource File/dataset3-cityC.csv");

    cout << "\n=== MEMBER 3: CARBON EMISSION ANALYSIS ===" << endl;
    analyzeArray(testArray.getArray(), testArray.getSize(), "Master Dataset");
    analyzeLinkedList(testCity.getHead(), "Master Dataset");

    cout << "\n=== MEMBER 2: TRAVERSAL ===" << endl;
    cout << "\n[Original Data]" << endl;
    testCity.display(5);
    testCity.traversal();

    cout << "\n=== MEMBER 4: SORTING ALGORITHMS ===" << endl;
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

    cout << "\n=== MEMBER 4: SEARCHING ALGORITHMS ===" << endl;
    testCity.searchByAgeGroup(20, 25);
    testCity.searchByTransport("Walking");

    cout << "\n=== MEMBER 5: PERFORMANCE TRACKING ===" << endl;
    testCity.searchByAgeRangeLL(18, 25);
    testCity.searchByTransportLL("Car");
    testCity.searchByDistanceLL(15.0);
    
    testArray.searchByAgeRangePerf(18, 25);
    testArray.searchByTransportPerf("Car");
    testArray.searchByDistancePerf(15.0);
    
    return 0;
}