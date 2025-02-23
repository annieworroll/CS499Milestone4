full: cservice.o contact.o main.o sql.o
	g++ cservice.o contact.o main.o sql.o -o contactmanager

cservice.o:
	g++ -c contactservice.cpp -o cservice.o

contact.o:
	g++ -c contact.cpp -o contact.o

main.o:
	g++ -c main.cpp -o main.o

sql.o:
	gcc -c sqlite3.c -o sql.o

