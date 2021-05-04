main : Reader.o Attribute.o User.o Provider.o
	g++ -o main Attribute.o Reader.o User.o Provider.o

Reader.o : Reader.cpp
	g++ -c Reader.cpp

Attribute.o : ../Model/Attribute.cpp
	g++ -c ../Model/Attribute.cpp

User.o : ../Model/User.cpp
	g++ -c ../Model/User.cpp

Provider.o : ../Model/Provider.cpp
	g++ -c ../Model/Provider.cpp

clean :
	rm *.o
