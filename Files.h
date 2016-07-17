#ifndef FILES_H
#define FILES_H
//Dependencies
#include <vector>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include "Car.h"

using namespace std;

int saveCars(vector<Car>,string);
void loadCars(vector <Car>*, string);
bool filexist(string);

#endif // FILES_H
