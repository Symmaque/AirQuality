main : Reader.o Attribute.o
	g++ -o main Attribute.o Reader.o

Reader.o : Reader.cpp
	g++ -c Reader.cpp

Attribute.o : ../Model/Attribute.cpp
	g++ -c ../Model/Attribute.cpp

clean :
	rm *.o
