#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void readSensor();

int main()
{
    readSensor();
    return 0;
}

void readSensor()
{
    //File pointer
    ifstream file("./data/sensors.csv");
    string buff;
    if (file.is_open())
    {
        while (getline(file, buff, ';'))
        {
            cout << buff << ";";
        }
    }
}