vpath %.h headers
vpath %.cc sources

CXXFLAGS = -Wall

objects = album.o date.o photo.o photolist.o tag.o taglist.o

all : main.o $(objects) test.cc
	g++ -o tagger $(CXXFLAGS) $(objects) main.o

main.o : $(objects) test.cc

album.o : album.h date.h photo.h photolist.h tag.h taglist.h

date.o : date.h

photo.o : photo.h tag.h taglist.h

photolist.o : photo.h photolist.h

tag.o : tag.h

taglist.o : tag.h taglist.h

clean :
	rm -f *.o
