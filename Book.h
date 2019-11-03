// Book.h

#ifndef BOOK_H
#define BOOK_H
#include <ostream>
#include <string>

#include "Date.h"

using std::string;

//define Book class
class Book{
	
	public:
	//first we define an 'enum' to operate with genres
	enum class Genres {
		biography=1, children, fiction, horror, nonfiction, periodical 
	};
	
	//decleare constructor
	Book(string isbn, string title, Genres gen, Date cpr_date, bool ckt);
	//Book();//I don't know if it can be used
	
	//const members than can't modify the object
	//for now i simply create one for each of the parametres
	string get_isbn() const;
	string get_title() const;
	Genres get_gen() const;
	Date get_date() const;
	bool get_ckt() const;
	
	
	
	//void print_book() const;
	
	//now can be useful to define some fcts to work on every book, something like 
	
	//now all parameters
	private:
	string isbn;
	string title;
	Genres gen;
	Date cpr_date;
	bool ckt;
	
	
};

string default_isbn();


#endif
