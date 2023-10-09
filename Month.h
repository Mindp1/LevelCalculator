//
// Created by Manan Patel on 6/24/23.
//

#ifndef LEVELCALCULATOR_MONTH_H
#define LEVELCALCULATOR_MONTH_H

#include <string>
#include <iostream>

std::string long_to_month(size_t month_val);

class Month {
private:
    std::string name;
    long month{0};
    void fixMonthOver12(bool isConstructorUsed = false) {
        if (month > 12) {
            month %= 12;
        }
        name = long_to_month(month);
    }

public:
    const std::string &getName() const {
        return name;
    }

public:
    Month() :
            name{"January"},
            month{1}
    {
    }
    explicit Month(long month_value)
    {
        month = month_value;
        fixMonthOver12(true);
        name = long_to_month(month);
    }

    Month(long month_value, bool fixMonth){
        if (fixMonth) {
            month = month_value;
            fixMonthOver12();
        } else {
            setMonth(month_value);
            name = long_to_month(month);
        }
    }
    bool setMonth(size_t month_val) {
        if (month_val > 0 && month_val < 13) {
            month = static_cast<long>(month_val);
            name = long_to_month(month_val);
            return true;
        } else {
            return false;
        }
    }

    long asLong() const {
        return month;
    }

    Month operator + (long num_months) const {
        long result = month+ num_months;
        if ( result < 13 && result > 0) {
            return Month{result};
        } else if (result > 12) {
            return {month + num_months%12, true};
        } else {// if( result < 1)
            return {labs(result) + 1, true};
        }
    }

    Month operator - (long num_months) const {
        return this->operator+(-num_months);
    }

    Month& operator ++ () {
        month = month % 12 == 0 ? 1 : month + 1;
        name = long_to_month(month);
        return *this;
    }

    Month operator ++ (int) {
        const Month temp(*this);
        ++(*this);
        return temp;
    }

    Month& operator += (long num_months) {
        *this = *this + num_months;
        name = long_to_month(month);
        return *this;
    }

    bool operator > (const Month& month2) const {
        return month > month2.month;
    }

    bool operator < (const Month& month2) const {
        return month < month2.month;
    }

    bool operator != (const Month& month2) const {
        return month != month2.month;
    }

    friend std::ostream&  operator << (std::ostream& stream, const Month& month1){
        return stream << month1.month << ' ' << month1.name;
    }

    friend std::istream& operator >> (std::istream& stream, Month&
    month1) {
        stream >> month1.month;
        month1.fixMonthOver12();
        month1.name = long_to_month(month1.month);
        return stream;
    }
};

#endif //LEVELCALCULATOR_MONTH_H
