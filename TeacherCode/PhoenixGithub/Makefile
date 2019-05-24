.PHONY: all

all: clean
	g++ -std=c++1y -o ImageEdit.o -c main.cpp -Wall -O `pkg-config --cflags --libs opencv`
	g++ -o iEdit ImageEdit.o `pkg-config --cflags --libs opencv`

clean:
	rm -f *.o iedit 


