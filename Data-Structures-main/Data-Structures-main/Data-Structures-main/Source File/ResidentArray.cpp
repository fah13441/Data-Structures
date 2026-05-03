#include "../Header/ResidentArray.hpp"
#include <iostream>
#include <fstream>
#include <iomanip>

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
    if (size >= capacity) {
        resize();
    }

    arr[size] = r;
    size++;
}

void ResidentArray::display(int limit) {
    cout << left
         << setw(8) << "ID"
         << setw(6) << "Age"
         << setw(15) << "Transport"
         << setw(12) << "Distance"
         << setw(15) << "Emission"
         << setw(6) << "Days" << endl;

    cout << "-------------------------------------------------------------" << endl;

    int count = (limit > size) ? size : limit;

    for (int i = 0; i < count; i++) {
        cout << left
             << setw(8) << arr[i].id
             << setw(6) << arr[i].age
             << setw(15) << arr[i].transport
             << setw(12) << arr[i].distance
             << setw(15) << arr[i].emissionFactor
             << setw(6) << arr[i].days
             << endl;
    }
}

void ResidentArray::loadFromCSV(string filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // skip header

    while (getline(file, line)) {
        Resident r;
        string temp = "";
        int field = 0;

        for (int i = 0; i <= line.length(); i++) {
            if (i == line.length() || line[i] == ',') {

                if (field == 0) r.id = temp;
                else if (field == 1) r.age = stoi(temp);
                else if (field == 2) r.transport = temp;
                else if (field == 3) r.distance = stof(temp);
                else if (field == 4) r.emissionFactor = stof(temp);
                else if (field == 5) r.days = stoi(temp);

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

int ResidentArray::getSize() {
    return size;
}

Resident* ResidentArray::getArray() {
    return arr;
}

void ResidentArray::searchByTransport(string target) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Transport Mode [" << target << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].transport == target) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByDistance(float threshold) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Distance > " << threshold << "km ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].distance > threshold) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByAgeRange(int minAge, int maxAge) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Age Range [" << minAge << " - " << maxAge << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].age >= minAge && arr[i].age <= maxAge) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByTransport(string target) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Transport Mode [" << target << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].transport == target) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByDistance(float threshold) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Distance > " << threshold << "km ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].distance > threshold) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}

void ResidentArray::searchByAgeRange(int minAge, int maxAge) {
    clock_t start = clock();
    int found = 0;
    cout << "\n--- Search: Age Range [" << minAge << " - " << maxAge << "] ---\n";
    for (int i = 0; i < size; i++) {
        if (arr[i].age >= minAge && arr[i].age <= maxAge) found++;
    }
    clock_t end = clock();
    cout << "Found: " << found << " | Time: " << fixed << setprecision(6) << (double)(end - start) / CLOCKS_PER_SEC << "s\n";
}