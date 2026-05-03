#ifndef RESIDENTLIST_HPP
#define RESIDENTLIST_HPP

#include "Resident.hpp"
#include <string>

// Custom Singly Linked List Node (No STL)
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
    
    // Custom CSV Loader without <sstream>
    void loadFromCSV(std::string filename);

    int getSize();

    // ==========================================
    // Member 4: Sorting Functions
    // ==========================================
    void sortListByAge();
    void sortListByDistance();
    void sortListByEmission();

    // ==========================================
    // Member 4: Searching Functions
    // ==========================================
    void searchByAgeGroup(int minAge, int maxAge);
    void searchByTransport(std::string transportType);
    void searchByDistanceGreaterThan(float minDistance);

    // ==========================================================
    // Member 5: Searching & Performance Functions (Linked List)
    // ==========================================================
    void searchByTransportLL(string target);
    void searchByDistanceLL(float threshold);
    void searchByAgeRangeLL(int minAge, int maxAge);
};

#endif