#include <iostream>
#include <string>
#include <vector>

class Date {
    // default private
    public:
        Date();
        Date(int a);
        Date(int y, int m, int d);

        int month() const {return m;}
        int year() const {return y;}
        int day() const {return d;}

        void add_day(int n);
    private:
        int y, m, d;
        bool is_valid();
};

Date::Date() {

}

Date::Date(int yy, int mm, int dd): y{yy}, m{mm}, d{dd} {}

bool Date::is_valid() {
    // check here
}

enum class Month {
    Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};

Month operator++(Month& m) {
    m = (m==Month::Dec) ? Month::Jan : Month(int(m) + 1);
    return m;
}

std::vector<std::string> month_tbl = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
};

std::ostream& operator<<(std::ostream& os, Month m) {
    return os << month_tbl[int(m)];
}

void Date::add_day(int n) {

}

int main() {
    Month m {Month::Jan};
    std::vector<Date> v(10, Date {});
    ++m;
}