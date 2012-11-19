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
	cout << "2 - Dodawanie zdjęcia" << endl;
	cout << "3 - Usuwanie zdjęcia" << endl;
	cout << "4 - Usuwanie wszystkich zdjęć z albumu" << endl;
	cout << "5 - Wyświetlanie zawartości albumu" << endl;
	cout << "6 - Zapisywanie albumu do pliku" << endl;
	cout << "7 - Wczytywanie albumu z pliku" << endl;
	cout << "8 - Wyjście z programu" << endl << endl;
	cout << "Którą funkcję chcesz wybrać?" << endl;

	int pytanie;
	cin >> pytanie;

	switch (pytanie)
	{
		case 1: instrukcja();// instrukcja
				break;
		case 2: dodawanie();// dodawanie
				break;
		case 3: usuwanie();// usuwanie zdjecia z albumu
				break;
		case 4: formatowanie();// usuwanie wszystkiego
				break;
		case 5: wyswietlanie();// wypisywanie
				break;
		case 6: zapisz();// zapis stanu do pliku
				break;
		case 6: wczytaj();// wczytywanie danych z pliku
				break;
		case 8: wyjscie();// wyjście z programu
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

void dodawanie()
{
	int dd, mm, yyyy;
	string title;

	cout << endl << "Dodawanie zdjęć." << endl << endl;
	cout << "Podaj nazwę dodawanego zdjêcia" << endl;
	cin >> title;

	cout << "Podaj dzień utworzenia zdjęcia" << endl;
	cin >> dd;
	cout << "Podaj miesiąc utworzenia zdjęcia" << endl;
	cin >> mm;
	cout << "Podaj rok utworzenia zdjęcia" << endl;
	cin >> yyyy;
	Date d(dd, mm, yyyy);

	cout << "Podaj ilość tagów, ktorą chcesz przypisać do zdjęcia" << endl;
	int ilosc;
	do {
		cin >> ilosc;
		if (ilosc > 5) {
			cout << "Błąd, wybierz mniejszą liczbę!";
			return;
		}
		if (ilosc = 0)
			cout << "Brak tagów do dodania";
	} while (ilosc < 6 && ilosc > -1);
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
	Photo p(title, d, tl);
	cout << "Zdjecie dodano do albumu" << endl;
}

void usuwanie()
{
	cout <<  endl << "Oto zakończenie." << endl << endl;
}

void formatowanie()
{
	cout <<  endl << "Oto zakończenie." << endl << endl;
}

void wyswietlanie()
{
	cout <<  endl << "Oto zakończenie." << endl << endl;
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
	cout << endl <<  "Wyjście z programu." << endl << endl;
}

int main(int argc, char *argv[])

{
	do {}while (menu() != 8);  // sprawdzenie co zwraca funkcja menu
// gdy inna niż 8 menu pojawi się od nowa
}
