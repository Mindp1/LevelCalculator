//
// Created by Manan Patel on 6/15/23.
//
#include <iostream>
#include <utility>
using std::cout, std::cin, std::string;

void calculateMonthsHere(int startDate[], int endDate[], int &months_here);

int main() {
    int currentDate[3]; //= {6, 21, 2023};
    char sep;
    cout << "Enter the current date\n";
    cin >> currentDate[0] >> sep >> currentDate[1] >> sep
        >> currentDate[2];
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
                cin >> startDate[0] >> sep >> startDate[1] >> sep
                    >> startDate[2];
                cout << "Enter days on hold\n";
                cin >> daysOnHold;
                if (startDate[1] > 6) {
                    ++startDate[0];
                }
                cout << "Enter end date\n";
                cin >> endDate[0] >> sep >> endDate[1] >> sep
                    >> endDate[2];
                calculateMonthsHere(startDate, endDate, months_here);
                cout << "Another enrollment with an end date?(Yy/Nn)\n";
                cin >> yesNo;
                repeat = tolower(yesNo) == 'y';
            }
        }
        cout << "Enter start date\n";
        cin >> startDate[0] >> sep >> startDate[1] >> sep >> startDate[2];
        cout << "Enter days on hold\n";
        cin >> daysOnHold;
        if (startDate[1] > 6) {
            ++startDate[0];
        }
        calculateMonthsHere(startDate, currentDate, months_here);
        months_here -= daysOnHold / 30;
        int currentLevel = months_here / 6 + 1;
        if (currentLevel > 5) {
            currentLevel = 5;
        }
        int levelProgress = months_here % 6;
        for (int i = 0; i < 6 - levelProgress; ++i) {
            if (startDate[0] == 12) {
                startDate[0] = 1;
                ++startDate[2];
            } else {
                ++startDate[0];
            }
        }
        if (startDate[0] == 12) {
            startDate[0] = 1;
            ++startDate[2];
        } else {
            ++startDate[0];
        }
        cout << "Months here: " << months_here << '\n'
             << "Current Level: " << currentLevel << '\n'
             << "Months toward next level: " << months_here % 6 << '\n';
        cout << "Date for level " << currentLevel + 1 << ": "
             << startDate[0] << '/' << startDate[2] << '\n';
        for (int i = 0; i < 6; ++i) {
            if (startDate[0] == 12) {
                startDate[0] = 1;
                ++startDate[2];
            } else {
                ++startDate[0];
            }
        }
        cout << "Date for level " << currentLevel + 2 << ": "
             << startDate[0] << '/' << startDate[2] << '\n';
        cout << "Would you like to enter another students information?"
                "(Yy/Nn)\n";
        cin >> yesNo;
        anotherStudent = tolower(yesNo) == 'y';
    }
}

void calculateMonthsHere(int startDate[], int endDate[],
                         int &months_here) {
    if ((endDate[0] == 2 && endDate[1] == 28)
        || endDate[1] == 30 || endDate[1] == 31) {
        ++endDate[0];
    }
    while (startDate[2] < endDate[2]) {
        ++months_here;
        if (startDate[0] == 12) {
            startDate[0] = 1;
            ++startDate[2];
        } else {
            ++startDate[0];
        }
    }
    while (startDate[0] < endDate[0]) {
        ++months_here;
        if (startDate[0] == 12) {
            startDate[0] = 1;
            ++startDate[2];
        } else {
            ++startDate[0];
        }
    }
}