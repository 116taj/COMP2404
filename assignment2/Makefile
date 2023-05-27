#observe - Linux is case sensitive. These names should match your filenames exactly

all: a2
	
a2: main.o TestControl.o TestView.o Album.o AlbumArray.o Photo.o PhotoArray.o PhotoGram.o Client.o Date.o
	g++ -o a2 main.o TestControl.o TestView.o Album.o AlbumArray.o Photo.o PhotoArray.o PhotoGram.o Client.o Date.o
	
TestControl.o: TestControl.cc TestControl.h TestView.h
	g++ -c TestControl.cc
	
TestView.o: TestView.cc TestView.h
	g++ -c TestView.cc
		
Album.o: Album.h Album.cc 
	g++ -c Album.cc 

AlbumArray.o: AlbumArray.h AlbumArray.cc 
	g++ -c AlbumArray.cc 

Photo.o: Photo.h Photo.cc
	g++ -c Photo.cc

PhotoArray.o: PhotoArray.cc PhotoArray.h
	g++ -c PhotoArray.cc

PhotoGram.o: PhotoGram.h PhotoGram.cc
	g++ -c PhotoGram.cc

Client.o: Client.h Client.cc
	g++ -c Client.cc

Date.o:	Date.h Date.cc
	g++ -c Date.cc

main.o:	main.cc TestControl.h
	g++ -c main.cc

clean:
	rm -f a2 *.o
