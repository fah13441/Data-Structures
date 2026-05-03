#ifndef RESIDENTARRAY_HPP
#define RESIDENTARRAY_HPP

#include "Resident.hpp"
#include <string>

class ResidentArray {
private:
    Resident* arr;
    int capacity;
    int size;

    void resize();

public:
    ResidentArray(int cap = 15000);
    ~ResidentArray();

    void insertToEnd(const Resident& r);
    void display(int limit = 10);
    void loadFromCSV(std::string filename);

    int getSize();
    Resident* getArray();

    void sortArrayByAge();
    void sortArrayByDistance();
    void sortArrayByEmission();
    void searchByAgeGroup(int minAge, int maxAge);
    void searchByTransport(std::string transportType);
    void searchByDistanceGreaterThan(float minDistance);
    void searchByTransportPerf(std::string target);
    void searchByDistancePerf(float threshold);
    void searchByAgeRangePerf(int minAge, int maxAge);
};

#endif