# include <iostream>

enum class color{red, green, blue};
enum class months{jan, feb, mar, apr, may, jun,
                  jul, aug, sep, oct, nov, dec};

class Date {
    unsigned int day_;
    months month_;
    unsigned int year_;

public:
    Date(const unsigned int day, const months month, const unsigned int year) :
        day_{day},
        month_{month},
        year_{year}{}
    
    ~Date() = default;

    int day() const {
        return day_;
    }
    months month() const {
        return month_;
    }
    int year() const {
        return year_;
    }

    void add_months(const unsigned int n);

    void add_days(const unsigned int n);

    void print_date() const {
        std::cout << day_ << " " << (unsigned int)month_ + 1 << " " << year_ << std::endl;
    }
};

void Date::add_months(const unsigned int n){
    if ((unsigned int)month_ + n > 11) {
        unsigned int old_month = (unsigned int)month_;
        month_ = months::jan;
        year_++;
        add_months(n - (12 - old_month));
    }
    else {
        month_ = (months)((int)month_ + n);
    }
    
}

void Date::add_days (const unsigned int n){
    unsigned int month_days;
    switch (month_)
    {
    case months::feb:
        month_days = 28;
        break;
    
    case months::apr: case months::jun:
    case months::sep: case months::nov:
        month_days = 30;
        break;

    default:
        month_days = 31;
        break;
    }
    
    if(n+day_ > month_days) {
        unsigned int old_day = day_;
        day_ = 1;
        add_months(1);
        add_days(n-(month_days-old_day));
    }
    else {
        day_ += n;
    }
}

bool operator==(const Date& lhs, const Date& rhs) {
    if(lhs.day() == rhs.day() &&
       lhs.month() == rhs.month() &&
       lhs.year() == rhs.year()) {
           return true;
       }
    return false;
}

bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.day() << " " << (unsigned int)d.month() + 1 << " " << d.year();
    return os; 
}

bool is_leap(const int y) {
    if (y%400 == 0) {
        return true;
    }
    if(y%100 == 0) {
        return false;
    }
    return y%4 == 0;
}

int main() {
    Date my_date = Date(20, months::jan, 2000);

    my_date.print_date();
    my_date.add_months(25);
    my_date.print_date();
    my_date.add_days(50);
    my_date.print_date();
    my_date.add_days(5000);
    my_date.print_date();

    Date date1 = Date(20, months::jan, 2000);
    Date date2 = Date(20, months::jan, 2000);
    std::cout << (date1==date2) << (date1!=date2) << (date1==my_date) << std::endl;
    std::cout << my_date << std::endl;


    return 0;
}