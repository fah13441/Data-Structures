#ifndef RESIDENTARRAY_HPP
#define RESIDENTARRAY_HPP

#include "Resident.hpp"
#include <string>
#include <sstream>

class ResidentArray {
private:
    Resident* arr;
    int capacity;
    int size;

public:
    ResidentArray(int cap = 15000); 
    ~ResidentArray();
    void insertToEnd(const Resident& r);
    void display(int limit = 10);
    void loadFromCSV(string filename);

    // ========================================== Sorting Functions  ==========================================
    void sortArrayByAge();
    void sortArrayByDistance();
    void sortArrayByEmission();

    // ==========================================  Searching Functions  ==========================================
    void searchByAgeGroup(int minAge, int maxAge);
    void searchByTransport(string transportType);
    void searchByDistanceGreaterThan(float minDistance);
};

#endif