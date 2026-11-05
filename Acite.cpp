#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
using namespace std;


struct Karts {
    string nosakums;
    string masts;
    int vertiba;
};
    vector<Karts> speletajaRoka;
    vector<Karts> datoraRoka;
    vector<Karts> kava;

int izveidotKavu() {
    string nosaukumi[] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string masti[] = {"Pīķis", "Kreicis", "Ercens", "Kārava"};
    int vertibas[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 4; j++) {
            Karts karte;
            karte.nosakums = nosaukumi[i];
            karte.masts = masti[j];
            karte.vertiba = vertibas[i];
            kava.push_back(karte);
        }
    }
    return kava.size();
}
int sajauktKavu(int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        swap(kava[i], kava[j]);
    }
    return 0;
}
Karts vilktKarti(){
    if (kava.empty()) {
        cout << "Kava ir iztukšota!" << endl;
        exit(0);
    }
    Karts karte = kava.back();
    kava.pop_back();
    cout << "Vilktā karte: " << karte.nosakums << " " << karte.masts << endl;
    return karte;
}

int aprekinatSummu(const vector<Karts>& roka) {
    int summa = 0;
    int duzi = 0;
    for (int i = 0; i < roka.size(); i++) {
        summa += roka[i].vertiba;
        if (roka[i].nosakums == "A") duzi++;
    }
    while (summa > 21 && duzi > 0) {
        summa -= 10;   // viens dūzis 11 vietā skaitās 1
        duzi--;
    }
    return summa;
}
string simbols(const string& masts) {
    if (masts == "Pīķis")   return "♠";
    if (masts == "Kreicis") return "♣";
    if (masts == "Ercens")  return "♥";
    return "♦";
}
void zimetRoku(const vector<Karts>& roka, bool slept = false) {
    for (int rinda = 0; rinda < 5; rinda++) {
        for (int i = 0; i < roka.size(); i++) {
            bool apslepta = slept && i == 1;
            string n = roka[i].nosakums;
            if (n.size() == 1) n += " ";          // "K " un "10" ir vienā platumā
            string s = simbols(roka[i].masts);

            if (rinda == 0) cout << "┌───────┐ ";
            if (rinda == 1) cout << (apslepta ? "│░░░░░░░│ " : "│" + n + "     │ ");
            if (rinda == 2) cout << (apslepta ? "│░░░░░░░│ " : "│   " + s + "   │ ");
            if (rinda == 3) cout << (apslepta ? "│░░░░░░░│ " : "│     " + n + "│ ");
            if (rinda == 4) cout << "└───────┘ ";
        }
        cout << endl;
    }
}
void zimetGaldu(bool sleptDatoru){
    system("cls");
    cout << R"(
   _      _ _
  /_\  __(_) |_ ___
 / _ \/ _| |  _/ -_)
/_/ \_\__|_|\__\___|
)" << endl;
    cout << "Datora roka:" << endl;
    zimetRoku(datoraRoka, sleptDatoru);
    if (!sleptDatoru) {
        cout << "Datora summa: " << aprekinatSummu(datoraRoka) << endl;
    }
    cout << endl;
    cout << "Tava roka:" << endl;
    zimetRoku(speletajaRoka);
    cout << "Tava summa: " << aprekinatSummu(speletajaRoka) << endl;
    cout << endl;
}
int speletajaGajiens() {
    zimetGaldu(true);
    cout << "1. Vilkt karti" << endl;
    cout << "2. Nevilkt" << endl;
    int izvele;
    cin >> izvele;
    if (cin.fail()) {          // ja ievadīts burts, nevis skaitlis
        cin.clear();
        cin.ignore(1000, '\n');
        return 0;
    }
    switch (izvele) {
        case 1:
            speletajaRoka.push_back(vilktKarti());
            break;
        case 2:
            return -1; // Speletajs beidz gajienu
        default:
            break;
    }
    return 0;
}
int datoraGajiens() {
    if (aprekinatSummu(datoraRoka) >= 17) {
        return -1;
    }
    datoraRoka.push_back(vilktKarti());
    return 0;
}
int noteiktUzvaretaju() {
    int speletajaSumma = aprekinatSummu(speletajaRoka);
    int datoraSumma = aprekinatSummu(datoraRoka);
    if (speletajaSumma > datoraSumma) {
        cout << "Speletajs uzvare!" << endl;
    } else if (speletajaSumma < datoraSumma) {
        cout << "Dators uzvareja!" << endl;
    } else {
        cout << "Neizskirts!" << endl;
    }
    return 0;
}
int main() {
    system("chcp 65001 > nul");
    srand(time(0));
    int n = izveidotKavu();
    sajauktKavu(n);


    speletajaRoka.push_back(vilktKarti());
    speletajaRoka.push_back(vilktKarti());
    datoraRoka.push_back(vilktKarti());
    datoraRoka.push_back(vilktKarti());

    while (true) {
        int rezultats = speletajaGajiens();
        if (rezultats == -1) {
            break;
        }
        if (aprekinatSummu(speletajaRoka) > 21) {
            zimetGaldu(false);
            cout << "Parsniegts 21. Tu zaudeji!" << endl;
            return 0;
        }
    }
 
    while (true) {
        int rezultats = datoraGajiens();
        if (rezultats == -1) {
            break;
        }
        if (aprekinatSummu(datoraRoka) > 21) {
            zimetGaldu(false);
            cout << "Dators parsniedza 21. Tu uzvareji!" << endl;
            return 0;
        }
    }
    zimetGaldu(false);
    noteiktUzvaretaju();
    return 0;
}