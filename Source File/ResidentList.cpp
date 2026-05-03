#include "../Header/ResidentList.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

ResidentList::ResidentList() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

ResidentList::~ResidentList() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}

void ResidentList::insertToEnd(const Resident& r) {
    Node* newNode = new Node;
    newNode->data = r;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

int ResidentList::getSize() {
    return size;
}

void ResidentList::display(int limit) {
    cout << left << setw(8) << "ID" << setw(6) << "Age" << setw(15) << "Transport"
         << setw(12) << "Distance" << setw(15) << "Total Emission" << setw(6) << "Days" << endl;
    cout << "-------------------------------------------------------------" << endl;

    Node* temp = head;
    int count = 0;
    
    while (temp != nullptr && count < limit) {
        cout << left << setw(8) << temp->data.id << setw(6) << temp->data.age
             << setw(15) << temp->data.transport << setw(12) << temp->data.distance
             << setw(15) << temp->data.getTotalEmission() << setw(6) << temp->data.days << endl;
        temp = temp->next;
        count++;
    }
    cout << "(Showing top " << count << " of " << size << " records)\n" << endl;
}

// ========================================== CSV LOADER ==========================================
void ResidentList::loadFromCSV(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    int loadCount = 0;
    
    getline(file, line); 

    while (getline(file, line)) {
        if (line.empty() || line == "\r" || line == "\n") continue;

        Resident r;
        size_t pos = 0;

        try {
            pos = line.find(','); r.id = line.substr(0, pos); line.erase(0, pos + 1);
            if (r.id == "ID" || r.id == "id") continue; // Extra safety skip

            pos = line.find(','); r.age = stoi(line.substr(0, pos)); line.erase(0, pos + 1);
            pos = line.find(','); r.transport = line.substr(0, pos); line.erase(0, pos + 1);
            pos = line.find(','); r.distance = stof(line.substr(0, pos)); line.erase(0, pos + 1);
            pos = line.find(','); r.emissionFactor = stof(line.substr(0, pos)); line.erase(0, pos + 1);
            r.days = stoi(line); // Last item

            insertToEnd(r);
            loadCount++;
        } catch (...) {
        }
    }
    file.close();
    cout << "- Loaded " << loadCount << " records from " << filename << endl;
}

// ========================================== SORTING ==========================================

void ResidentList::sortListByAge() {
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data.age < minNode->data.age) {
                minNode = j;
            }
        }
        if (minNode != i) {
            Resident temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}

void ResidentList::sortListByDistance() {
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data.distance < minNode->data.distance) {
                minNode = j;
            }
        }
        if (minNode != i) {
            Resident temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}

void ResidentList::sortListByEmission() {
    for (Node* i = head; i != nullptr; i = i->next) {
        Node* minNode = i;
        for (Node* j = i->next; j != nullptr; j = j->next) {
            if (j->data.getTotalEmission() < minNode->data.getTotalEmission()) {
                minNode = j;
            }
        }
        if (minNode != i) {
            Resident temp = i->data;
            i->data = minNode->data;
            minNode->data = temp;
        }
    }
}

// ========================================== SEARCHING ==========================================

void ResidentList::searchByAgeGroup(int minAge, int maxAge) {
    cout << "\n[Search Results: Age " << minAge << " to " << maxAge << "]" << endl;
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.age >= minAge && temp->data.age <= maxAge) {
            cout << "- Found ID: " << temp->data.id << " (Age: " << temp->data.age << ")" << endl;
            count++;
        }
        temp = temp->next;
    }
    cout << "Total Found: " << count << endl;
}

void ResidentList::searchByTransport(string transportType) {
    cout << "\n[Search Results: Transport = " << transportType << "]" << endl;
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.transport == transportType) {
            cout << "- Found ID: " << temp->data.id << " (Transport: " << temp->data.transport << ")" << endl;
            count++;
        }
        temp = temp->next;
    }
    cout << "Total Found: " << count << endl;
}

void ResidentList::searchByDistanceGreaterThan(float minDistance) {
    cout << "\n[Search Results: Distance > " << minDistance << " km]" << endl;
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.distance > minDistance) {
            cout << "- Found ID: " << temp->data.id << " (Distance: " << temp->data.distance << " km)" << endl;
            count++;
        }
        temp = temp->next;
    }
    cout << "Total Found: " << count << endl;
}