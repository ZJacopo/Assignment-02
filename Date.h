#ifndef DATE_H
#define DATE_H

#include <ostream>

// simple Date (use Month type)
class Date {
public:
	enum Month {
		jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	// constructors
	Date(int y, Month m, int d);    // check for valid date and initialise
	Date();                         // default constructor

	// const members: can't modify the object
	int year() const;
	Month month() const;
	int day() const;

	// non-const members
	void add_year(int n);
	void add_month(int n);
	void add_day(int n);
private:
	int y;      // year
	Month m;
	int d;      // day of month
// ho provato, sbagliando, a mettere la dichiarazione della funzione di default qui dentro, ma ovviamente non funziona, se la metto fuori
// invece si e posso richiamarla dal main senza problemi
};

// operators
std::ostream& operator<<(std::ostream& os, const Date& d);
const Date& default_date();
#endif
