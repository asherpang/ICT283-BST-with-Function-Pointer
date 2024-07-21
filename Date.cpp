#include "Date.h"

// Default constructor initializes Date to 01/01/1900
Date::Date() : m_day(1), m_month(1), m_year(2000) {}

// Parameterized constructor sets Date to specified values
Date::Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

// Setter for day
void Date::SetDay(int day) {
    m_day = day;
}

// Setter for month
void Date::SetMonth(int month) {
    m_month = month;
}

// Setter for year
void Date::SetYear(int year) {
    m_year = year;
}

// Getter for day
int Date::GetDay() const {
    return m_day;
}

// Getter for month
int Date::GetMonth() const {
    return m_month;
}

// Getter for year
int Date::GetYear() const {
    return m_year;
}

bool Date::operator<(const Date& other) const {
    if (m_year < other.m_year) return true;
    if (m_year > other.m_year) return false;
    if (m_month < other.m_month) return true;
    if (m_month > other.m_month) return false;
    return m_day < other.m_day;
}

// Comparison operator ==
bool Date::operator==(const Date& other) const {
    return m_day == other.m_day && m_month == other.m_month && m_year == other.m_year;
}

bool Date::operator>(const Date& other) const {
    if (m_year > other.m_year) return true;
    if (m_year < other.m_year) return false;
    if (m_month > other.m_month) return true;
    if (m_month < other.m_month) return false;
    return m_day > other.m_day;
}

// Overloaded << operator for output stream
std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.GetDay() << '/' << date.GetMonth() << '/' << date.GetYear();
    return os;
}

// Overloaded >> operator for input stream
std::istream& operator>>(std::istream& input, Date& date) {
    int day, month, year;
    char slash1, slash2;
    input >> day >> slash1 >> month >> slash2 >> year; // read day, month, year separated by slashes
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);
    return input;
}
