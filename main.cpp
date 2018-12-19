#include <iostream>
#include <fstream>
#include "FlightReader.h"
#include "InfixToPrefix.h"
#include "Sockets.h"
#include <regex>


int main() {
    FlightReader fr;
    fr.lexer("openDataServer 5400 10");

//    FlightReader fr;
//    fr.lexer("connect 127.0.0.1 5402");


//    Sockets* s = new Sockets();
//    s->func1();

    while(true){}
    return 0;


//    ifstream ourFile;
//    string buffer;
//    FlightReader flightReader;
//    ourFile.open("flightFile.txt", ifstream::in | ifstream::app);
//    if (!ourFile) {
//        throw "Failed Opening File";
//    }
//    // read each line in the file and build the flight
//    while (getline(ourFile, buffer)) {
//        flightReader.lexer(buffer);
//    }
//    ourFile.close();
//    return 0;




//    InfixToPrefix sh;
//    //
//    vector<string> s  ;
//    s.push_back("(");
//    s.push_back("4");
//    s.push_back("-");
//    s.push_back("3");
//    s.push_back(")");
//    s.push_back("*");
//    s.push_back("(");
//    s.push_back("10");
//    s.push_back("/");
//    s.push_back("2");
//    s.push_back(")");
//    vector<string> g = sh.convertFunc(s);
////    for (int i = 0; i < g.size(); ++i){
////        //cout<<g[i];
////    }
//    Expression*e = sh.turnToExppression(g);
//    cout<<e->calculate()<<endl;


// Target sequence
    //string s = "GeeksForGeeksI am Geeksulooking for GeeksForGeeks "
    //           "articles";


//    string s = "OpenDataServer 5400 10";
//    regex v("[0-9]*\.");

    //regex v("[-+]?[0-9]\.?[0-9]+[\/\+\-\])+([-+]?[0-9]*\.?[0-9]+");
    // An object of regex for pattern to be searched
    //regex r("Geek[a-zA-Z]+");

    // flag type for determining the matching behavior
    // here it is for matches on 'string' objects
//    smatch m;

    // regex_search() for searching the regex pattern
    // 'r' in the string 's'. 'm' is flag for determining
    // matching behavior.

//    while (regex_search(s, m, v)) {
//        // for each loop
//        for (auto x : m) {
//            cout << x << "\n";
//        }
//        s = m.suffix();
//    }



    return 0;

}