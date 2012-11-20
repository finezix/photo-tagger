#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"

#include <ostream>

Album::~Album() {
	tagTree.seekAndDestroy();
	dateTree.seekAndDestroy();
	photos.seekAndDestroy();
}

bool Album::save() // zapisywanie do pliku
{
	// tu muszze ogarnac filesy w C++
	return false;
}

bool Album::load() // wczytywanie danych z pliku
{
	// jak wyzej
	return false;
}

bool Album::add(Photo* p) // dodawanie zdjêcia do albumu
{
	bool allGood = false;
	allGood = photos.add(p);
	if (allGood) {
		TagList tagi = p->getTagList();
		for (int i = 0; i < tagi.getSize(); i++) {
			Tag t = tagi.get(i);
			PhotoList* list = tagTree.find(t.getName());
			if (list == NULL) {
				list = new PhotoList(t.getName());
				tagTree.add(list);
			}
			list->add(p);
		}
	}
	if(allGood) {
		Date data = p->getDate();
		PhotoList* list = dateTree.find(data.toString());
		if (list == NULL) {
			list = new PhotoList(data.toString());
			dateTree.add(list);
		}
		allGood = list->add(p);
		
	}
	return allGood;
}

void Album::remove(Photo* p) //wywalanie zdjêcia z albumu
{
	//jeszcze pozniej
}

void Album::removeAll() // wywalanie wszystkiego, co jest w albumie, taki mega format ogólnie
{
	photos.clear();
}

std::ostream& operator<<(std::ostream& out, const Album& album) {
	out << album.photos;
	return out;
}