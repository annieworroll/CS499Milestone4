full: cdatabase.o cservice.o contact.o main.o sql.o
	g++ cdatabase.o cservice.o contact.o main.o sql.o -o contactmanager

cservice.o:
	g++ -g -c contactservice.cpp -o cservice.o

contact.o:
	g++ -g -c contact.cpp -o contact.o

main.o:
	g++ -g -c main.cpp -o main.o

sql.o:
	gcc -g -c sqlite3.c -o sql.o

cdatabase.o:
	g++ -g -c contactdatabase.cpp -o cdatabase.o


