class TimeAnalyzer {
    std::string date;
    int year, month, day;

    bool is_leap_year(int current_year) {
        if (current_year % 100 == 0 && current_year % 400 == 0) {
            return true;
        }
        else if (current_year % 100 == 0 && current_year % 4 == 0) {
            return false;
        } else if (current_year % 4 == 0) {
            return true;
        }
        else return false;
    }
    int year_to_int() {
        int accum = 0;
        for (int i = 1971; i < year; i++) {
            if (is_leap_year(i)) accum +=  366;
            else accum += 365;
        }
        return accum;
    }

    int month_to_int() {
        int accum = 0;
        if (month > 1) accum += 31;
        if (month > 2) accum += 28 + is_leap_year(year);
        if (month > 3) accum += 31;
        if (month > 4) accum += 30;
        if (month > 5) accum += 31;
        if (month > 6) accum += 30;
        if (month > 7) accum += 31;
        if (month > 8) accum += 31;
        if (month > 9) accum += 30;
        if (month > 10) accum += 31;
        if (month > 11) accum += 30;

        return accum;
    }

public:
    TimeAnalyzer(const std::string&date) : date(date) {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));

        std::cout << "Year: " << year << std::endl;
        std::cout << "Month: " << month << std::endl;
        std::cout << "day: " << day << std::endl;
    }

    int to_integer() {
        return year_to_int() + month_to_int() + day;
    }
};
class Solution {
public:
    int daysBetweenDates(string date1, string date2) {
       auto a = TimeAnalyzer(date1), b = TimeAnalyzer(date2); 

       return abs(b.to_integer() - a.to_integer());
    }
};