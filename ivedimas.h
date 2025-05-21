#pragma once

#include "headers.h"
#include "studentas.h"

void vardo_pavardes_ivedimas(vector<studentas> &S, studentas &s, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void ivedimas_ranka(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojami_pazymiai(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void generuojama_viskas(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde);
void skaitymas_is_failo_logika(vector<studentas> &S, int &ilgiausias_vardas, int &ilgiausia_pavarde, path &failas);
