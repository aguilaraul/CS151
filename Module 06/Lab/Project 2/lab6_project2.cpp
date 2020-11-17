/**
 * lab6_project2.cpp
 *
 * Author:  Raul Aguilar
 * Date:    November 6, 2020
 *
 * CS 151 3228 Module 6 Lab Project 2
 * create a TimeDate class that is owned by an Event class,
 * demonstrating composition.
 *
 */
#include <iostream>
using namespace std;

class TimeDate {
private:
    int hour, minute, day;
    string month;
public:
    TimeDate(int hour, int minute, int day, string month) :
    hour(hour),
    minute(minute),
    day(day),
    month(month)
    {

    }
    string getTimeDate() {
        string print_hour = to_string(hour);
        string am_pm = (hour < 12 ? "am" : "pm");
        if(hour == 0) {
            print_hour = "12";
        }
        if(hour > 12) {
            print_hour = to_string(hour - 12);
        }
        return month + " " + to_string(day) +
            " at " + print_hour + ":" +
            (minute < 10 ? "0" : "") + to_string(minute) + am_pm;
    }
};

class Event {
private:
    TimeDate start_time, end_time;
    string description;
public:
    Event(int start_hour, int start_minute, int start_day, string start_month,
          int end_hour, int end_minute, int end_day, string end_month,
          string description) :
          start_time(start_hour, start_minute, start_day, start_month),
          end_time(end_hour, end_minute, end_day, end_month)
    {
        this->description = description;
    }
    string getEvent() {
        return this->description + " starts at " +
            start_time.getTimeDate() +
            ", ends at " +
            end_time.getTimeDate();
    }
};


int main() {
    Event party(17, 30, 14, "Oct.",
                20, 30, 14, "Oct.",
                "My Birthday Party");
    cout << party.getEvent() << endl;

    Event inauguration(0, 0, 20, "Jan.",
                       23, 59, 20, "Jan.",
                       "Presidential Inauguration");
    cout << inauguration.getEvent() << endl;

    return 0;
}
