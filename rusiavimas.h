#pragma once

#include "headers.h"
#include "apskaiciuotas_studentas.h"

bool compareByVidurkis(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b);
bool compareByMediana(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b);
bool compareByVardas(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b);
bool compareByPavarde(apskaiciuotas_studentas &a, apskaiciuotas_studentas &b);

void kaip_rusiuojam_ir_rusiuojam(Container(apskaiciuotas_studentas) &S);
void sort_pagal_pasirinkima(int pasirinkimas, Container(apskaiciuotas_studentas) &S);
void skaidyti_studentus(Container(apskaiciuotas_studentas) &S, Container(const apskaiciuotas_studentas*) &vargšiukai, Container(const apskaiciuotas_studentas*) &kietiakiai, bool naudoti_vidurki);