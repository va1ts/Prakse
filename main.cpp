#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool lietotajaParole(string parole) {
    bool hasLielais = false;
    bool hasMazais = false;
    bool hasSkaitlis = false;
    bool hasSimbols = false;

    for (char c : parole) {
        if (isupper(c))
            hasLielais = true;
        else if (islower(c))
            hasMazais = true;
        else if (isdigit(c))
            hasSkaitlis = true;
        else
            hasSimbols = true;
    }

    return hasLielais && hasMazais && hasSkaitlis && hasSimbols;
}
bool pareizsEpasts(string epasts) {
    size_t at = epasts.find('@');

    size_t punkts = epasts.find('.', at);

    if (at == string::npos || punkts == string::npos) {
        return false;
    }

    return true;
}
int registracija() {
    string lietotaja_vards;
    string lietotaja_uzvards;
    string lietotaja_personaskods;
    string lietotaja_epasts;
    string lietotaja_parole;

    cout << "Ievadiet savu vardu: ";
    cin >> lietotaja_vards;

    cout << "Ievadiet savu uzvardu: ";
    cin >> lietotaja_uzvards;

    while (true) {
        cout << "Ievadiet savu personas kodu: ";
        cin >> lietotaja_personaskods;

        if (lietotaja_personaskods.length() == 11) {
            break;
        }
        cout << "Nepareizs personas kods! Tam jabut 11 cipariem.\n";
    }
    while (true) {
        cout << "Ievadiet savu epasta adresi: ";
        cin >> lietotaja_epasts;

        if (pareizsEpasts(lietotaja_epasts)) {
            break;
        }
        cout << "Nepareizs epasts! Meginiet velreiz.\n";
    }
    while (true) {
        cout << "Ievadiet savu paroli: ";
        cin >> lietotaja_parole;

        if (lietotaja_parole.length() < 8) {
            cout << "Parolei jabut vismaz 8 rakstzimem!\n";
            continue;
        }
        if (!lietotajaParole(lietotaja_parole)) {
            cout << "Parolei jabut vismaz vienam lielajam burtam, vienam mazajam burtam, vienam ciparam un vienam simbolam!\n";
            continue;
        }
        break;
    }
    cout << "\nRegistracija veiksmiga!\n";
    ofstream fails("lietotaji.txt", ios::app);

    fails << lietotaja_vards << " "
          << lietotaja_uzvards << " "
          << lietotaja_personaskods << " "
          << lietotaja_epasts << " "
          << lietotaja_parole;
    fails.close();
    return 0;
}
int pieslegties() {
    string ievaditsEpasts;
    string ievaditaParole;

    ifstream fails("lietotaji.txt");

    if (!fails) {
        cout << "Neizdevas atvert failu!\n";
        return 1;
    }

    while (true) {

        cout << "Ievadiet savu epastu: ";
        cin >> ievaditsEpasts;

        cout << "Ievadiet savu paroli: ";
        cin >> ievaditaParole;

        fails.clear();
        fails.seekg(0);

        string vards;
        string uzvards;
        string personaskods;
        string epasts;
        string parole;

        bool atrasts = false;

        while (fails >> vards >> uzvards >> personaskods >> epasts >> parole) {

            if (ievaditsEpasts == epasts && ievaditaParole == parole) {

                atrasts = true;

                cout << "Veiksmigi pieslegts!\n";
                cout << "Sveiki, " << vards << "!\n";

                break;
            }
        }
        if (atrasts) {
            break;
        }
        cout << "Nepareizs epasts vai parole!\n";
        cout << "Meginiet velreiz.\n\n";
    }
    fails.close();
    return 0;
}
int izvele() {
    int izvele;
    cout << "Izvelieties darbibu:\n";
    cout << "1. Registracija\n";
    cout << "2. Pieslegties\n";
    cout << "Ievadiet savu izveli: ";
    cin >> izvele;
    return izvele;
}
string lietotajaDati() {
    string vards, uzvards, personaskods, epasts, parole;
    ifstream fails("lietotaji.txt");

    if (!fails) {
        cout << "Neizdevas atvert failu!\n";
        return "";
    }

    while (fails >> vards >> uzvards >> personaskods >> epasts >> parole) {
        cout << "Vards: " << vards << "\n";
        cout << "Uzvards: " << uzvards << "\n";
        cout << "Personas kods: " << personaskods << "\n";
        cout << "Epasts: " << epasts << "\n";
        cout << "Parole: " << parole << "\n\n";
    }
    fails.close();
    return "";
}
int main() {
    int izveleRezultats = izvele();

    if (izveleRezultats == 1) {
        registracija();
        lietotajaDati();
    }
    else if (izveleRezultats == 2) {
        pieslegties();
        lietotajaDati();
    }
    else {
        cout << "Nepareiza izvele!\n";
    }

    return 0;
}

