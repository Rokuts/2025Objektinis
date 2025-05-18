#pragma once

#include "headers.h"
#include "studentas.h"
#include "apskaiciuotas_studentas.h"

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<apskaiciuotas_studentas> &S, ostream &isvestis);
void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<const apskaiciuotas_studentas*> &S, ostream &isvestis);
void isvedimas_i_ekrana(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S);
void isvedimas_i_faila(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S);
void skaidymas_ir_isvedimas_i_du_failus(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S);