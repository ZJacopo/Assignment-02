// main.cpp
#include "Book.h"
#include "Date.h"
#include <iostream>

using std::cout;

int main()
{
	//if you have to insert a new book you must create a new Date variable and use that
	Date def_date = default_date();
	cout << "Default date: " << def_date <<"\n";
	Date new_date = default_date();
		new_date.add_day(15);
		
	string isbn_1;
		isbn_1 = default_isbn();
	
	//if the program finds an error it stops
	//in this case because of isbn code
	//Book def_b_1{"1v3n", "first_book", Book::Genres::fiction, def_date, false};
	Book def_b_2{"123c", "second_book", Book::Genres::horror, new_date, true};
	
	//if you insert a genre that doesn't belong to enum it finds the error in two ways, one that leads to the exit(1)
	//happens when Book::Genres::wrong_genre; the other with a cerr static_cast<Book::Genres>(n>6)
	Book def_b_3{isbn_1, "third_book", static_cast<Book::Genres>(1), def_date, false};
	
	//in this case for the date
	//Book def_b_4{"123n", "fourth_book", Book::Genres::catastropy, def_date.add_day(15), true};
	
	/* funzionano
	cout<<"isbn "<<def_b_3.get_isbn()<<"\n";
	cout<<"title "<<def_b_2.get_title()<<"\n";
	cout<<"this book was published in "<<def_b_2.get_date()<<"\n";
	cout<<"checked? "<<def_b_2.get_ckt()<<"\n";
	*/

}
