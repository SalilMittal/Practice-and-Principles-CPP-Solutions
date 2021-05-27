#include "Chrono.h"
#include "Invalid.h"
#include <iostream>
#include <vector>
//#include <string>

namespace Chrono {
    // Date Class
    Date::Date(int yy, Month mm, int dd) : y{ yy }, m{ mm }, d{ dd } {
        if (!is_date(yy, mm, dd)) throw Invalid{ "Invalid Date" };
    }

    bool is_date(int y, Month m, int d) {
        if (y <= 0 || y > 5000) return false;

        if (d <= 0) return false;

        if (m < Month::Jan || Month::Dec < m) return false;

        int days_max = 31;

        switch (m)
        {
        case Month::Feb:
            days_max = is_leap_year(y) ? 29 : 28;
            break;
        case Month::Apr: case Month::Jun: case Month::Sep: case Month::Nov:
            days_max = 30;
            break;
        }

        if (d > days_max) return false;

        return true;
    }

    bool is_leap_year(int y) {
        return true;
    }

    bool operator==(const Date& a, const Date& b) {
        return a.year() == b.year() &&
            a.month() == b.month() &&
            a.day() == b.day();
    }

    bool operator!=(const Date& a, const Date& b) {
        return !(a == b);
    }

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os << "(" <<
            d.year() << ", " <<
            int(d.month()) << ", " <<
            d.day() << ")";
    }

    std::istream& operator>>(std::istream& is, Date& dd) {
        int y = 0, m = 0, d = 0;
        std::vector<char> chars;

        is >> chars[0] >> chars[1] >> chars[2] >> chars[3];

        if (!is) return is;

        if (chars[0] != '(' || chars[1] != ',' || chars[2] != ',' || chars[3] != ')') {
            is.clear(std::ios_base::failbit);
            return is;
        }

        dd = Date(y, Month(m), d);

        return is;
    }
};
