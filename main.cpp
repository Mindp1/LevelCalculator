//
// Created by Manan Patel on 6/15/23.
//
#include <iostream>
#include <utility>
using std::cout, std::cin, std::string;

enum index {
    month,
    day,
    year
};

void calculateMonthsHere(int startDate[], int endDate[], int &months_here);

int main() {
    int currentDate[3]; //= {6, 21, 2023};
    char sep;
    cout << "Enter the current date\n";
    cin >> currentDate[month] >> sep >> currentDate[day] >> sep
        >> currentDate[year];
    bool anotherStudent = true;
    while (anotherStudent) {
        int startDate[3]; // month, day, year
        int months_here = 0;
        int daysOnHold = 0;

        bool hasMultipleEnrollments = false, repeat = true;
        char yesNo;
        cout << "Does the student have multiple enrollments?(Yy/Nn)\n";
        cin >> yesNo;
        if (tolower(yesNo) == 'y') {
            hasMultipleEnrollments = true;
        } else {
            repeat = false;
        }
        while (repeat) {
            if (hasMultipleEnrollments) {
                int endDate[3];
                cout << "Enter start date\n";
                cin >> startDate[month] >> sep >> startDate[day] >> sep
                    >> startDate[year];
                cout << "Enter days on hold\n";
                cin >> daysOnHold;
                if (startDate[day] > 6) {
                    ++startDate[month];
                }
                cout << "Enter end date\n";
                cin >> endDate[month] >> sep >> endDate[day] >> sep
                    >> endDate[year];
                calculateMonthsHere(startDate, endDate, months_here);
                months_here -= daysOnHold / 30;
                cout << "Another enrollment with an end date?(Yy/Nn)\n";
                cin >> yesNo;
                repeat = tolower(yesNo) == 'y';
            }
        }
        cout << "Enter start date\n";
        cin >> startDate[month] >> sep >> startDate[day] >> sep >>
        startDate[year];
        cout << "Enter days on hold\n";
        cin >> daysOnHold;
        if (startDate[day] > 6) {
            ++startDate[month];
        }
        calculateMonthsHere(startDate, currentDate, months_here);
        ++months_here; //Includes this month
        months_here -= daysOnHold / 30;
        int currentLevel = months_here / 6 + 1;
        if (currentLevel > 5) {
            currentLevel = 5;
        }
        int levelProgress = months_here % 6; //Includes this month
        for (int i = 0; i < 6 - levelProgress; ++i) {
            if (startDate[month] == 12) {
                startDate[month] = 1;
                ++startDate[year];
            } else {
                ++startDate[month];
            }
        }
        if (startDate[month] == 12) {
            startDate[month] = 1;
            ++startDate[year];
        } else {
            ++startDate[month];
        }
        cout << "Months here: " << months_here << '\n'
             << "Current Level: " << currentLevel << '\n'
             << "Months toward next level: " << months_here % 6 << '\n';
        cout << "Date for level " << currentLevel + 1 << ": "
             << startDate[month] << '/' << startDate[year] << '\n';
        for (int i = 0; i < 6; ++i) {
            if (startDate[month] == 12) {
                startDate[month] = 1;
                ++startDate[year];
            } else {
                ++startDate[month];
            }
        }
        cout << "Date for level " << currentLevel + 2 << ": "
             << startDate[month] << '/' << startDate[year] << '\n';
        cout << "Would you like to enter another students information?"
                "(Yy/Nn)\n";
        cin >> yesNo;
        anotherStudent = tolower(yesNo) == 'y';
    }
}

void calculateMonthsHere(int startDate[], int endDate[],
                         int &months_here) {
    if ((endDate[month] == 2 && endDate[day] == 28)
        || endDate[day] == 30 || endDate[day] == 31) {
        ++endDate[month];
    }
    while (startDate[year] < endDate[year]) {
        ++months_here;
        if (startDate[month] == 12) {
            startDate[month] = 1;
            ++startDate[year];
        } else {
            ++startDate[month];
        }
    }
    while (startDate[month] < endDate[month]) {
        ++months_here;
        if (startDate[month] == 12) {
            startDate[month] = 1;
            ++startDate[year];
        } else {
            ++startDate[month];
        }
    }
//    ++months_here; //Includes this month //NOT right place to put
}