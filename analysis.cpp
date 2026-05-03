#include "analysis.h"

string ageGroups[5] = {
    "6-17",
    "18-25",
    "26-45",
    "46-60",
    "61-100"
};

string transportTypes[6] = {
    "Car",
    "Bus",
    "Bicycle",
    "Walking",
    "School Bus",
    "Carpool"
};

float calculateEmission(Resident r) {
    return r.distance * r.emissionFactor * r.days;
}

int getAgeGroupIndex(int age) {
    if (age >= 6 && age <= 17) {
        return 0;
    }
    else if (age >= 18 && age <= 25) {
        return 1;
    }
    else if (age >= 26 && age <= 45) {
        return 2;
    }
    else if (age >= 46 && age <= 60) {
        return 3;
    }
    else {
        return 4;
    }
}

void printAnalysisTable(float totalEmission[], int residentCount[], int transportCount[][6], string cityName, string structureName) {
    cout << "\n===============================================================\n";
    cout << "      CARBON EMISSION ANALYSIS - " << cityName << " (" << structureName << ")\n";
    cout << "===============================================================\n";

    cout << left
         << setw(12) << "Age Group"
         << setw(15) << "Residents"
         << setw(20) << "Total Emission"
         << setw(20) << "Average Emission"
         << setw(20) << "Most Used Mode"
         << endl;

    cout << "---------------------------------------------------------------------------------------\n";

    cout << fixed << setprecision(2);

    for (int i = 0; i < 5; i++) {
        if (residentCount[i] == 0) {
            cout << left
                 << setw(12) << ageGroups[i]
                 << setw(15) << 0
                 << setw(20) << 0.00
                 << setw(20) << 0.00
                 << setw(20) << "N/A"
                 << endl;
        }
        else {
            float averageEmission = totalEmission[i] / residentCount[i];

            int maxIndex = 0;
            for (int j = 1; j < 6; j++) {
                if (transportCount[i][j] > transportCount[i][maxIndex]) {
                    maxIndex = j;
                }
            }

            cout << left
                 << setw(12) << ageGroups[i]
                 << setw(15) << residentCount[i]
                 << setw(20) << totalEmission[i]
                 << setw(20) << averageEmission
                 << setw(20) << transportTypes[maxIndex]
                 << endl;
        }
    }
}

void analyzeArray(Resident arr[], int size, string cityName) {
    float totalEmission[5] = {0, 0, 0, 0, 0};
    int residentCount[5] = {0, 0, 0, 0, 0};
    int transportCount[5][6] = {0};

    for (int i = 0; i < size; i++) {
        int groupIndex = getAgeGroupIndex(arr[i].age);
        float emission = calculateEmission(arr[i]);

        totalEmission[groupIndex] += emission;
        residentCount[groupIndex]++;

        for (int j = 0; j < 6; j++) {
            if (arr[i].transport == transportTypes[j]) {
                transportCount[groupIndex][j]++;
            }
        }
    }

    printAnalysisTable(totalEmission, residentCount, transportCount, cityName, "Array");
}

void analyzeLinkedList(Node* head, string cityName) {
    float totalEmission[5] = {0, 0, 0, 0, 0};
    int residentCount[5] = {0, 0, 0, 0, 0};
    int transportCount[5][6] = {0};

    Node* current = head;

    while (current != NULL) {
        int groupIndex = getAgeGroupIndex(current->data.age);
        float emission = calculateEmission(current->data);

        totalEmission[groupIndex] += emission;
        residentCount[groupIndex]++;

        for (int j = 0; j < 6; j++) {
            if (current->data.transport == transportTypes[j]) {
                transportCount[groupIndex][j]++;
            }
        }

        current = current->next;
    }

    printAnalysisTable(totalEmission, residentCount, transportCount, cityName, "Linked List");
}