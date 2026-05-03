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

    void searchByTransport(string target);
    void searchByDistance(float threshold);
    void searchByAgeRange(int minAge, int maxAge);

    int getSize();
    Resident* getArray();
};

#endif