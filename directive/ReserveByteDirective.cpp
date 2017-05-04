//
// Created by Walid on 5/3/2017.
//

#include "ReserveByteDirective.h"

int ReserveByteDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {

    int currentLocationCounter = locationCounter;
    locationCounter += incrementValue;
    return currentLocationCounter;
}