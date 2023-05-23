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
#include <iostream>
#include <fstream>
#include <cstring>
#include "activityList.h"
#include "activity.h"
#include "main.h"

using namespace std;

//Name:   ActivityList()
//Desc:   Constructor for ActivityList class.
//input:  none.
//output: none
//return: none
ActivityList::ActivityList() {
    head = NULL;
    tail = NULL;
    size = 0;
}

//Name:   ActivityList()
//Desc:   Constructor for ActivityList class.
//input:  none.
//output: none
//return: none
ActivityList::ActivityList(char fileName[]) {
    size = 0;
    ifstream inFile;
    openFile(fileName, inFile);
    loadData(inFile);
}

//Name:   ~ActivityList()
//Desc:   Destructor for ActivityList class.
//input:  none.
//output: none
//return: none
ActivityList::~ActivityList() {
    Node *curr = head;
    while (curr) {
        head = curr->next;
        delete curr;
        curr = head;
    }
    tail = nullptr;
}

//Name:   getNumActivities()
//Desc:   Gets the total number of activities in the activity list.
//input:  none.
//output: none
//return: none
int ActivityList::getNumActivities() const {
    return size;
}

//Name:   getInsertionPoint()
//Desc:   Searches list to find index where first char in current activity is less than first char of name
//        of activity passed in.
//output: none
//return: int plus one for the index to insert the activity at in list.
int ActivityList::getInsertionPoint(char *tempName, const char *insertName) {
    // may not need this method
}

//Name:   addActivity()
//Desc:   Adds ref to newly created activity to array of all activities in memory.
//input:  array holding all activities currently in memory, number of activities in memory,
//        ref to activity being created.
//output: none
//return: none
void ActivityList::addActivity(Activity &activity) {
    Node *curr = nullptr, *prev = nullptr, *newNode = nullptr;
    char temp1[MAXCHAR], temp2[MAXCHAR];
    newNode->data = activity;
    newNode->next = nullptr;

    // if head is null make head and tail
    if (!head) {
        head = newNode;
        tail = newNode;
    }
    else {
        // else if head is greater than activity make head=activity and head->curr
        activity.getName(temp2);
        for (curr = head; curr; curr = curr->next) {
            curr->data.getName(temp1);

            if (!curr->next) {
                tail->next = newNode;
                tail = newNode;
            }
            else if (temp1[0] > temp2[0]) {
                prev = curr;
                curr = newNode;
                curr->next = prev;
            }
            else {
                newNode->next = curr;
                head = newNode;
            }
            // else make curr->next = activity
        }
    }
    size++;
}

//Name:   showActivities()
//Desc:   Displays all activities currently in memory.
//input:  all activities currently in memory, the number of all activities
//output: Displays all activities with a number at the start of each line.
//return: none
void ActivityList::showActivities() {
    Node *curr = nullptr;
    int i = 1;
    for(curr = head; curr; curr = curr->next)
    {

        cout << i << ".";
        curr->data.printActivity();
        i++;
    }
    cout << endl;
}

//Name:   searchActivitiesByLocation()
//Desc:   Asks user for location of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByLocation() {
    Node *curr = nullptr;
    char searchLocation[MAXCHAR];
    getUserInputChar("Enter location name: ", searchLocation);
    char storedLocation[MAXCHAR];

    bool activityFound = false;
    for (curr = head; curr; curr = curr->next)
    {
        curr->data.getLocation(storedLocation);
        if(strstr(searchLocation, storedLocation) != NULL)
        {
            activityFound = true;
            curr->data.printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   searchActivitiesByType()
//Desc:   Asks user for type of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByType() {
    Node *curr = nullptr;
    cout << "Enter Type number(0-Athletic, 1-Food, 2-Arts, 3-Games, 4-Other): ";
    char letter;
    cin >> letter;
    Activity::Type tempType = readType(letter);

    bool activityFound = false;
    for (curr = head; curr; curr = curr->next)
    {
        Activity::Type type = curr->data.getType();
        if(type == tempType)
        {
            activityFound = true;
            curr->data.printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   searchActivitiesByName()
//Desc:   Asks user for name of activity to search for and prints all activities that match
//        the input string.
//input:  array holding all activities currently in memory, number of activities in memory
//output: All activities matching search.
//return: none
void ActivityList::searchActivitiesByName() {
    Node *curr = nullptr;
    char searchName[MAXCHAR];
    getUserInputChar("Enter the activity name (50 characters or less): ", searchName);
    char activityName[MAXCHAR];

    bool activityFound = false;
    for(curr = head; curr; curr = curr->next)
    {
        curr->data.getName(activityName);
        if(strstr(searchName, activityName) != NULL)
        {
            activityFound = true;
            curr->data.printActivity();
        }
    }

    if (!activityFound) {
        cout << "Activity not found!! " << endl;
    }
}

//Name:   removeActivity()
//Desc:   Removes activity from all activities in array stored in memory.
//input:  array holding all activities currently in memory, number of activities in memory
//output: none
//return: none
void ActivityList::removeActivity() {
//    Node *curr = nullptr, *prev = nullptr;
//    int index = getIndexFromUser("Pick the index to remove: ");
//    int i = 0;
//    if(index <= size && index > -1)
//    {
//        for(curr = head; curr; curr = curr->next)
//        {
//            list[i-1] = list[i];
//        }
//    }
//    size--;
//    cout << "Activity removed! " << endl;
}

//Name:   writeData()
//Desc:   Uses ofstream to write data from local file.
//input:  outFile to write to, all current activities in memory, number of activities
//output: A small response showing user has saved data.
//return: none
void ActivityList::writeData(char fileName[]) {
    Node *curr = nullptr;
    ofstream outFile;
    openFile(fileName, outFile);
    char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
    int tempRating;
    Activity::Type tempType;

    for(curr = head; curr; curr = curr->next)
    {
        curr->data.getName(tempName);
        curr->data.getLocation(tempLocation);
        curr->data.getLevel(tempLevel);
        tempRating = curr->data.getRating();
        tempType = curr->data.getType();
        outFile << tempName << ";" << tempLocation << ";" << tempLevel << ";" << tempRating << ";" << tempType << endl;
    }
    outFile.close();
    cout << "Activities written to file! Thank you for using my program!! " << endl;
}

//Name:   loadData()
//Desc:   Uses ifstream to read data from local file.
//input:  inFile to read from, all current activities in memory, number of activities
//output: none
//return: none
void ActivityList::loadData(ifstream &inFile)
{
    Activity activity;
    char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
    int tempRating;
    Activity::Type tempType;
    char tempType2[51];

    inFile.get(tempName, MAXCHAR, ';');
    while(inFile)
    {
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempLocation, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempLevel, MAXCHAR, ';');
        inFile.ignore(MAXCHAR, ';');
        inFile >> tempRating;
        inFile.ignore(MAXCHAR, ';');
        inFile.get(tempType2, 2, ';');

        if(strcmp(tempType2, "0") == 0)
        {
            tempType = Activity::athletic;
        }
        else if(strcmp(tempType2, "1") == 0)
        {
            tempType = Activity::food;
        }
        else if(strcmp(tempType2, "2") == 0)
        {
            tempType = Activity::arts;
        }
        else if(strcmp(tempType2, "3") == 0)
        {
            tempType = Activity::games;
        }
        else
        {
            tempType = Activity::other;
        }
        inFile.ignore(100, '\n');
        activity.setName(tempName);
        activity.setLocation(tempLocation);
        activity.setLevel(tempLevel);
        activity.setRating(tempRating);
        activity.setType(tempType);
        addActivity(activity);
        inFile.get(tempName, MAXCHAR, ';');
    }
    inFile.close();
}