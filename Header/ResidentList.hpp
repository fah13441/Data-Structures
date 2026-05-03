#ifndef RESIDENTLIST_HPP
#define RESIDENTLIST_HPP

#include "Resident.hpp"
#include <string>

struct Node {
    Resident data;
    Node* next;
};

class ResidentList {
private:
    Node* head;
    Node* tail;
    int size;

public:
    ResidentList();
    ~ResidentList();

    void insertToEnd(const Resident& r);
    void display(int limit = 10);
    void traversal();
    void loadFromCSV(std::string filename);

    int getSize();
    Node* getHead();

    void sortListByAge();
    void sortListByDistance();
    void sortListByEmission();
    void searchByAgeGroup(int minAge, int maxAge);
    void searchByTransport(std::string transportType);
    void searchByDistanceGreaterThan(float minDistance);
    void searchByTransportLL(std::string target);
    void searchByDistanceLL(float threshold);
    void searchByAgeRangeLL(int minAge, int maxAge);
};

#endif