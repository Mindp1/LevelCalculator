//
// Created by Manan Patel on 6/24/23.
//

#ifndef LEVELCALCULATOR_DATE_H
#define LEVELCALCULATOR_DATE_H
#include "Month.h"
#include <iostream>
#include <utility>
#include <cmath>


class Date {
private:
    Month month;
    long day{},year{};

    void fixDate() {
        bool needToFixAgain = true;
        while (needToFixAgain) {
            long old_day = day;
            switch (month.asLong()) {
                case 1:
                    if (day > daysInJanuary) {
                        month += 1;
                        day -= daysInJanuary;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 2:
                    if (day > daysInFebruary) {
                        month += 1;
                        day -= daysInFebruary;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 3:
                    if (day > daysInMarch) {
                        month += 1;
                        day -= daysInMarch;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 4:
                    if (day > daysInApril) {
                        month += 1;
                        day -= daysInApril;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 5:
                    if (day > daysInMay) {
                        month += 1;
                        day -= daysInMay;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 6:
                    if (day > daysInJune) {
                        month += 1;
                        day -= daysInJune;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 7:
                    if (day > daysInJuly) {
                        month += 1;
                        day -= daysInJuly;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 8:
                    if (day > daysInAugust) {
                        month += 1;
                        day -= daysInAugust;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 9:
                    if (day > daysInSeptember) {
                        month += 1;
                        day -= daysInSeptember;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 10:
                    if (day > daysInOctober) {
                        month += 1;
                        day -= daysInOctober;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 11:
                    if (day > daysInNovember) {
                        month += 1;
                        day -= daysInNovember;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
                case 12:
                    if (day > daysInDecember) {
                        month += 1;
                        day -= daysInDecember;
                    } else {
                        needToFixAgain = false;
                    }
                    break;
            }
            if (old_day == day) {
                needToFixAgain = false;
            }
        }
    }
public:

    static constexpr long daysInJanuary = 31, daysInFebruary = 28,
            daysInMarch = 31, daysInApril = 30, daysInMay = 31, daysInJune = 30,
            daysInJuly = 31, daysInAugust = 31, daysInSeptember = 30,
            daysInOctober = 31, daysInNovember = 30, daysInDecember = 31;

    constexpr static const long daysInMonths[] = {31,28,31,30,31,30,31,31,
                                                 30,31,30,31};

    [[maybe_unused]] Date(long n_month, long n_day, long n_year) :
    month{n_month, true},
    year{n_year}
    {
        if (n_day == 0) {
            n_day = 1;
        }
        day = abs(n_day);
        fixDate();
    }

    Date(Month n_month, long n_day, long n_year) :
            month{std::move(n_month)},
            year{n_year}
    {
        if (n_day == 0) {
            n_day = 1;
        }
        day = std::abs(n_day);
        fixDate();
    }

    Date() = default;

    [[nodiscard]] const Month &getMonth() const {
        return month;
    }

    [[nodiscard]] long getDay() const {
        return day;
    }

    [[nodiscard]] long getYear() const {
        return year;
    }

    void addMonths(long months) {
        year += (month.asLong() + months - 1) /12;
        //Currently on the last day of the month.
        if (day == daysInMonths[month.asLong()-1]) {
            month += months;
            day = daysInMonths[month.asLong()-1];
        } else {
            month += months;
            day = std::min(day,daysInMonths[month.asLong()-1]);
        }
    }

    bool operator > (const Date& date2) const {
        if (year != date2.year)
            return year > date2.year;
        if (month != date2.month)
            return month > date2.month;
        return day > date2.day;
    }
    bool operator < (const Date& date2) const {
        if (year != date2.year)
            return year < date2.year;
        if (month != date2.month)
            return month < date2.month;
        return day < date2.day;
    }
    Date operator + (long days) const {
        Date temp(this->month,this->day + days, this->year);
        return temp;
    }

    friend std::ostream& operator << (std::ostream& stream,
            const Date& date1) {
        return stream << date1.month.asLong() << '/' << date1.day <<
                      '/' << date1.year;
    }

    friend std::istream& operator >> (std::istream& stream, Date& date1) {
        char sep;
        return stream >> date1.month >> sep >> date1.day >> sep
            >> date1.year;
    }
};


#endif //LEVELCALCULATOR_DATE_H
