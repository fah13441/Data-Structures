#ifndef RESIDENT_HPP
#define RESIDENT_HPP

#include <string>
using namespace std;

struct Resident {
    string id;          
    int age;
    string transport;
    float distance;
    float emissionFactor;
    int days;

    float getTotalEmission() const {
        return distance * emissionFactor * days;
    }
};

#endif