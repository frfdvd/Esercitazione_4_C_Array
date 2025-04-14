#include "Utils.hpp"

#include "fstream"
#include "iostream"
#include "vector"
#include "sstream"
#include "iomanip"

using namespace std;

bool LeggiFile(const string& inputFilePath,
                double& S,
                int& n,
                double*& w,
                double*& r)
{
    // apro il file
    ifstream myfile(inputFilePath);
    if (!myfile) {
        cerr << "Impossibile aprire il file!!!" << endl;
        return false;
    }

    string lineafile;
    vector<string> linea_corrente;


    // leggo le righe del file
    unsigned int contatore = 0; 
    while (getline(myfile, lineafile)) {
        stringstream ss(lineafile);
        string valore;

        // riga per riga metto nel vettore linea_corrente i valori separati da ;
        while (getline(ss, valore, ';')){
            linea_corrente.push_back(valore);
        }
        
        // seleziono caso per caso  
        if (linea_corrente[0]=="S"){
            S = stod(linea_corrente[1]);
        }else if (linea_corrente[0]=="n"){
            n = stoi(linea_corrente[1]);
            w = new double[n];
            r = new double[n];
        }else if (isdigit(linea_corrente[0][0])){
            w[contatore] = stod(linea_corrente[0]);
            r[contatore] = stod(linea_corrente[1]);
            contatore = contatore + 1;
        }   

        // svuoto la lista per prepararmi alla prossima riga 
        linea_corrente.clear();
    }

    // chiudo il file
    myfile.close();

    return true;
}



int CalcolaTasso(const double* const& w,
                const double* const& r,
                const int& n,
                const double& S,
                double& tasso_ritorno,
                double& V)
{
    double contatore = 0.0;
    
    for(int i = 0; i < n; i++){
        contatore = contatore + (1 + r[i])*w[i];
    }
    tasso_ritorno = contatore - 1;
    V = contatore*S;
    
    return 0;
}

bool ScriviFile(const string& outputFileName,
                const double& S,
                const int& n,
                const double* const& w,
                const double* const& r,
                const double& tasso_ritorno,
                const double& V)
{
    // apro il file
    ofstream outfile(outputFileName);
    if (!outfile) {
        cerr << "Impossibile scrivere sul file!!!" << endl;
        return false;
    }

    outfile << fixed << setprecision(2);
    outfile << "S = " << S << ", " << "n = " << n << endl;
    
    outfile << defaultfloat;
    outfile << "w = [ ";
    for (int i = 0; i < n; i++) {
    outfile << w[i] <<' ';
    }
    outfile << "]" << endl;

    outfile << "r = [ ";
    for (int i = 0; i < n; i++) {
        outfile << r[i] << ' ';
    }
    outfile << "]" << endl;
    outfile << "Rate of return of the portfolio: " << tasso_ritorno << endl;
    
    outfile << fixed << setprecision(2);
    outfile << "V: " << V << endl;
    
    // chiudo il file 
    outfile.close();
    return true;
}
