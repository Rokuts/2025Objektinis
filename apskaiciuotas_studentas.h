#pragma once

#include "headers.h"
#include "studentas.h"

struct apskaiciuotas_studentas{
    studentas studentas;
    double vidurkis;
    double mediana;
};

apskaiciuotas_studentas apskaiciuoti_stud(studentas stud);


