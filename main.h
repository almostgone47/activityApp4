/***********************************************************************************
# Author:           Jeremiah Barro
# Assignment:       Assignment 3, Linked Lists
# Date:             May 23rd, 2023
# Description:      This is a console app that allows users to create, read
                    and destroy Activities which are read and stored to a local
                    file.
# Input:            String input through console and a file input for storage.
# Output:           Outputs results to screen and writes to local file.
# Sources:          N/A
#***********************************************************************************/
#ifndef CS162LINKEDLISTS_MAIN_H
#define CS162LINKEDLISTS_MAIN_H
#include <iostream>
#include "activity.h"
#include "activityList.h"

using namespace std;

// function prototypes
void displayActivityMenu();
char getUserInput();
void executeCmd(char userInput, ActivityList &activityList);
void openFile(char fileName[], ifstream &inFile);
Activity::Type readType(char num);
void openFile(char fileName[], ofstream &outFile);
void addActivity(Activity &activity);
void getUserInputChar(char const prompt[MAXCHAR], char *dest);
int getIndexFromUser(char const prompt[MAXCHAR]);

#endif //CS162LINKEDLISTS_MAIN_H
