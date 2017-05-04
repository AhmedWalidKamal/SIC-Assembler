//
// Created by Walid on 5/3/2017.
//

#include "StartDirective.h"

int StartDirective :: execute(int& start, int& end, int& locationCounter,int incrementValue) {
    start = incrementValue;
    locationCounter = incrementValue;
    return locationCounter;
}