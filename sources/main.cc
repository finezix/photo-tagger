#include "../headers/album.h"
#include "../headers/taglist.h"
#include "../headers/tag.h"
#include "../headers/photolist.h"
#include "../headers/photo.h"
#include "../headers/date.h"
#include "menu.cc"

// >>>>>>> do testow
#include "test.cc"
// >>>>>>> do testow

#include <iostream>



int main() {
// 	dataCheck();
// 	tagCheck();
// 	taglistCheck();

	Album album;
	do {}while (menu(album) != 8);
	return 0;
}