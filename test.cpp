//
// Created by Manan Patel on 7/16/23.
//
#include "Date.h"
#include "Student.h"
using std::cout, std::cin;
int main() {
//    Month month(23);
//    cout << month << ' ' << ++month << ' ' << ++month << '\n';
//    Date date(10,31,2023);
//    long daysToAdd;
//    cout << "Enter the date\n";
//    cin >> date;
//    cout << "\nThe date is : " << date << "\nEnter the days to add\n";
//    cin >> daysToAdd;
//    Date temp((date + daysToAdd));
//    cout << "The added date is: " << temp << "\ntest: " << (temp + 30) ;


//    Student s1;
//
//    s1.addEnrollment({6,3,2021},{10,1,2021},0);
//    cout << s1.getMonthsEnrolled() << '\n';
//    s1.addEnrollment({6,14,2022},{11,30,2022},0);
//    cout << s1.getMonthsEnrolled() << '\n';
//    s1.addEnrollment({12,1,2022},{8,7,2023},0);
//    cout << s1.getMonthsEnrolled();


    //Actual implemenation
    Date currentDate;
    cout << "Enter the current date\n";
    cin >> currentDate;
    bool anotherStudent = true;
    bool hasMultipleEnrollments = false;
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