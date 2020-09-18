#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

int main()
{
    string day[] = {"Sunday", "Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday"};
    string month[] = {"January", "February", "March", "April", "May",
                        "June", "July", "August", "September", "October",
                        "November", "December"};
    time_t now = time(NULL);
    tm *local = localtime(&now);

    // Print M/D/YY
    cout << local->tm_mon;
    cout << "/" << local->tm_mday;
    cout << "/" << local->tm_year - 100 << endl;

    // Print Month Day, Year
    cout << month[local->tm_mon];
    cout << " " << local->tm_mday;
    cout << ", " << local->tm_year + 1900 << endl;

    // Print D-Mon-Year
    cout << local->tm_mday;
    cout << "-" << month[local->tm_mon].substr(0, 3);
    cout << "-" << local->tm_year + 1900 << endl;

    // Print 24-hour time
    cout << local->tm_hour << ":";
    cout << setw(2) << setfill('0') << local->tm_min << endl;

    // Print 12-hour clock
    cout << local->tm_hour%12 << ":";
    cout << setw(2) << setfill('0') << local->tm_min << endl;

    // my birthday tm struct
    tm birthday;
    birthday.tm_year = 1995 - 1900;
    birthday.tm_mon = 6;
    birthday.tm_mday = 15;
    birthday.tm_hour = 12;
    birthday.tm_min = 0;
    birthday.tm_sec = 0;
    birthday.tm_isdst = 1;

    // Epoch of birth
    cout << endl;
    time_t time_of_birthday = mktime(&birthday);
    cout << ctime(&time_of_birthday);
    cout << "I was born " << time_of_birthday << " seconds after epoch!" << endl;

    // Seconds in one week
    int seconds_per_week = 24*7*60*60;

    // Week before birthday
    time_t week_before_birthday = time_of_birthday - seconds_per_week;
    cout << endl << ctime(&week_before_birthday);
    return 0;
}
