#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;


int main(){
    double S;
    int n;
    string inputFilePath = "./data.txt";
    string outputFileName = "./result.txt";
    vector<double> w;
    vector<double> r;
    double V;
    double tasso_ritorno;

    // prendo i dati da data
    LeggiFile(inputFilePath,S,n,w,r);

    // calcolo il tasso e la V
    CalcolaTasso(w,r,S,tasso_ritorno,V);

    // scrivo sul file result
    ScriviFile(outputFileName, S, n, w, r, tasso_ritorno, V);
    return 0;
    
}
