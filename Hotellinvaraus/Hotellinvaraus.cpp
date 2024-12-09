
// Eino Lausmaa Hotellihuoneen varausohjelma 4-5p
// lis�tty ominaisuus: varausten poistaminen

#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <cstdlib>


using namespace std;


// varauksissa k�ytett�v�n structin alustus
struct Huone {
    int huoneenNumero;
    int varausNumero;
    string varaajanNimi;
    bool varattu;
    bool yhdenHengenHuone;
    int hinta;
};


// Luo huoneet ohjelman arpoman huonem��r�n perusteella
vector<Huone> luoHuoneet(int huoneidenMaara) {
    vector<Huone> kaikkiHuoneet;
    for (int i = 1; i <= huoneidenMaara; i++) {
        Huone huone;
        huone.huoneenNumero = i;
        huone.varattu = false;
        huone.yhdenHengenHuone = (i <= huoneidenMaara / 2); // Tekee ensimm�isest� puoliskosta huoneita yhden hengen ja lopuista kahden hengen huoneita
        kaikkiHuoneet.push_back(huone);
    }
    return kaikkiHuoneet;
}


// Tarkistaa huoneen varauksessa ett� huonetta ei ole viel� varattu ja palauttaa sen bool arvon.
bool tarkistetaanOnkoHuoneVarattu(const vector<Huone>& kaikkiHuoneet, int huoneenNumero, bool yhdenHengenHuone) {
    return kaikkiHuoneet[huoneenNumero - 1].varattu == false && kaikkiHuoneet[huoneenNumero - 1].yhdenHengenHuone == yhdenHengenHuone;
}


// Laskee varauksen hinnan ja oottaa siin� arvotun alennuksen huomioon.
int lopullisenHinnanLaskeminen(int hinta, int oidenMaara, int alennus) {
    return (hinta * oidenMaara * (100 - alennus)) / 100;
}


// K�ytet��n sy�tteen tarkastuksessa, jos k�ytt�j� pist�� v��r�nlaisen sy�tteen. K�yt�nn�ss� tyhjent�� sy�tteen seuraavaa yrityst� varten.
void syotteenTarkastus() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    system("cls");
}


// etsii vectorista huoneen jossa on tallennettuna k�ytt�j�n antaman varausnumero ja tulostaa siit� huoneesta varaajan nimen ja huoneen numeron.
void hakeeHuoneenVarausnumerolla(vector<Huone>& kaikkiHuoneet, int varausNumero) {
    bool loytyi = false;
    for (auto& huone : kaikkiHuoneet) {
        if (huone.varausNumero == varausNumero) {

            int valinta = 0;
            while (valinta != 1 && valinta != 2) {
                system("cls");
                cout << "----------| Haun valikko |----------\n\n";
                cout << "\nVaraaja: " << huone.varaajanNimi << ", Huonenumero: " << huone.huoneenNumero << endl;
                loytyi = true;

                cout << "\n\n[1]Jatka valikkoon.\n[2]Poista varaus.\n\n:";
                cin >> valinta;
                system("cls");

                if (valinta == 1)
                    break;
                else if (valinta == 2) {

                    huone.varausNumero = 0;
                    huone.varaajanNimi = "";
                    huone.varattu = false;
                    huone.hinta = 0;

                    cout << "Varaus on poistettu, kiitos k�ynnist�!\n";
                }
                else if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "Valitse vaihtoehto v�lilt� 1-2\n";
                }
                else {
                    cout << "Valitse vaihtoehto v�lilt� 1-2\n";
                }
            }


            break;
        }
    }
    if (!loytyi) {
        cout << "Varausta ei l�ytynyt.\n";
    }

    cout << "\nPaina Enter jatkaaksesi...";
    cin.get();
    system("cls");
}


// Etsii vectorista huoneen jossa on tallennettuna k�ytt�j�n antama varaajan nimi ja tulostaa siit� huoneesta varaajan varausnumeron ja huoneen numeron.
void hakeeHuoneenVaraajalla(vector<Huone>& kaikkiHuoneet, string varaajanNimi) {
    bool loytyi = false;
    for (auto& huone : kaikkiHuoneet) {
        if (huone.varaajanNimi == varaajanNimi) {


            int valinta = 0;
            while (valinta != 1 && valinta != 2) {
                system("cls");
                cout << "----------| Haun valikko |----------\n\n";
                cout << "\nVarausnumero: " << huone.varausNumero << ", Huonenumero: " << huone.huoneenNumero << endl;
                loytyi = true;
                
                cout <<"\n\n[1]Jatka valikkoon.\n[2]Poista varaus.\n\n:";
                cin >> valinta;
                system("cls");

                if (valinta == 1)
                    break;
                else if (valinta == 2) {

                    huone.varausNumero = 0;
                    huone.varaajanNimi = "";
                    huone.varattu = false;
                    huone.hinta = 0;

                    cout << "Varaus on poistettu, kiitos k�ynnist�!\n";
                }
                else if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "Valitse vaihtoehto v�lilt� 1-2\n";
                }
                else {
                    cout << "Valitse vaihtoehto v�lilt� 1-2\n";
                }
            }


            break;
        }
    }
    if (!loytyi) {
        cout << "Varausta ei l�ytynyt.\n";
    }

    cout << "\nPaina Enter jatkaaksesi...";
    cin.get();
    system("cls");
}


int main() {
    setlocale(LC_ALL, "fi-FI");
    srand(time(0));


    // Huoneiden m��r�n arpominen, alustaminen ja muuta alustamista ohjelmaa varten
    int huoneidenMaara = (rand() % 261) + 40;
    int yhdenHengenHuoneidenMaara = huoneidenMaara / 2;
    vector<Huone> kaikkiHuoneet = luoHuoneet(huoneidenMaara);
    int yhdenHengenHuoneenHinta = (rand() % 21) + 80;               // Random hinta v�lilt� 80-100
    int kahdenHengenHuoneenHinta = yhdenHengenHuoneenHinta + 50;    // Tekee kahden hengen huoneesta 50� kalliimman

    int menuMuuttuja;

    while (true) {
        cout << "----------| Hotellin varaus systeemi |----------\n\n";
        cout << "[1] Varaa huone.\n[2] Hae huonetta.\n[3] Sulje ohjelma.\n\n: ";
        cin >> menuMuuttuja;
        system("cls");

        if (menuMuuttuja == 1) {
            system("cls");


            // Huoneen varaamisessa k�ytett�v�t muuttujat luokittain.
            int huoneenkoko = 0, huoneenNumero = 0, oidenMaara = 0, arvotaankoHuoneenNumero = 0;
            bool yhdenHengenHuone = 0;
            string varaajanNimi;


            // K�ytt�j� valitsee onko huonen yhden hengen vai kahden hengen.
            while (huoneenkoko != 1 && huoneenkoko != 2) {
                cout << "----------| Huoneen varaus |----------\n\n";
                cout << "Kuinka monen hengen huoneen haluat(1-2)?\n\n: ";
                cin >> huoneenkoko;
                system("cls");
                
                if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "\nValitse huoneen kooksi joko 1 tai 2 (hekil��).\n\n";
                }
                else if (huoneenkoko != 1 && huoneenkoko != 2) {
                    cout << "\nValitse huoneen kooksi joko 1 tai 2 (hekil��).\n\n";
                }
            }

            yhdenHengenHuone = (huoneenkoko == 1); //Jos k�ytt�j� valitsee yhden hengen, muuttaa bool arvon todeksi.



            while (arvotaankoHuoneenNumero != 1 && arvotaankoHuoneenNumero != 2) {
                cout << "----------| Huoneen varaus |----------\n\n";
                cout << "[1] Valitse huoneen numero itse.\n[2] Arvo huoneen numero\n\n: ";
                cin >> arvotaankoHuoneenNumero;
                system("cls");

                if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "Valitse vaihtoehtojen 1 ja 2 v�lill�.\n\n";
                }
                else if (arvotaankoHuoneenNumero != 1 && arvotaankoHuoneenNumero != 2) {
                    cout << "Valitse vaihtoehtojen 1 ja 2 v�lill�.\n\n";
                }
            }

            // K�ytt�j� valitsee itse oman huoneen numeron ja senn varattavuus varmistetaan aliohjelmassa.
            // Ohjelma n�ytt�� varaajalle eri huoneiden numero v�lin riippuen siit� onko huone yhden hengen vai kahden.
            if (arvotaankoHuoneenNumero == 1) {
                if (yhdenHengenHuone == true) {
                    while (huoneenNumero < 1 || huoneenNumero > yhdenHengenHuoneidenMaara || !tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone)) {
                        cout << "----------| Huoneen varaus |----------\n\n";
                        cout << "Valitse huoneen numero v�lilt� 1-" << yhdenHengenHuoneidenMaara << "\n\n: ";
                        cin >> huoneenNumero;
                        system("cls");

                        if (cin.fail()) {
                            syotteenTarkastus();
                        }

                        else if (tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone) == false)
                            cout << "\nT�m� huone on jo varattu, valitse toinen huone.";
                    }
                }
                else {
                    while (huoneenNumero <= yhdenHengenHuoneidenMaara || huoneenNumero > huoneidenMaara || !tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone)) {
                        cout << "----------| Huoneen varaus |----------\n\n";
                        cout << "Valitse huoneen numero v�lilt� " << yhdenHengenHuoneidenMaara + 1 << "-" << huoneidenMaara << "\n\n: ";
                        cin >> huoneenNumero;
                        system("cls");

                        if (cin.fail()) {
                            syotteenTarkastus();
                        }

                        else if (tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone) == false)
                            cout << "\nT�m� huone on jo varattu, valitse toinen huone.";
                    }
                }
            }

            // Arpoo huoneen numeron ja tarkistaa sen varattavuuden aliohjelmassa.
            // Ohjelma arpoo sen eri numerov�lilt� riippuen siit� onko kyseess� yhden hengen vai kahden.
            else if (arvotaankoHuoneenNumero == 2) {
                if (yhdenHengenHuone == true) {
                    do {
                        huoneenNumero = rand() % yhdenHengenHuoneidenMaara + 1;
                    } while (huoneenNumero < 1 || huoneenNumero > yhdenHengenHuoneidenMaara || !tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone));
                }
                else {
                    do {
                        huoneenNumero = (rand() % yhdenHengenHuoneidenMaara + 1) + yhdenHengenHuoneidenMaara;
                    } while (huoneenNumero <= yhdenHengenHuoneidenMaara || huoneenNumero > huoneidenMaara || !tarkistetaanOnkoHuoneVarattu(kaikkiHuoneet, huoneenNumero, yhdenHengenHuone));
                }
            }

            // k�ytt�j� valitsee montako y�t� varaus kest��
            do {
                system("cls");
                cout << "----------| Huoneen varaus |----------\n\n";
                cout << "Kuinka moneksi y�ksi varaat huoneen?\n\n: ";
                cin >> oidenMaara;

                if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "Sy�tteen t�ytyy olla numero!\n\n";
                }
                else
                    break;
            } while (true);
            

            // Kysyy varaajan nimen.
            system("cls");
            cout << "----------| Huoneen varaus |----------\n\n";
            cout << "Anna nimi jolla varaus tehd��n: ";
            cin.ignore();
            getline(cin, varaajanNimi);     // Tallentaa varaajan nimeksi koko kirjoitetun linen.


            // Arpoo varaukselle alennusprosentin ja laskee aliohjelmalla lopullisen hinnan.
            int alennus = (rand() % 3) * 10;
            int hinta = yhdenHengenHuone ? yhdenHengenHuoneenHinta : kahdenHengenHuoneenHinta;
            int loppusumma = lopullisenHinnanLaskeminen(hinta, oidenMaara, alennus);

            //Arpoo varaukselle varausnumeron ja kaiken aiemmin saadun datan vectoriin.
            int varausnumero = (rand() % 90000) + 10000;
            kaikkiHuoneet[huoneenNumero - 1].varattu = true;
            kaikkiHuoneet[huoneenNumero - 1].varausNumero = varausnumero;
            kaikkiHuoneet[huoneenNumero - 1].varaajanNimi = varaajanNimi;
            kaikkiHuoneet[huoneenNumero - 1].hinta = loppusumma;


            // Tulostaa k�ytt�j�lle varausnumeron ja antaa laskun loppusumman.
            system("cls");
            cout << "----------| Huoneen varaus |----------\n\n";
            cout << "Varausnumero: " << varausnumero << endl;
            cout << "Laskun loppusumma (alennus " << alennus << "%): " << loppusumma << " euroa" << endl;
            cout << "\nPaina Enter jatkaaksesi...";
            cin.get();
            system("cls");
        }



        else if (menuMuuttuja == 2) {
            system("cls");


            // Hakemisessa k�ytett�v�t muuttujat.
            int haku = 0, varausnumero;
            string varaajanNimi;

            
            while (haku != 1 && haku != 2) {
                cout << "----------| Haun valikko |----------\n\n";
                cout << "[1] Hae varausnumerolla\n[2] Hae varaajan nimell�\n\n: ";
                cin >> haku;
                system("cls");


                // hakee huoneen varausnumerolla aliohjelman avulla.
                if (haku == 1) {
                    cout << "----------| Haun valikko |----------\n\n";
                    cout << "\nAnna varausnumero: ";
                    cin >> varausnumero;
                    hakeeHuoneenVarausnumerolla(kaikkiHuoneet, varausnumero);
                }


                //Hakee huoneen varaajan nimell� aliohjelman avulla.
                else if (haku == 2) {
                    cout << "----------| Haun valikko |----------\n\n";
                    cout << "\nAnna varaajan nimi: ";
                    cin.ignore();
                    getline(cin, varaajanNimi);
                    hakeeHuoneenVaraajalla(kaikkiHuoneet, varaajanNimi);
                }


                else if (cin.fail()) {
                    syotteenTarkastus();
                    cout << "Valitse vaihtoehtojen 1 ja 2 v�lill�.\n\n";
                }


                else {
                    cout << "Valitse vaihtoehtojen 1 ja 2 v�lill�.\n\n";
                }
            }
        }

        // Sulkee ohjelman
        else if (menuMuuttuja == 3) {
            system("cls");

            cout << "Kiitos asioinnista!";
            break;
        }


        // Syotteen tarkastusta.
        else if (cin.fail()) {
            syotteenTarkastus();
            cout << "Valitse joku vaihtoehdoista kirjoittamalla numero 1-3.\n\n";
        }
        else {
            cout << "Valitse joku vaihtoehdoista kirjoittamalla numero 1-3.\n\n";
        }
    }

     return 0;
}

