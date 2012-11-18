#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"

#include <iostream>
#include <string>
#include <ostream>

using namespace std;

void instrukcja();
void dodawanie();
void usuwanie();
void formatowanie();
void wyswietlanie();
void wyjscie();
void zapisz();
void wczytaj();

int menu()

{

    cout << "1 - Instrukcja" << endl;
    cout << "2 - Dodawanie zdjecia" << endl;
    cout << "3 - Usuwanie zdjecia" << endl;
    cout << "4 - Usuwanie wszystkich zdjec z albumu" << endl;
    cout << "5 - Wyswietlanie zawartosci albumu" << endl;
    cout << "6 - Zapisywanie albumu do pliku" << endl;
    cout << "7 - Wczytywanie albumu z pliku" << endl;
    cout << "8 - Wyj�cie z programu" << endl;

    cout << "Kt�r� funkcj� chcesz wybra�?" << endl;

    int pytanie;

    cin >> pytanie;


    switch(pytanie)
    {
        case 1: instrukcja();       // instrukcja
                break;
        case 2: dodawanie(); // dodawanie
                break;
        case 3: usuwanie(); // usuwanie zdjecia z albumu
                break;
        case 4: formatowanie();     // usuwanie wszystkiego
                break;
        case 5: wyswietlanie();     // wypisywanie
                break;
        case 6: zapisz();     // zapis stanu do pliku
                break;
        case 6: wczytaj();     // wczytywanie danych z pliku
                break;
        case 8: wyjscie();     // wyj�cie z programu
                break;
    }
    return pytanie;            // zwraca warto�� do por�wnania.
}


void instrukcja()
{
    cout << "Interaktywny program pozwalaj�cy na opanowanie kolekcji zdj��." << endl;
    cout << "Program pozwala na nadanie zdj�ciu do pi�ciu r�nych kategorii," << endl;
    cout << "pozwala r�wnie� wyszukiwa� zdj�cia wed�ug nazwy, daty utworzenia," << endl;
    cout << "oraz przypisanych kategorii. Zycze milej zabawy!" << endl;
}

void dodawanie()
{
    int dd, mm, yyyy;
    string title;

    cout << endl << "Dodawanie zdjec." << endl << endl;
    cout << "Podaj nazw� dodawanego zdj�cia" << endl;
    cin >> title;

    cout << "Podaj dzien uwtorzenia zdjecia" << endl;
    cin >> dd;
    cout << "Podaj miesiac uwtorzenia zdjecia" << endl;
    cin >> mm;
    cout << "Podaj rok uwtorzenia zdjecia" << endl;
    cin >> yyyy;
    Date d(dd, mm, yyyy);

    cout << "Podaj ilosc tagow, ktora chcesz przypisac do zdjecia" << endl;
    int ilosc;
    if ilosc > 5 cout << "Blad, wybierz mniejsza liczbe!";
    if ilosc=0 cout << "Brak tagow do dodania";
    else{
    TagList tl;
    for (i=1, i<ilosc+1, i++)
    {
        string nazwatagu;
        string wagatagu;
        cout << "Podaj nazwe kategorii, ktora chcesz przypisac do zdjecia (tag)" << endl;
        cin >> nazwatagu;
        cout << "Podaj wage dodanego tagu" << endl;
        cin >> wagatagu;
        tl.add(Tag(nazwatagu, wagatagu));
        cout << "Dodano tag " << i << " z " << ilosc << endl;
        cout << "Dodawanie tagu " << i+1 << " z " << ilosc <<" w toku."<< endl;
        }
    }
    Photo p(title, const Date& d, const TagList& tl);
    cout << "Zdjecie dodano do albumu"<<endl;

}

void usuwanie()
{
    cout <<  endl << "Oto zako�czenie." << endl << endl;
}

void formatowanie()
{
    cout <<  endl << "Oto zako�czenie." << endl << endl;
}

void wyswietlanie()
{
    cout <<  endl << "Oto zako�czenie." << endl << endl;
}

void wczytaj()
{
    //tu bedzie cos, co ogarnia wczytywanie
}

void zapisz()
{
    //cos, co bedzie zapisywac
}

void wyjscie()
{
    cout << endl <<  "Wyj�cie z programu." << endl << endl;
}

int main(int argc, char *argv[])

{

    int wyjscie = 0;  // tworzymy zmienn� int kt�ra b�dzie si� r�wna� 0

    do

    {

      wyjscie = menu();     // wywo�anie funkcji menu()

    }while (wyjscie != 4);  // sprawdzenie co zwraca funkcja menu

                            // gdy inna ni� 4 menu pojawi si� od nowa



}
