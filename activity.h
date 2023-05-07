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
#ifndef CS162DYNAMICVARIABLESANDMEMORYMANAGEMENT_ACTIVITY_H
#define CS162DYNAMICVARIABLESANDMEMORYMANAGEMENT_ACTIVITY_H

const int MAXCHAR = 51;

class Activity {
public:
    Activity();
    // the big three
    ~Activity();
    Activity(const Activity &activity);
    const Activity & operator= (const Activity &activity);

    enum Type {athletic, food, arts, games, other};
    void setName(char *newName);
    void setLocation(char *newLocation);
    void setLevel(char *newLevel);
    void setRating(int newRating);
    void setType(Type newType);
    void getName(char *returnName);
    void getLocation(char *returnLocation) const;
    void getLevel(char *returnLevel) const;
    [[nodiscard]] int getRating() const;
    [[nodiscard]] Type getType() const;
    void printActivity();

private:
    char *name;
    char *location;
    char *level;
    int rating{};
    Type type;
};
#endif //CS162DYNAMICVARIABLESANDMEMORYMANAGEMENT_ACTIVITY_H
