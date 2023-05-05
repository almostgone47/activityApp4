/***********************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 2, Dynamic Variables and Memory Management Assignment
# Date:             May 5th, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a file input for storage.
# Output:           Outputs results to screen and writes to local file.
# Sources:          N/A
#***********************************************************************************/
#include <cstring>
#include <iostream>
#include "activity.h"

using namespace std;

//Name:   setName()
//Desc:   Sets the name property of an Activity.
//input:  A ref to a variable to copy the value held at the name property.
//output: none
//return: none
void Activity::setName(char *newName) {
    strcpy(name, newName);
};

//Name:   setLocation()
//Desc:   Sets the location property of an Activity.
//input:  A ref to a variable to copy the value held at the location property.
//output: none
//return: none
void Activity::setLocation(char *newLocation) {
    strcpy(location, newLocation);
};

//Name:   setLevel()
//Desc:   Sets the level property of an Activity.
//input:  A ref to a variable to copy the value held at the level property.
//output: none
//return: none
void Activity::setLevel(char *newLevel) {
    strcpy(level, newLevel);
};

//Name:   setRating()
//Desc:   Sets the rating property of an Activity.
//input:  An integer value that will the new rating property value.
//output: none
//return: none
void Activity::setRating(int newRating) {
    rating = newRating;
};

//Name:   setType()
//Desc:   Sets the type property of an Activity.
//input:  An Enum Type value that will the new type property value.
//output: none
//return: none
void Activity::setType(Type newType) {
    type = newType;
};

//Name:   getName()
//Desc:   Gets the name property of an Activity.
//input:  A ref to a variable to copy the value held at the name property.
//output: none
//return: none
void Activity::getName(char *returnName) const {
    strcpy(returnName, name);
};

//Name:   getLocation()
//Desc:   Sets the location property of an Activity.
//input:  A ref to a variable to copy the value held at the location property.
//output: none
//return: none
void Activity::getLocation(char *returnLocation) const {
    strcpy(returnLocation, location);
};

//Name:   getLevel()
//Desc:   Sets the level property of an Activity.
//input:  none
//output: none
//return: none
void Activity::getLevel(char *returnLevel) const {
    strcpy(returnLevel, level);
};

//Name:   getRating()
//Desc:   Sets the rating property of an Activity.
//input:  none
//output: none
//return: An integer representing the rating of an activity.
int Activity::getRating() const {
    return rating;
};

//Name:   getType()
//Desc:   Sets the type property of an Activity.
//input:  none
//output: none
//return: Enum Type
Activity::Type Activity::getType() const {
    return type;
};

//Name:   printActivity()
//Desc:   Prints each of the values of an Activity with a semicolon delimiter.
//input:  none
//output: none
//return: none
void Activity::printActivity() {
    cout << name << ";" << location << ";" << level << ";" << rating << ";" << type << endl;
}