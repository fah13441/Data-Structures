#ifndef ANALYSIS_H
#define ANALYSIS_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Header/Resident.hpp"
#include "Header/ResidentList.hpp"

using namespace std;

float calculateEmission(Resident r);
int getAgeGroupIndex(int age);

void analyzeArray(Resident arr[], int size, string cityName);
void analyzeLinkedList(Node* head, string cityName);

#endif