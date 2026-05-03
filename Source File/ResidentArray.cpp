#include "../Header/ResidentArray.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;

ResidentArray::ResidentArray(int cap) {
    capacity = cap;
    size = 0;
    arr = new Resident[capacity];
}

ResidentArray::~ResidentArray() {
    delete[] arr;
}

void ResidentArray::resize() {
    capacity *= 2;
    Resident* newArr = new Resident[capacity];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
}

void ResidentArray::insertToEnd(const Resident& r) {
    if (size >= capacity) resize();
    arr[size] = r;
    size++;
}

void ResidentArray::display(int limit) {
    cout << left << setw(8) << "ID" << setw(6) << "Age" << setw(15) << "Transport"
         << setw(12) << "Distance" << setw(15) << "Emission" << setw(6) << "Days" << endl;
    cout << "-------------------------------------------------------------" << endl;

    int count = (limit > size) ? size : limit;
    for (int i = 0; i < count; i++) {
        cout << left << setw(8) << arr[i].id << setw(6) << arr[i].age
             << setw(15) << arr[i].transport << setw(12) << arr[i].distance
             << setw(15) << arr[i].getTotalEmission() << setw(6) << arr[i].days << endl;
    }
}

void ResidentArray::loadFromCSV(string filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); 

    while (getline(file, line)) {
        if (line.empty() || line == "\r" || line == "\n") continue;
        
        Resident r;
        string temp = "";
        int field = 0;

        for (size_t i = 0; i <= line.length(); i++) {
            if (i == line.length() || line[i] == ',') {
                try {
                    if (field == 0) r.id = temp;
                    else if (field == 1) r.age = stoi(temp);
                    else if (field == 2) r.transport = temp;
                    else if (field == 3) r.distance = stof(temp);
                    else if (field == 4) r.emissionFactor = stof(temp);
                    else if (field == 5) r.days = stoi(temp);
                } catch(...) {}

                temp = "";
                field++;
            } else {
                temp += line[i];
            }
        }
        insertToEnd(r);
    }
    file.close();
}

int ResidentArray::getSize() { return size; }
Resident* ResidentArray::getArray() { return arr; }

void ResidentArray::sortArrayByAge() {
    for (int i = 0; i < size - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j].age < arr[minIdx].age) minIdx = j;
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
            if (arr[j].distance < arr[minIdx].distance) minIdx = j;
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
            if (arr[j].getTotalEmission() < arr[minIdx].getTotalEmission()) minIdx = j;
        }
        if (minIdx != i) {
            Resident temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
}

void ResidentArray::searchByAgeGroup(int minAge, int maxAge) {
    cout << "\n[Search Results: Age " << minAge << " to " << maxAge << "]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].age >= minAge && arr[i].age <= maxAge) {
            cout << "- Found ID: " << arr[i].id << " (Age: " << arr[i].age << ")" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << endl;
}

void ResidentArray::searchByTransport(string transportType) {
    cout << "\n[Search Results: Transport = " << transportType << "]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].transport == transportType) {
            cout << "- Found ID: " << arr[i].id << " (Transport: " << arr[i].transport << ")" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << endl;
}

void ResidentArray::searchByDistanceGreaterThan(float minDistance) {
    cout << "\n[Search Results: Distance > " << minDistance << " km]" << endl;
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].distance > minDistance) {
            cout << "- Found ID: " << arr[i].id << " (Distance: " << arr[i].distance << " km)" << endl;
            count++;
        }
    }
    cout << "Total Found: " << count << endl;
}

void ResidentArray::searchByTransportPerf(string target) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- [Array] Performance Search: Transport Mode [" << target << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].transport == target) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByDistancePerf(float threshold) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- [Array] Performance Search: Distance > " << threshold << "km ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].distance > threshold) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByAgeRangePerf(int minAge, int maxAge) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- [Array] Performance Search: Age Range [" << minAge << " - " << maxAge << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].age >= minAge && arr[i].age <= maxAge) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}