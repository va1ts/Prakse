#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <conio.h>
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
            if (n.size() == 1) n += " "; 
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

void zimetPogas(int izvele) {
    string vilkt   = "  VILKT KARTI  ";
    string nevilkt = "    NEVILKT    ";
    string izcelt = "\033[30;47m";
    string parastais = "\033[0m";

    cout << "  " << (izvele == 0 ? izcelt : parastais) << "[" << vilkt << "]" << parastais
         << "     " << (izvele == 1 ? izcelt : parastais) << "[" << nevilkt << "]" << parastais << endl;
    cout << endl << "  <- -> izvelies, Enter apstiprini (vai spied 1 / 2)" << endl;
}

int speletajaGajiens() {
    int izvele = 0; 
    while (true) {
        zimetGaldu(true);
        zimetPogas(izvele);

        int taustins = _getch();
        if (taustins == 0 || taustins == 224) {   
            taustins = _getch();
            if (taustins == 75) izvele = 0;        
            if (taustins == 77) izvele = 1;        
        } else if (taustins == 13) {               
            break;
        } else if (taustins == '1') {
            izvele = 0;
            break;
        } else if (taustins == '2') {
            izvele = 1;
            break;
        }
    }

    if (izvele == 0) {
        speletajaRoka.push_back(vilktKarti());
        return 0;
    }
    return -1; 
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
        cout << "Tu uzvareji!" << endl;
        return 1;
    } else if (speletajaSumma < datoraSumma) {
        cout << "Dators uzvareja!" << endl;
        return -1;
    } else {
        cout << "Neizskirts!" << endl;
        return 0;
    }
}

int spele() {
    kava.clear();
    speletajaRoka.clear();
    datoraRoka.clear();

    int n = izveidotKavu();
    sajauktKavu(n);

    speletajaRoka.push_back(vilktKarti());
    speletajaRoka.push_back(vilktKarti());
    datoraRoka.push_back(vilktKarti());
    datoraRoka.push_back(vilktKarti());

    int speletajaSumma = aprekinatSummu(speletajaRoka);
    int datoraSumma = aprekinatSummu(datoraRoka);
    if (speletajaSumma == 21 || datoraSumma == 21) {
        zimetGaldu(false);
        if (speletajaSumma == 21 && datoraSumma == 21) {
            cout << "Abiem 21! Neizskirts!" << endl;
            return 0;
        } else if (speletajaSumma == 21) {
            cout << "ACITE! Tev 21. Tu uzvareji!" << endl;
            return 1;
        } else {
            cout << "Datoram acite (21). Tu zaudeji!" << endl;
            return -1;
        }
    }

    while (true) {
        int rezultats = speletajaGajiens();
        if (rezultats == -1) {
            break;
        }
        if (aprekinatSummu(speletajaRoka) > 21) {
            zimetGaldu(false);
            cout << "Parsniegts 21. Tu zaudeji!" << endl;
            return -1;
        }
        if (aprekinatSummu(speletajaRoka) == 21) {  
            zimetGaldu(false);
            cout << "Tev 21! Tu uzvareji!" << endl;
            return 1;
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
            return 1;
        }
    }
    zimetGaldu(false);
    if (aprekinatSummu(datoraRoka) == 21) {
        cout << "Datoram 21! Tu zaudeji!" << endl;
        return -1;
    }
    return noteiktUzvaretaju();
}

int main() {
    system("chcp 65001 > nul");
    srand(time(0));

    int uzvaras = 0, zaudejumi = 0, neizskirti = 0;
    char atbilde;

    do {
        int rezultats = spele();
        if (rezultats == 1) uzvaras++;
        else if (rezultats == -1) zaudejumi++;
        else neizskirti++;

        cout << endl;
        cout << "Uzvaras: " << uzvaras << "  Zaudejumi: " << zaudejumi
             << "  Neizskirti: " << neizskirti << endl;
        cout << "Spelet velreiz? (j/n): ";
        atbilde = _getch(); 
    } while (atbilde == 'j' || atbilde == 'J');

    cout << "Paldies par speli!" << endl;
    system("pause");
    return 0;
}