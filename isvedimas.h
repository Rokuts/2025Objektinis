#pragma once

#include "headers.h"
#include "studentas.h"
#include "apskaiciuotas_studentas.h"

void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<apskaiciuotas_studentas> &S, ostream &isvestis, bool ar_rodyti_vidurki);
void lentele(int ilgiausia_pavarde, int ilgiausias_vardas, vector<const apskaiciuotas_studentas*> &S, ostream &isvestis, bool ar_rodyti_vidurki);
void isvedimas_i_ekrana(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S);
void isvedimas_i_faila(int ilgiausia_pavarde, int ilgiausias_vardas, vector<studentas> &S);
void skaidymas_ir_isvedimas_i_du_failus(vector<studentas> &S, int ilgiausia_pavarde, int ilgiausias_vardas);
void skaidymas_ir_isvedimas_i_du_failus_logika(vector<studentas> &S, int ilgiausia_pavarde, int ilgiausias_vardas, int pasirinkimas, path &failas1, path &failas2);
