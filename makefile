all:
	clear
	g++ -o exe personne.cpp main.cpp -Wall -Wextra
	./exe
	rm exe
