//
//  main.cpp
//  COMSC-210 | lab 23: Goat Manager 3001 | Guo An Wang
//  IDE: Xcode
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <list>
#include <ctime>
#include <cstdlib>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//function prototypes
int select_goat(list<Goat> trip);
void delete_goat(list<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int main() {
    srand(time(0));
    bool again;
    // read & populate arrays for names and colors
    ifstream fin("Names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("Colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    list<Goat> trip;
    return 0;
}
int main_menu() {
    int user;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat \n[2] Delete a goat \n[3] List goats \n[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> user;
    cin.ignore();
    if (user > 4) {
        cout << "Not a valid option" << endl;
        return 1;
    }
    return user;
}
void add_goat(list<Goat> &trip, string names[], string colors[]){
    int randomName = rand() % SZ_NAMES;
    int randomColor = rand() % SZ_COLORS;
    int randomAge = rand() % MAX_AGE;
    
    string name = names[randomName];
    string color = colors[randomColor];
    
    Goat newGoat(name, randomAge, color);
    trip.push_back(newGoat);
}
//int select_goat(list<Goat> trip){
    
//}
void delete_goat(list<Goat> &trip){
    
}
void display_trip(list<Goat> trip){
    if (trip.empty()) {
        cout << "List is empty" << endl;
        return;
     }
    int i = 1;
    for (auto &val : trip) {
        cout << "[" << i++ << "] " << val.get_name() << " (" << val.get_age() << ", " << val.get_color() << ") " << endl;
    }
}
