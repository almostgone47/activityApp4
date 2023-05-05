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
#include <iostream>
#include <fstream>
#include "activityList.h"
#include "activity.h"

//Name:   displayActivityMenu()
//Desc:   Displays menu of all user options.
//input:  none
//output: Displays all menu options.
//return: none
void displayActivityMenu() {
    cout << endl << "Welcome! " << endl;
    cout << "This program will help you manage your activities. " << endl << endl;
    cout << "Pick an option from below: " << endl << endl;
    cout << "(a)Add a new activity " << endl;
    cout << "(b)List activities " << endl;
    cout << "(c)List activities by location " << endl;
    cout << "(d)List activities by Type " << endl;
    cout << "(e)Remove an activity " << endl;
    cout << "(f)Search by activity name " << endl;
    cout << "(q)Quit " << endl;
}

//Name:   readInt()
//Desc:   Prompts user for an integer which is used to the rating of an activity
//        when adding a new activity.
//input:  int representing the rating being input.
//output: Displays prompt for user to enter a rating.
//return: The integer representing the user's rating of the activity.
int readInt()
{
    int temp = 0;
    cout << "Enter the activity rating: ";
    cin >> temp;

    while (!cin)
    {
        cin.clear();
        cin.ignore(100, '\n');
        cout << "Invalid rating! Please enter a valid rating! ";
        cin >> temp;
    }
    cin.ignore(100, '\n');

    return temp;
}

//Name:   readType()
//Desc:   Matches an input char to the corresponding Enum Type.
//input:  char representing the type being input.
//output: none
//return: The corresponding type to the input char.
Activity::Type readType(char num)
{
    Activity::Type tempType;
    switch(num)
    {
        case '0':
            tempType = static_cast<Activity::Type>(0);
            break;
        case '1':
            tempType = static_cast<Activity::Type>(1);
            break;
        case '2':
            tempType = static_cast<Activity::Type>(2);
            break;
        case '3':
            tempType = static_cast<Activity::Type>(3);
            break;
        default:
            tempType = static_cast<Activity::Type>(4);
    }
    return tempType;
}


//Name:   getUserInput()
//Desc:   Accepts user input.
//input:  Any char
//output: none
//return: A single char.
char getUserInput()
{
    char input;
    cin >> input;
    cin.ignore(100, '\n');
    return input;
}

//Name:   getIndexFromUser()
//Desc:   Helper function for prompting and returning an index from user input.
//input:  A number for the index the user would like to use.
//output: A prompt passed as an argument.
//return: An integer.
int getIndexFromUser(char prompt[MAXCHAR]) {
    int index;
    cout << prompt;
    cin >> index;
    cin.ignore(100, '\n');
    cout << endl;
    return index;
}

//Name:   getUserInputChar()
//Desc:   Helper function for prompting and returning a char array from user input.
//input:  A destination to store input in and a text prompt for the user to see.
//output: A prompt passed as an argument.
//return: An char array.
void getUserInputChar(char prompt[MAXCHAR], char *dest) {
    char temp[MAXCHAR];
    cout << prompt;
    cin.get(temp, MAXCHAR, '\n');
    cout << endl;
    strcpy(dest, temp);
}

//Name:   addActivity()
//Desc:   Collects data from user to create a new activity.
//input:  reference to activity bing created.
//output: Prompts for each of the data points required to create an activity.
//return: none
void addActivity(Activity &activity) {
    char letter;
    char tempName[MAXCHAR], tempLocation[MAXCHAR], tempLevel[MAXCHAR];
    int tempRating;
    Activity::Type tempType;

    cout << "Enter the activity name (50 characters or less): ";
    cin.get(tempName, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity location (50 characters or less): ";
    cin.get(tempLocation, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    cout << "Enter the activity level: ";
    cin.get(tempLevel, MAXCHAR, '\n');
    cin.ignore(100, '\n');
    tempRating = readInt();
    cout << "Enter Type number(0-Athletics, 1-Food, 2-Arts, 3-Games, and 4-Others): " ;
    cin >> letter;
    cin.ignore(100, '\n');
    tempType = readType(letter);
    activity.setName(tempName);
    activity.setLocation(tempLocation);
    activity.setLevel(tempLevel);
    activity.setRating(tempRating);
    activity.setType(tempType);
    cout << "Activity added! " << endl;
}

//Name:   executeCmd()
//Desc:   Takes user input and executes the matching command.
//input:  userInput representing desired command, activities currently in
//        memory, number of activities in memory.
//output: none
//return: none
void executeCmd(char userInput, ActivityList &activityList)
{
    Activity activity;
    switch (tolower(userInput))
    {
        case 'a':
            if(activityList.getNumActivities() == 30)
            {
                cout << "Your list is Full! Movie not added!! ";
                return;
            }
            addActivity(activity);
            activityList.addActivity(activity);
            activityList.showActivities();
            break;
        case 'b':
            activityList.showActivities();
            break;
        case 'c':
            activityList.searchActivitiesByLocation();
            break;
        case 'd':
            activityList.searchActivitiesByType();
            break;
        case 'e':
            activityList.showActivities();
            activityList.removeActivity();
            activityList.showActivities();
            break;
        case 'f':
            activityList.searchActivitiesByName();
            break;
        case 'q':
            break;
        default:
            cout << "Invalid option!! Please try again! " << endl;
    }
}

//Name:   openFile()
//Desc:   Uses ifstream to open local file.
//input:  inFile buffer to read to, file name where data is being read from.
//output: none
//return: none
void openFile(char fileName[], ifstream &inFile)
{
    inFile.open(fileName);
    if(!inFile)
    {
        cout << "Input file did not open!! Program exiting!!! " << endl;
        exit(0);
    }
}

//Name:   openFile()
//Desc:   Uses ofstream to open local file.
//input:  outFile buffer to write from, file name where data is being written to.
//output: none
//return: none
void openFile(char fileName[], ofstream &outFile)
{
    outFile.open(fileName);
    if(!outFile)
    {
        cout << "Input file did not open!! Program exiting!!! " << endl;
        exit(0);
    }
}

//Name:   main()
//Desc:   This the entry point to the application.
//input:  None
//output: prompt
//return: int 0 for program finished
int main() {
    char fileName[MAXCHAR] = "activities.txt";
    ActivityList activityList(fileName);
    char userInput;

    do
    {
        displayActivityMenu();

        userInput = getUserInput();

        executeCmd(userInput, activityList);

    } while (tolower(userInput != 'q'));

    activityList.writeData(fileName);

    return 0;
}
