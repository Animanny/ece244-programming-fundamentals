/*
 * This file was developed for the Fall 2018 instance of ECE244 at the University of Toronto.
 * Creator: Matthew J. P. Walker
 */


#include <galaxy-explorer/AsteroidsObserver.hpp>
//using namespace std;
//#include<iostream>

void AsteroidsObserver::onAsteroidInRange(Asteroid asteroid) {
    
//        cout << "asteroid " << asteroid.getID() << " in range" << endl;
        asteroids().pushFront(asteroid); // add to the front of the list if empty
    
    // insert based on 
//    if ()
    
}

void AsteroidsObserver::onAsteroidUpdate(Asteroid asteroid) {    
    AsteroidListItem* curr = asteroids().begin();
    AsteroidListItem* prev = curr;;
    while (curr != nullptr 
            && curr->getData().getID() != asteroid.getID()) {
        prev = curr;
        curr = curr->getNext();
        
    }
    asteroids().insertAfter(prev, asteroid);
    
//    std::cout << "asteroid " << asteroid.getID() << " updated" << std::endl;
}

void AsteroidsObserver::onAsteroidOutOfRange(Asteroid asteroid) {
    
    AsteroidListItem* curr = asteroids().begin();
    while (curr != nullptr && curr->getNext() != nullptr 
            && curr->getNext()->getData().getID()!= asteroid.getID()) {
        curr = curr->getNext();
    }
    if (curr->getNext() == nullptr) { // if reached the end of the list
        return;
    } else {
        asteroids().eraseAfter(curr); // delete asteroid that was destroyed
//        cout << "asteroid " << asteroid.getID() << " out of range" << endl;
    }
}

void AsteroidsObserver::onAsteroidDestroy(Asteroid asteroid) {
    
    
    AsteroidListItem* curr = asteroids().begin();
    while (curr!= nullptr && curr->getNext() != nullptr 
            && curr->getNext()->getData().getID()!= asteroid.getID()) {
        curr = curr->getNext();
    }
    if (curr->getNext() == nullptr) { // if reached the end of the list
        return;
    } else {
        asteroids().eraseAfter(curr); // delete asteroid that was destroyed
//        cout << "asteroid " << asteroid.getID() << " destroyed" << endl;
    }
}
