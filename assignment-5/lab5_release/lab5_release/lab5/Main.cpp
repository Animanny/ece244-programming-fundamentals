/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: yehchenh
 *
 * Created on November 21, 2018, 9:00 AM
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;
#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"
#include <iostream>
#include <string>
#include <sstream>

/*
 * 
 */
int main(int argc, char** argv) {
    string line;
    string command;
    
    string name;
    string status;
    bool isActive;
    unsigned int IPaddress;
    
    TreeDB treeDB;
    
    // array of commands available
    string AVAIL_COMMANDS [8] = {"insert", 
                            "find", 
                            "remove", 
                            "printall", 
                            "printprobes",
                            "removeall", 
                            "countactive", 
                            "updatestatus"};
    
    string ERROR_MESSAGE [2] = {"Error: entry already exists", 
                           "Error: entry does not exist"};
    
    string SUCCESS = "Success";
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
    
    while (!cin.eof()) {
        stringstream linestream(line);
        
        linestream >> command; // read fro, stringstream into command
        
        if (command.compare(AVAIL_COMMANDS[0]) == 0) { // insert
            linestream >> name >> IPaddress >> status;
            if (status == "active") isActive = true;
            else isActive = false;
            DBentry* newEntry = new DBentry(name, IPaddress, isActive);
            
            bool inserted = treeDB.insert(newEntry);
            
            if (inserted) {
                cout << SUCCESS << endl;
                
                linestream.ignore(1000, '\n');
            } else {
                cout << ERROR_MESSAGE[0] << endl;
                linestream.ignore(1000, '\n');
                delete newEntry;
            }
            
            
        }else if (command.compare(AVAIL_COMMANDS[1]) == 0){ // find
            linestream >> name;
            DBentry* entryFound = treeDB.find(name);
            
            if (entryFound == NULL) {
                cout << ERROR_MESSAGE[1] << endl;
                linestream.ignore(1000, '\n');
            } else {
                operator<<(cout, *entryFound);
                linestream.ignore(1000, '\n');
            }
        } else if (command.compare(AVAIL_COMMANDS[2]) == 0) { // remove
            linestream >> name;
            bool removed = treeDB.remove(name);
            
            if (removed) {
                cout << SUCCESS << endl;
            } else {
                cout << ERROR_MESSAGE[1] << endl;
                linestream.ignore(1000, '\n');
            }
            
        } else if (command.compare(AVAIL_COMMANDS[3]) == 0) { // print all 
            operator<<(cout, treeDB);
        }  else if (command.compare(AVAIL_COMMANDS[4]) == 0) { // printprobes
            linestream >> name;
            DBentry* entryFound = treeDB.find(name);
            
            if (entryFound == NULL) {
                cout << ERROR_MESSAGE[1] << endl;
                linestream.ignore(1000, '\n');
            } else {
                treeDB.printProbes();
            }
            
        } else if (command.compare(AVAIL_COMMANDS[5]) == 0) { // removeall
            treeDB.clear();
            cout << SUCCESS << endl;
        } else if (command.compare(AVAIL_COMMANDS[6]) == 0) { // countactive
                treeDB.countActive();
        }  else if (command.compare(AVAIL_COMMANDS[7]) == 0) { // updatestatus
            linestream >> name >> status;
            
            if (status == "active") {
                isActive = true;
            } else {
                isActive = false;
            }
            
            DBentry* entry = treeDB.find(name);
            
            if (entry == NULL) {
                cout << ERROR_MESSAGE[1] << endl;
                linestream.ignore(1000, '\n');
            } else {
                entry->setActive(isActive);
                cout << SUCCESS << endl;
            }
        }
        
        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
        
    }
    
    return 0;
}

