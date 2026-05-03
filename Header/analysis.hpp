#ifndef ANALYSIS_HPP
#define ANALYSIS_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include "Resident.hpp"
#include "ResidentList.hpp"

using namespace std;

float calculateEmission(Resident r);
int getAgeGroupIndex(int age);

void analyzeArray(Resident arr[], int size, string cityName);
void analyzeLinkedList(Node* head, string cityName);

#endif