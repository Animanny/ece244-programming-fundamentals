/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "DBentry.h"
using namespace std;
#include <iostream>
#include <string>

DBentry::DBentry() {
//    cout << "invoking default constructor" << endl;
    (*this).name = "";
    (*this).IPaddress = 0;
    (*this).active = false;
    
}

DBentry::DBentry(string _name, unsigned int _IPaddress, bool _active) {
//    cout << "invoking second constructor" << endl;
    (*this).name = _name;
    (*this).IPaddress = _IPaddress;
    (*this).active = _active;
}

DBentry::~DBentry(){
//    cout << "invoking destructor" << endl;
}

void DBentry::setName(string _name) {
    (*this).name = _name;
//    cout << "set name to " << _name << endl;
}

string DBentry::getName() const {
    return (*this).name;
}

void DBentry::setIPaddress(unsigned int _IPaddress) {
//    cout << "set IP address " << _IPaddress << endl;
    (*this).IPaddress = _IPaddress;
}

unsigned int DBentry::getIPaddress() const {
    return (*this).IPaddress;
}

void DBentry::setActive(bool _active) {
//    cout << "set active " << _active << endl;
    (*this).active = _active;
}

bool DBentry::getActive() const {
    return (*this).active;
}

ostream& operator<< (ostream& out, const DBentry& rhs) {
    // name : IPaddress : active  followed by newline
    string status;
    if (rhs.active) {
        status = "active";
    } else {
        status = "inactive";
    }
    out << rhs.name << " : " << rhs.IPaddress << " : " << status << endl;
    return out;
            
}
