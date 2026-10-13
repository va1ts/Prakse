#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool pareizsKontaNumurs(string numurs){
    int i;
    if (numurs.length() != 21){
        return false;
    }
    if (numurs[4] != 'H' || numurs[5] != 'A' || numurs[6] != 'B' || numurs[7] != 'A'){
        return false;
    }
    for (int i = 2; i < 21; i++){
        if(i >= 4 && i <=7)
        continue;
    }
    if(!isdigit(numurs[i])){
        return false;
    }
    return true;
}
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
void bankasIzvele(double &bilance){
    int izvele;

    while (true){
        cout << "\nKo velaties darit?\n";
        cout << "1. Apskatit bilanci\n";
        cout << "2. Pielikt naudu\n";
        cout << "3. Iznemt naudu\n";
        cout << "4. Iziet\n";
        cout << "Izvele: ";
        cin >> izvele;

        if (izvele == 1){
            cout << "Jusu bilance: " << bilance << " EUR\n";
        }
        else if (izvele == 2){
            double summa;

            cout << "Cik daudz naudas pielikt? ";
            cin >> summa;

            if (summa > 0){
                bilance += summa;
                cout << "Nauda veiksmigi pielikta!\n";
                cout << "Jauna bilance: " << bilance << " EUR\n";
            }
        }
        else if (izvele == 3){
            double summa;

            cout << "Cik daudz naudas iznemsiet?: ";
            cin >> summa;

            if (summa <= 0){
                cout << "Summai jabut lielakai par 0!\n";
            }
            else if (summa > bilance){
                cout << "Nepietiek naudas konta!\n";
            }
            else {
                bilance -= summa;
                cout << "Nauda veiksmigi iznemta!\n";
                cout << "Jauna bilance: " << bilance << " EUR\n";
            }
        }
        else if (izvele == 4){
            break;
        }
        else {
            cout << "Nepareiza izvele!\n";
        }
    }
}   
int registracija() {
    string lietotaja_vards;
    string lietotaja_uzvards;
    string lietotaja_personaskods;
    string lietotaja_parole;
    string kontaNumurs;
    double bilance;

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
    while(true){
        cout << "Ievadi savu Bankas konta numuru: ";
        cin >> kontaNumurs;

        if(pareizsKontaNumurs(kontaNumurs)){
            cout << "Nepareizi ievadits Bankas konta numurs! Ievadi Velreiz: ";
            continue;
        }
        break;  
    }
    cout << "Ievadiet savu konta bilanci: ";
    cin >> bilance;

    cout << "\nRegistracija veiksmiga!\n";
    ofstream fails("BankasLietotaji.txt", ios::app);

    fails << lietotaja_vards << " "
          << lietotaja_uzvards << " "
          << lietotaja_personaskods << " "
          << lietotaja_parole << " "
          << kontaNumurs << " "
          << bilance;
    fails.close();
    return 0;
}
int pieslegties() {
    string ievaditaPersonasKods;
    string ievaditaParole;

    ifstream fails("BankasLietotaji.txt");

    if (!fails) {
        cout << "Neizdevas atvert failu!\n";
        return 1;
    }

    while (true) {

        cout << "Ievadiet savu Personas Kodu: ";
        cin >> ievaditaPersonasKods;

        cout << "Ievadiet savu paroli: ";
        cin >> ievaditaParole;

        fails.clear();
        fails.seekg(0);

        string vards;
        string uzvards;
        string personaskods;
        string parole;
        string kontaNumurs;
        double bilance;

        bool atrasts = false;

        while (fails >> vards >> uzvards >> personaskods >> parole >> kontaNumurs >> bilance) {

            if (ievaditaPersonasKods == personaskods && ievaditaParole == parole) {

                atrasts = true;

                cout << "Veiksmigi pieslegts!\n\n";
                cout << "Sveiki, " << vards << "!\n";

                bankasIzvele(bilance);

                break;
            }    
        }
        if (atrasts) {
            break;
        }
        cout << "Nepareizs Personas kods vai parole!\n";
        cout << "Meginiet velreiz.\n\n";
    }
    fails.close();
    return 0;
}
string lietotajaDati() {
    string vards;
    string uzvards;
    string personaskods;
    string parole;
    string kontaNumurs;
    double bilance;
    ifstream fails("BankasLietotaji.txt");

    if (!fails) {
        cout << "Neizdevas atvert failu!\n";
        return "";
    }

    while (fails >> vards >> uzvards >> personaskods >> parole >> kontaNumurs >> bilance) {
        cout << "Bankas Konts: " << kontaNumurs << "\n";
    }
    fails.close();
    return "";
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

int main() {
    int izveleRezultats = izvele();

    if (izveleRezultats == 1) {
        registracija();
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