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
#ifndef CS162LINKEDLISTS_ACTIVITYLIST_H
#define CS162LINKEDLISTS_ACTIVITYLIST_H
#include "activity.h"

using namespace std;

const int CAP = 30;
const int GROWTH = 5;

class ActivityList {
private:
    Activity *list;
    int size;
    int capacity;
    void growList();
public:
    ActivityList();
    ActivityList(char []);
    ~ActivityList();
    
    int getNumActivities() const;
    void showActivities();
    void searchActivitiesByLocation();
    void searchActivitiesByType();
    void searchActivitiesByName();
    void loadData(ifstream &inFile);
    void removeActivity();
    void writeData(char fileName[]);
    int getInsertionPoint(char *tempName, const char *insertName);
    void addActivity(Activity &activity);
};
#endif //CS162LINKEDLISTS_ACTIVITYLIST_H
