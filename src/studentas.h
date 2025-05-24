#pragma once

#include "headers.h"

struct studentas{
    string vardas, pavarde;
    int egzas;
    vector<int> n;

};

double vidurkis(studentas *s);
double mediana(studentas *s);
