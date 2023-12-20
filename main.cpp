//
// Created by Manan Patel on 7/16/23.
//
#include "Date.h"
#include "Student.h"
using std::cout, std::cin;
// TODO : Add a warning if the student had an invalid entry
int main() {
    Date currentDate;
    cout << "Enter the current date (MM/DD/YYYY)\n";
    cin >> currentDate;
    bool anotherStudent = true;
    bool hasMultipleEnrollments;
    char yesNo;
    while (anotherStudent) {
        Student s1;
        cout << "Does the student have multiple enrollments?(Yy/Nn)\n";
        cin >> yesNo;
        hasMultipleEnrollments = toupper(yesNo) == 'Y';
        while (hasMultipleEnrollments) {
            Date startDate, endDate;
            long daysOnHold = 0;
            cout << "Enter the start date\n";
            cin >> startDate;
            cout << "Enter the end date\n";
            cin >> endDate;
            cout << "Enter the days on hold\n";
            cin >> daysOnHold;
            s1.addEnrollment(startDate,endDate,daysOnHold);
            cout << "Does the student have another enrollment with an "
                    "end date?(Yy/Nn)\n";
            cin >> yesNo;
            hasMultipleEnrollments = toupper(yesNo) == 'Y';
        }
        Date startDate;
        long daysOnHold = 0;
        cout << "Enter the start date\n";
        cin >> startDate;
        cout << "Enter the days on hold\n";
        cin >> daysOnHold;
        s1.addEnrollment(startDate,currentDate,daysOnHold);
        cout << "The student has been here for: "
             << s1.getMonthsEnrolled() << " months" << '\n'
             << "Current level: " << s1.getLevel() << '\n'
             << "They will be level " << s1.nextLevel()
             << " On " << s1.dateForNextLevel() << '\n'
             << "And they will be level " << s1.nextNextLevel()
             << " On " << s1.dateForNextNextLevel() <<'\n';
        cout << "Would you like to enter another student's information?"
                "(Yy/Nn)";
        cin >> yesNo;
        anotherStudent = toupper(yesNo) == 'Y';
    }
}