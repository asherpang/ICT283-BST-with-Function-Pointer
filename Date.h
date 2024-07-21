// Date.h

//---------------------------------------------------------------------------------

#ifndef DATE_H
#define DATE_H

//---------------------------------------------------------------------------------

#include <iostream>

//---------------------------------------------------------------------------------

/**
 * @class Date
 * @brief Represents a date with day, month, and year components.
 *
 * The Date class provides functionality to manage a date with its day, month, and year.
 * It supports setting and getting these components individually. It also supports
 * input and output through stream operators.
 *
 * @author Asher Pang
 * @version 01
 * @date 23/06/2024 Asher Pang, Started
 *
 * @bug No known bugs at the moment.
 *
 */
class Date {
public:
    /**
     * @brief Constructs a Date object with default value of 1/1/1900.
     */
    Date();

    /**
     * @brief Constructs a Date object with specified day, month, and year.
     * @param day Day of the month (1-31).
     * @param month Month of the year (1-12).
     * @param year Year.
     */
    Date(int day, int month, int year);

    /**
     * @brief Sets the day of the month.
     * @param day Day of the month (1-31).
     */
    void SetDay(int day);

    /**
     * @brief Sets the month of the year.
     * @param month Month of the year (1-12).
     */
    void SetMonth(int month);

    /**
     * @brief Sets the year.
     * @param year Year.
     */
    void SetYear(int year);

    /**
     * @brief Gets the day of the month.
     * @return Day of the month.
     */
    int GetDay() const;

    /**
     * @brief Gets the month of the year.
     * @return Month of the year.
     */
    int GetMonth() const;

    /**
     * @brief Gets the year.
     * @return Year.
     */
    int GetYear() const;

    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;
    bool operator>(const Date& other) const;

private:
    int m_day;   ///< Day of the month.
    int m_month; ///< Month of the year.
    int m_year;  ///< Year.
};

/**
 * @brief Output stream operator for the Date class.
 *
 * This operator overload allows for the Date object to be output to an output stream
 * in the format day/month/year.
 *
 * @param os Reference to the output stream.
 * @param date Reference to the Date object to be output.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& os, const Date& date);

/**
 * @brief Input stream operator for the Date class.
 *
 * This operator overload allows for the Date object to be input from an input stream
 * expecting the format day/month/year.
 *
 * @param is Reference to the input stream.
 * @param date Reference to the Date object to be populated.
 * @return Reference to the input stream.
 */
std::istream& operator>>(std::istream& is, Date& date);

#endif // DATE_H
