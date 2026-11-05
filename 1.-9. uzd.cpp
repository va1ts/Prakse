#include <iostream>
#include <string>
using namespace std;

// 1.uzd int main(){
//     string lietotaja_vards;
//     int lietotaja_vecums;
//     cout << "Ievadiet savu vardu: ";
//     cin >> lietotaja_vards;
//     cout << "Ievadiet savu vecumu: ";
//     cin >> lietotaja_vecums;
//     cout << "Jus esat " << lietotaja_vards << " un jums ir " << lietotaja_vecums << " gadi.";
//     return 0;
// }
// 2. uzd int main(){
//     int temperatura;
//     cout << "Ievadiet temperaturu: ";
//     cin >> temperatura;
//     if (temperatura > 15 && temperatura < 25) {
//         cout << "Patikams laiks!";
//     }
//     else{
//         cout << "Nepatikams laiks!";
//     }
//     return 0;
// }
// 2.1 uzd int main(){
//     int temperatura;
//     int fahrenheit;
//     cout << "Ievadiet temperaturu Celsius: ";
//     cin >> temperatura;
//     fahrenheit = (temperatura * 9/5) + 32;
//     cout << "Temperatura Farenheita: " << fahrenheit;
//     return 0;
// }
// 2.2 uzd int main(){
//     int temperatura;
//     int celsius;
//     cout << "Ievadiet temperaturu Farenheita: ";
//     cin >> temperatura;
//     celsius = (temperatura - 32) * 5/9;
//     cout << "Temperatura Celsius: " << celsius;
//     return 0;
// }
// 2.3 uzd int fahrenheit(){
//     int temperatura;
//     int fahrenheit;
//     cout << "Ievadiet temperaturu Celsius: ";
//     cin >> temperatura;
//     fahrenheit = (temperatura * 9/5) + 32;
//     cout << "Temperatura Farenheita: " << fahrenheit;
//     return 0;
// }
// int celsius(){
//     int temperatura;
//     int celsius;
//     cout << "Ievadiet temperaturu Farenheita: ";
//     cin >> temperatura;
//     celsius = (temperatura - 32) * 5/9;
//     cout << "Temperatura Celsius: " << celsius;
//     return 0;
// }
// int main(){
//     int izvele;
//     cout << "Izvelieties konversijas veidu: ";
//     cout << "\n 1. Celsius uz Farenheita" ;
//     cout << "\n 2. Farenheita uz Celsius";
//     cout << "\n Ievadiet savu izveli: ";
//     cin >> izvele;
//     if (izvele == 1) {
//         fahrenheit();
//     } else if (izvele == 2) {
//         celsius();
//     } else {
//         cout << "Nepareiza izvēle!" << endl;
//     }
//     return 0;
// }
// 3. uzd int main(){
//     int lietotajaIzvele;
//     cout << "Ievadi skaitli no 1 lidz 7: ";
//     cin >> lietotajaIzvele;
//     switch (lietotajaIzvele) {
//         case 1:
//             cout << "Pirmdiena";
//             break;
//         case 2:
//             cout << "Otrdiena";
//             break;
//         case 3:
//             cout << "Trešdiena";
//             break;
//         case 4:
//             cout << "Ceturtdiena";
//             break;
//         case 5:
//             cout << "Piektdiena";
//             break;
//         case 6:
//             cout << "Sestdiena";
//             break;
//         case 7:
//             cout << "Svētdiena";
//             break;
//         default:
//             cout << "Nezinama diena!";
//     }
// 4. uzd int main(){
//     int i, j;
//     for(i = 1; i <= 10; i++){
//         cout << i << "\t";
//     }
//     cout << "\n";
//     for(j = 10; j >= 1; j--){
//         cout << j << "\t";
//     }
//     return 0;
// }
// 5. uzd (ar true\false funkciju) int main(){
//     bool turpinat = true;
//     string parole;
//     while (turpinat) {
//         cout << "Ievadiet paroli: ";
//         cin >> parole;
//         if (parole == "Stop" || parole == "stop") {
//             cout << "Programma Partraukta!";
//             turpinat = false;
//         } 
//         else if(parole == "1234") 
//         {
//             cout << "Parole ir pareiza!";
//             turpinat = false;
//         } 
//         else
//         {
//             cout << "Nepareiza parole! Meginiet velreiz.";
//         }
//     }
//     return 0;
// }
// 5.1 uzd(ar break funckiju) int main(){
//     string parole;
//     while(true){
//         cout << "Ievadiet paroli: ";
//         cin >> parole;
//         if (parole == "Stop" || parole == "stop") {
//             cout << "Programma Partraukta!";
//             break;
//         } 
//         else if(parole == "1234") 
//         {
//             cout << "Parole ir pareiza!";
//             break;
//         } 
//         else
//         {
//             cout << "Nepareiza parole! Meginiet velreiz.";
//         }
//     }
//     return 0;
// }
// 6. uzd. int sveicinat(){
//     string sasveiciens;
//     cout << "Sveiki!";
//     return 0;
// }
// int main(){
//     sveicinat();
//     cout << "\n";
//     sveicinat();
// }
// 7.uzd int main(){
//     int masivs[5] = {4, 7, 2, 9, 1};
//     int kopsumma = 0;
//     for(int i = 0; i < 5; i++){
//         kopsumma += masivs[i];
//         cout << masivs[i] << " ";
//     }
//     cout << "\nKopeja summa: " << kopsumma;
//     return 0;
// }
// 8.uzd int main(){
//     string pareizaParole = "C++2026";
//     while(true){
//         string lietotajaParole;
//         cout << "Ievadiet paroli: ";
//         cin >> lietotajaParole;
//         if (lietotajaParole == pareizaParole) {
//             cout << "Piekluve atlauta!";
//             break;
//         } else {
//             cout << "Piekluve liegta";
//             break;
//         }
//     }
// }
// 9.uzd int main(){
//     int skaitlis1, skaitlis2;
//     int sum;
//     cout << "Ievadiet skaitli: ";
//     cin >> skaitlis1;
//     cout << "\nIevadi otro skaitli: ";
//     cin >> skaitlis2;
//     cout << "Ievadiet kadu no sim zimem: +, -, *, /: ";
//     char simbols;
//     cin >> simbols;
//     switch(simbols){
//         case '+':
//             sum = skaitlis1 + skaitlis2;
//             cout << "Rezultats: " << sum;
//             break;
//         case '-':
//             sum = skaitlis1 - skaitlis2;
//             cout << "Rezultats: " << sum;
//             break;
//         case '*':
//             sum = skaitlis1 * skaitlis2;
//             cout << "Rezultats: " << sum;
//             break;
//         case '/':
//             if (skaitlis2 != 0) {
//                 sum = skaitlis1 / skaitlis2;
//                 cout << "Rezultats: " << sum;
//             } else {
//                 cout << "Dalit ar nulli nav iespejams!";
//             }
//             break;
//         default:
//             cout << "Nepareiza simbols!";   
//     return 0;
//     }
// }