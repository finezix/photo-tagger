#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"

#include <iostream>
#include <string>

void dataCheck() {
	std::cout << "ale tu pusto..." << std::endl;
	Date da(10, 10, 1992);
	Date dh(15, 8, 1992);
	std::cout << da << std::endl << da.toString() << std::endl;
	std::cout << "Różnica w datach: " << da.compareTo(dh) << std::endl;
}

void tagCheck() {
	Tag t;
	std::cout << "pusty tag: " << t << std::endl;
	t = Tag(std::string("nazwa_test"), 2);
	std::cout << "dobry tag: " << t << std::endl;
	std::cout << t.getName() << ": " << t.getWeight() << std::endl;
}

void taglistCheck() {
	TagList l;
	l.add(Tag(std::string("waga2"), 2));
	l.add(Tag(std::string("waga3"), 3));
	l.add(Tag(std::string("waga1"), 1));
	std::cout << l << std::endl;
	std::cout << l.get(1) << std::endl;
	std::cout << l.getIndex(l.get(1).getName()) << std::endl;
}

void photoCheck() {
// 	Photo p(std::string(""), Date(10,10,1992), 
	
}