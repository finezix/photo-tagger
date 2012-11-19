#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"

#include <iostream>
#include <string>
#include <ostream>

//ogolnie nie wiem, jak napisac to, ze te drzewa ze soba rozmawiaja...

using namespace std;

void instrukcja();
void dodawanie();
void usuwanie();
void formatowanie();
void wyswietlanie();
//void wyjscie();
void zapisz();
void wczytaj();

void wypisza();
void wypiszch();
void znajdznazw();
void znajdztag();
void znajdzdate();

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
		case 7: wczytaj();// wczytywanie danych z pliku
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

	// tu cos, to ma jakis zwiazek z tym album::add(photo* p), co nie...?
	//ale nie umiem zupelnie

	cout << "Zdjecie dodano do albumu" << endl;
	int menu();
}

void usuwanie()
{
	cout << "Co chcesz usunąć?" << endl;
	cout << "1 - Usun zdjecie";
}

void formatowanie()
{
	cout <<  "Czy na pewno chcesz usunąć album?" << endl;
	cout <<  "Aby potwierdzic wcisnij '1' " << endl;
	int potwierdzenie;
	if (potwierdzenie=1)	{void removeAll();}
	else cout << "Album nie zostal usuniety" << endl;
	int menu();
}

void wyswietlanie()
{
	cout << "Wyswietlanie, co chcesz zrobic?" << endl;
	cout << "1 - Wyswietl alfabetycznie zdjecia zawarte w albumie" << endl;
	cout << "2 - Wyswietl chronologicznie zdjecia zawarte w albumie" << endl;
	cout << "3 - Szukaj zdjecia" << endl;
	cout << "4 - Szukaj tagu" << endl;
	cout << "5 - Szukaj daty" << endl;

	int pytanie2;
	cin >> pytanie2;

	switch (pytanie2)
	{
	    case 1: wypisza();// instrukcja
				break;
		case 2: wypiszch;// dodawanie
				break;
		case 3: znajdznazw();// usuwanie zdjecia z albumu
				break;
		case 4: znajdztag();// usuwanie wszystkiego
				break;
		case 5: znajdzdate();// wypisywanie
				break;
}
}

void wczytaj()
{
	cout <<"Error 404: Page not found" << endl;
	cout <<"Yet..." << endl;
}

void zapisz()
{
	cout << "Error 404: Page not found" << endl;
	cout << "Yet..." << endl;
	menu();
}

/* void wyjscie()
{
	cout << "Czy na pewno chcesz wyjsc z programu?" << endl;
    cout << "Aby potwierdzic wcisnij '1' " << endl;
	int tak;
	cin >> tak;
	if tak =1
	cout << "Do widzenia!" << endl;
	return 0;
	else menu();
} */
void wypisza()
{
    template <Tree photosTree> friend std::ostream& operator<<(std::ostream& out, const Tree<Photo>& tree);
}

void wypiszch()
{
    template <Tree dateTree> friend std::ostream& operator<<(std::ostream& out, const Tree<Photolist>& tree);
}
void znajdznazw()
{
    cout << "Wpisz nazwe zdjecia, ktore chcesz znalexc"<<endl;
    string nazwa;
    cin >> nazwa;
     Photo* find(const nazwa);
}
void znajdztag()
{
    cout << "Podaj nazwe poszukiwanego tagu" << endl;
    string nazwatag;
    cin >> nazwatag;
    Photolist* find(const nazwatag);
}

void znajdzdate()
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
	return ss.str();

    Photolist* find( ss);
}

int main(int argc, char *argv[])
{
    Tree<Photo> photosTree;
    Tree<PhotoList> tagTree;
    Tree<PhotoList> dateTree;

	do {}while (menu() != 8);
}

