main : Reader.o Attribute.o User.o Provider.o Cleaner.o
	g++ -o main Attribute.o Reader.o User.o Provider.o Cleaner.o


Attribute.o : ../Model/Attribute.cpp
	g++ -c ../Model/Attribute.cpp

User.o : ../Model/User.cpp
	g++ -c ../Model/User.cpp

Provider.o : ../Model/Provider.cpp
	g++ -c ../Model/Provider.cpp

Cleaner.o : ../Model/Cleaner.cpp
	g++ -c ../Model/Cleaner.cpp

Reader.o : Reader.cpp
	g++ -c Reader.cpp

clean :
	rm *.o
