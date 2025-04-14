#pragma once

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


// LeggiFile legge il file e inizializza i valori
// inputFilePath: percorso del file
// S: somma di soldi investiti
// n: lunghezza dei vettori
// w: vettore w risultante
// r: vettore risultante
bool LeggiFile(const string& inputFilePath,
                double& S,
                int& n,
                double*& w,
                double*& r);



// CalcolaTasso calcola il tasso di interesse e il valore del portafoglio alla fine
// w: vettore w contenente le frazione di capitale
// r: vettore r contenente i tassi di ritorno
// tasso_ritorno: variabile di tasso di ritorno
// V: valore capitale alla fine
int CalcolaTasso(const double* const& w,
                const double* const& r,
                const int& n,
                const double& S,
                double& tasso_ritorno,
                double& V);



// ScriviFile scrive su un file il risultato
// outputFileName: percorso del file dove scrivere
// le altre variabili sono le stesse definite prima
bool ScriviFile(const string& outputFileName,
                const double& S,
                const int& n,
                const double* const& w,
                const double* const& r,
                const double& tasso_ritorno,
                const double& V);
