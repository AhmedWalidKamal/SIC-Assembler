//
// Created by Walid on 5/3/2017.
//

#include "ReserveWordDirective.h"

int ReserveWordDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {

    int currentLocationCounter = locationCounter;
    locationCounter += (3 *incrementValue);
    return currentLocationCounter;
}