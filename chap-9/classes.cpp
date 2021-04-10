#include <iostream>
#include <string>
#include <vector>
using namespace std;


Date& default_date() {
    /* Epoch Date */
    static constexpr int EPOCH_YEAR = 190;
    static constexpr Month EPOCH_MONTH = Month::Jan;
    static constexpr int EPOCH_DAY = 1;

    static Date dd {EPOCH_YEAR, EPOCH_MONTH, EPOCH_DAY};
    return dd;
}

class Invalid {
    public: 
        Invalid(string err): msg{err} {} 
        string what() {return msg;}
    private:
        string msg = "Invalid Exception Thrown";
};

enum class Month {
    Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec
};


class Date {
    public:
        /* Default Constructor */
        Date(): y{default_date().year()}, m{default_date().month()}, d{default_date().day()} {}

        /* Constructor */
        Date(int yy, Month mm, int dd): y{yy}, m{mm}, d{dd} {
            if(!is_valid()) throw Invalid{"Invalid Date"};
        }

        /* Member function declarations */
        int year() {return y;}
        Month month() {return m;}
        int day() {return d;}

        void add_day(int n);
    private:
        int y;
        int d;
        Month m;
        bool is_valid();
};

bool Date::is_valid() {
    if(int(m) < 1 || 12 < int(m)) return false;
    return true;
}

void Date::add_day(int n) {d++;}

ostream& operator<<(ostream& os, Month m) {
    const vector<string> month_tbl = {
        "January", "February", "March", "April",
        "May", "June", "July", "August", "September"
        "October", "November", "December"
    };
    return os << month_tbl[int(m)];
}

int main() {
    try {
        // Date d {2004, Month::Feb, 31};
        // cout << d.month() << "\n";
        // d.add_day(2);
        Date d2{1};
        cout << default_date().year();
    } catch(Invalid e) {
        cerr << e.what();
    }
}