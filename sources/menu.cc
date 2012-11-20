#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"

#include <iostream>
#include <string>
#include <ostream>
#include <sstream>

//ogolnie nie wiem, jak napisac to, ze te drzewa ze soba rozmawiaja...

using namespace std;

void instrukcja();
void dodawanie(Album& album);
void usuwanie(Album& album);
void formatowanie(Album& album);
void wyswietlanie(Album& album);
void wyjscie();
void zapisz(Album& album);
void wczytaj(Album& album);

void wypisza(Album& album);
void wypiszch(Album& album);
void znajdznazw(Album& album);
void znajdztag(Album& album);
void znajdzdate(Album& album);

int menu(Album& album)

{
	cout << "1 - Instrukcja" << endl;
	cout << "2 - Dodawanie zdjecia" << endl;
	cout << "3 - Usuwanie zdjecia" << endl;
	cout << "4 - Usuwanie wszystkich zdjec z albumu" << endl;
	cout << "5 - Wyświetlanie zawartosci albumu" << endl;
	cout << "6 - Zapisywanie albumu do pliku" << endl;
	cout << "7 - Wczytywanie albumu z pliku" << endl;
	cout << "8 - Wyjscie z programu" << endl << endl;
	cout << "Ktora funkcje chcesz wybrac?" << endl;

	int pytanie;
	cin >> pytanie;

	switch (pytanie)
	{
		case 1: instrukcja();// instrukcja
				break;
		case 2: dodawanie(album);// dodawanie
				break;
		case 3: usuwanie(album);// usuwanie zdjecia z albumu
				break;
		case 4: formatowanie(album);// usuwanie wszystkiego
				break;
		case 5: wyswietlanie(album);// wypisywanie
				break;
		case 6: zapisz(album);// zapis stanu do pliku
				break;
		case 7: wczytaj(album);// wczytywanie danych z pliku
				break;
		case 8: wyjscie();
				break;
    }
	return pytanie; // zwraca wartość do porównania.
}


void instrukcja()
{
	cout << "Interaktywny program pozwalający na opanowanie kolekcji zdjęć." << endl;
	cout << "Program pozwala na nadanie zdjęciu do pięciu różnych kategorii," << endl;
	cout << "pozwala również wyszukiwać zdjęcia według nazwy, daty utworzenia," << endl;
	cout << "oraz przypisanych kategorii. Życzę miłej zabawy!" << endl;
}

void dodawanie(Album& album)
{
	int dd, mm, yyyy;
	string title;

	cout << endl << "Dodawanie zdjec." << endl << endl;
	cout << "Podaj nazwe dodawanego zdjêcia" << endl;
	cin >> title;

	cout << "Podaj dzien utworzenia zdjecia" << endl;
	cin >> dd;
	cout << "Podaj miesiac utworzenia zdjecia" << endl;
	cin >> mm;
	cout << "Podaj rok utworzenia zdjecia" << endl;
	cin >> yyyy;
	Date d(dd, mm, yyyy);

	cout << "Podaj ilosc tagow, ktora chcesz przypisac do zdjecia" << endl;
	int ilosc;
	do {
		cin >> ilosc;
		if (ilosc > 5) {
			cout << "Błąd, wybierz mniejszą liczbę!";
			return;
		}
		if (ilosc < 1)
			cout << "Brak tagów do dodania";
	} while (ilosc > 5 || ilosc < 1);
	TagList tl;
	for (int i = 0; i < ilosc; i++) {
		cout << "Dodawanie tagu " << i+1 << " z " << ilosc <<" w toku."<< endl;
		string nazwatagu;
		unsigned int wagatagu;
		cout << "Podaj nazwe kategorii, ktora chcesz przypisac do zdjecia (tag)" << endl;
		cin >> nazwatagu;
		cout << "Podaj wage dodanego tagu" << endl;
		cin >> wagatagu;
		tl.add(Tag(nazwatagu, wagatagu));
		cout << "Dodano tag " << i + 1 << " z " << ilosc << endl;
	}
	
	if (album.add(new Photo(title, d, tl)))
		cout << "Zdjecie dodano do albumu" << endl;
	else
		cout << "Zdjecia nie dodano do albumu" << endl;
}

void usuwanie(Album& album)
{
	cout << "Co chcesz usunąć?" << endl;
	cout << "1 - Usun zdjecie";
}

void formatowanie(Album& album)
{
	cout <<  "Czy na pewno chcesz usunąć album?" << endl;
	cout <<  "Aby potwierdzic wcisnij '1' " << endl;
	int potwierdzenie;
	cin >> potwierdzenie;
	if (potwierdzenie == 1) {
		album.removeAll();
		cout << "Album zostal usuniety" << endl;
	} else
		cout << "Album nie zostal usuniety" << endl;
}

void wyswietlanie(Album& album)
{
	cout << "Wyswietlanie, co chcesz zrobic?" << endl;
	cout << "1 - Wyswietl alfabetycznie zdjecia zawarte w albumie" << endl;
	cout << "2 - Wyswietl chronologicznie zdjecia zawarte w albumie" << endl;
	cout << "3 - Szukaj zdjecia" << endl;
	cout << "4 - Szukaj tagu" << endl;
	cout << "5 - Szukaj daty" << endl;

	int pytanie2 = 1;
	cin >> pytanie2;

	switch (pytanie2)
	{
	    case 1: wypisza(album);// instrukcja
				break;
		case 2: wypiszch(album);// dodawanie
				break;
		case 3: znajdznazw(album);// usuwanie zdjecia z albumu
				break;
		case 4: znajdztag(album);// usuwanie wszystkiego
				break;
		case 5: znajdzdate(album);// wypisywanie
				break;
	}
}

void wczytaj(Album& album)
{
	cout <<"Error 404: Page not found" << endl;
	cout <<"Yet..." << endl;
//	bool load();
}

void zapisz(Album& album)
{
	cout << "Error 404: Page not found" << endl;
	cout << "Yet..." << endl;
//	bool save();
}

void wyjscie()
{
	cout << "Dziękuję za używanie programu. Program się zakończy." << endl;
}

void wypisza(Album& album)
{
	cout << "Wypisuje caly album:" << endl << endl;
	cout << album << endl;
}

void wypiszch(Album& album)
{
//     template <Tree dateTree> friend std::ostream& operator<<(std::ostream& out, const Tree<Photolist>& tree);
}
void znajdznazw(Album& album)
{
    cout << "Wpisz nazwe zdjecia, ktore chcesz znalexc"<<endl;
    string nazwa;
    cin >> nazwa;
//     album.find(nazwa);
}
void znajdztag(Album& album)
{
    cout << "Podaj nazwe poszukiwanego tagu" << endl;
    string nazwatag;
    cin >> nazwatag;
	PhotoList* list = album.tagTree.find(nazwatag);
	cout << list << endl;
}

void znajdzdate(Album& album)
{
    cout << "Wpisz date uwtorzenia zdjecia, ktore chcesz znalexc"<<endl;
    cout << "Podaj dzien"<<endl;
    int dzien;
    cin >> dzien;
    cout << "Podaj miesiac"<<endl;
    int miesiac;
    cin >> miesiac;
    cout << "Podaj rok"<<endl;
    int rok;
    cin >> rok;

    std::ostringstream ss;
	ss << "Data: " << dzien << '.' << miesiac << '.' << rok << ';';

//     findDate(Data(dzien, miesiac, rok));
}
