//
// Created by Manan Patel on 7/31/23.
//

#ifndef LEVELCALCULATOR_STUDENT_H
#define LEVELCALCULATOR_STUDENT_H

#include "Date.h"
#include <iostream>
#include <vector>

struct StartEndDatePair{
    Date startDate{};
    Date endDate{};
    long daysOnHold{0};
};

class Student {
private:
    std::vector<StartEndDatePair> EnrollmentPeriods{};
    bool invalidEnrollment = false;
    long monthsEnrolled{};
    long level{1};
public:

    [[nodiscard]] bool hasInvalidEnrollment() const {
        return invalidEnrollment;
    }

    Student() = default;

    //Never includes the current month
    [[nodiscard]] long getMonthsEnrolled() const {
        return monthsEnrolled;
    }

    [[maybe_unused]] Student(const Date& start, const Date& end, long holdDays) {
        if (start < end) {
            EnrollmentPeriods.push_back({start,end,holdDays});
        } else {
            invalidEnrollment = true;
        }
        calculateMonthsEnrolled();
    }

    void addEnrollment(const Date& start, const Date& end, long holdDays) {
        if (start < end) {
            EnrollmentPeriods.push_back({start,end,holdDays});
            calculateMonthsEnrolled();
            calculateLevel();
        } else {
            invalidEnrollment = true;
        }
    }

    [[nodiscard]] long getLevel() const {
        return level;
    }

    void calculateMonthsEnrolled() {
        monthsEnrolled = 0;

        for (auto i = EnrollmentPeriods.begin();
             i < EnrollmentPeriods.end(); ++i) {
            Date temp(i->startDate);

            // In the first month of the enrollment, skip it if it starts
            // after the 7th day of the month
            if (temp.getDay() > 7) {
                temp.addMonths(1);
            }
            // Doesn't run on the last month
            while (temp.getMonth() != i->endDate.getMonth() ||
                   temp.getYear() != i->endDate.getYear()) {
                ++monthsEnrolled;
                temp.addMonths(1);
            }
            // Adds the last month, as long as it isn't the current month
            if (i != EnrollmentPeriods.end() - 1) {
                ++monthsEnrolled;
            }
            // If the end month doesn't last for the whole month, then
            // discount it
            if (i->endDate.getDay() <
                Date::daysInMonths[i->endDate.getMonth().asLong()-1] - 7
                && i != EnrollmentPeriods.end() - 1) {
                --monthsEnrolled;
            }
            monthsEnrolled -= i->daysOnHold/30;
        }
    }

    void calculateLevel() {
        level = monthsEnrolled/6 + 1;
    }

    [[nodiscard]] Date dateForNextLevel() const {
        Date temp = EnrollmentPeriods.back().endDate;
        temp = temp + -(temp.getDay() - 1);
        temp.addMonths(6 -(monthsEnrolled%6));
        return temp;
    }

    [[nodiscard]] long nextLevel() const {
        return level + 1;
    }

    [[nodiscard]] Date dateForNextNextLevel() const {
        Date temp = EnrollmentPeriods.back().endDate;
        temp = temp + -(temp.getDay() - 1);
        temp.addMonths(6-(monthsEnrolled%6) + 6);
        return temp;
    }

    [[nodiscard]] long nextNextLevel() const {
        return level + 2;
    }

};


#endif //LEVELCALCULATOR_STUDENT_H
