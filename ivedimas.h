#pragma once

#include "headers.h"
#include "studentas.h"

void vardo_pavardes_ivedimas(Container(studentas) &S, studentas &s, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void ivedimas_ranka(Container(studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojami_pazymiai(Container(studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojama_viskas(Container(studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo(Container(studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo_logika(Container(studentas) &S, int &ilgiausias_vardas, int &ilgiausia_pavarde, path &failas);
