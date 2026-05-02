#include "ResidentArray.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

using namespace std;

ResidentArray::ResidentArray(int cap) {
    capacity = cap;
    size = 0;
    arr = new Resident[capacity];
}

ResidentArray::~ResidentArray() {
    delete[] arr;
}

void ResidentArray::insertToEnd(const Resident& r) {
    if (size < capacity) {
        arr[size] = r;
        size++;
    } else {
        cout << "Array is full! Increase capacity." << endl;
    }
}

void ResidentArray::display(int limit) {
    cout << left << setw(10) << "ID" << setw(6) << "Age" << setw(15) << "Transport" 
         << setw(10) << "Dist" << setw(15) << "Total Emission" << endl;
    cout << "---------------------------------------------------------------" << endl;
    
    int displayCount = (size < limit) ? size : limit;
    for (int i = 0; i < displayCount; i++) {
        cout << left << setw(10) << arr[i].id << setw(6) << arr[i].age 
             << setw(15) << arr[i].transport << setw(10) << arr[i].distance 
             << setw(15) << arr[i].getTotalEmission() << endl;
    }
    cout << "(Showing top " << displayCount << " of " << size << " total records)\n" << endl;
}

void ResidentArray::loadFromCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open " << filename << ". Check your folder paths!" << endl;
        return;
    }

    string line, temp;
    int loadCount = 0;

    while (getline(file, line)) {
        if (line.empty() || line == "\r" || line == "\n") continue; 

        stringstream ss(line);
        Resident r;

        getline(ss, r.id, ',');

        if (r.id == "ID" || r.id == "id" || r.id == "Id") continue;

        try {
            getline(ss, temp, ','); r.age = stoi(temp);
            getline(ss, r.transport, ',');
            getline(ss, temp, ','); r.distance = stof(temp);
            getline(ss, temp, ','); r.emissionFactor = stof(temp);
            
            getline(ss, temp); 
            r.days = stoi(temp);

            insertToEnd(r);
            loadCount++;
        } 
        catch (...) {
      
        }
    }
    
    file.close();
    cout << "- Loaded " << loadCount << " records from " << filename << endl;
}


// ========================================== SORTING ALGORITHMS ==========================================

void ResidentArray::sortArrayByAge() {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].age < arr[minIdx].age) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Resident temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void ResidentArray::sortArrayByDistance() {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].distance < arr[minIdx].distance) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Resident temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void ResidentArray::sortArrayByEmission() {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].getTotalEmission() < arr[minIdx].getTotalEmission()) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            Resident temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

// ========================================== SEARCHING ALGORITHMS ==========================================

void ResidentArray::searchByAgeGroup(int minAge, int maxAge) {
    cout << "[Search Results: Age " << minAge << " to " << maxAge << "]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].age >= minAge && arr[i].age <= maxAge) {
            cout << "- Found ID: " << arr[i].id << " (Age: " << arr[i].age << ")" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << "\n\n";
}

void ResidentArray::searchByTransport(string transportType) {
    cout << "[Search Results: Transport = " << transportType << "]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].transport == transportType) {
            cout << "- Found ID: " << arr[i].id << " (Transport: " << arr[i].transport << ")" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << "\n\n";
}

void ResidentArray::searchByDistanceGreaterThan(float minDistance) {
    cout << "[Search Results: Distance > " << minDistance << " km]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].distance > minDistance) {
            cout << "- Found ID: " << arr[i].id << " (Distance: " << arr[i].distance << " km)" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << "\n\n";
}