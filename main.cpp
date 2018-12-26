#include <iostream>
#include <fstream>
#include "FlightReader.h"
#include "InfixToPrefix.h"
#include "Sockets.h"
#include <regex>


int main(int argc, char *argv[]) {
    ifstream ourFile;
    Maps *maps = new Maps();
    maps->counter++;
    string buffer = "";
    FlightReader flightReader(maps);
    ourFile.open(argv[1], ifstream::in | ifstream::app);
    if (!ourFile) {
        throw "Failed Opening File";
    }
    // read each line in the file and build the flight
    while (getline(ourFile, buffer)) {
        flightReader.lexer(buffer);
    }
    flightReader.exit();
    ourFile.close();

    //cout << maps->counter << endl;
    if (maps->counter == 1) {
        delete maps;
    }   else    {
        maps->counter--;
    }

    return 0;
}