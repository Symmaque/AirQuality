main : Reader.o Attribute.o User.o Measure.o
	g++ -o main Attribute.o Reader.o User.o Measure.o


Attribute.o : ../Model/Attribute.cpp
	g++ -c ../Model/Attribute.cpp

User.o : ../Model/User.cpp
	g++ -c ../Model/User.cpp

Measure.o : ../Model/Measure.cpp
	g++ -c ../Model/Measure.cpp

clean :
	rm *.o
