#include <iostream>
#include <fstream>
#include "FlightReader.h"

int main() {
    ifstream ourFile;
    string buffer;
    FlightReader flightReader;
    ourFile.open("flightFile.txt", ifstream::in | ifstream::app);
    if (!ourFile) {
        throw "Failed Opening File";
    }
    // read each line in the file and build the flight
    while (getline(ourFile, buffer)) {
        flightReader.lexer(buffer);
    }
    ourFile.close();



    return 0;
}