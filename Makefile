CC = g++
CPPFLAGS = -std=c++17 -Wall -g

main: main.o activity.o activityList.o

main.o: main.cpp main.h

activity.o: activity.cpp activity.h

activityList.o: activityList.cpp activityList.h

clean:
	rm *.o main