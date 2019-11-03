// Book.cpp
#include "Book.h"
//#include "Date.h"

#include <iostream> //because there are needed cerr and cout 
#include <ostream>

using std::ostream;
using std::cerr;
using std::cout;
using std::to_string;


//fist: initialize;
Book::Book(string isbn_init, string title_init, Genres gen_init, Date cprd_init, bool cktd_init)
	:isbn{isbn_init}, title{title_init}, gen{gen_init}, cpr_date{cprd_init}, ckt{cktd_init}
	
//second: verify
{
	string abc{"abcdefghijklmopqrstuvwxyz"}; //we will use this stringt to confront the final char of isbn; notice that n is absent because means new and is used for the void constructor
	bool find{0}; 
	
	//isbn è definito come una catena di nnnx dove n=intero x=char
	//una volta inserito dovrò controllare carattere per carattere che i primi tre siano interi, e l'ultimo un char
	
	//per prima cosa controllo che l'isbn sia di 4 caratteri
	if (isbn.length() != 4){
		cerr<<"invalid length of ISBN! Instead of 4 its length is "<<isbn.length()<<"\n";
		exit(1);
		}
	
	for(int i = 0; i < static_cast<int>(isbn.length()); ++i)
	{
		if(i < static_cast<int>(isbn.length())-1){
			if( (isbn.at(i)>'9') || (isbn.at(i)<'0')){// questo metodo non è ortodosso, ma certamente identifica se la cifra è intera o meno anche senza verificare che lo sia effettivamente
				cerr<<"invalid isbn code: "<<isbn<<" there is a mistake at position "<<i<<" this value is "<<isbn.at(i)<<"\n";
				exit(1);
			}
		}
		
		else{
			for(int i = 0; i < static_cast<int>(abc.length()); ++i){		
				if(isbn.at(3) == abc.at(i)){find = 1; i = static_cast<int>(abc.length());}
				}
			if(isbn.at(3) == 'n'){
				find = 1;
				cout<<"pay attention because "<<isbn<<" may be new and void"<<"\n";
				i = static_cast<int>(abc.length());}
				
			if(!find){
				cerr<<"invalid isbn code, there is a mistake at final position in: "<<isbn<<"\n";
				exit(1);	
			}
		
		}
	}
	//mi pare parecchio codice però...
	
	
	if(gen<Genres::biography || gen>Genres::periodical){
		cerr<<"this genre is not contemplated in this library \n";
		exit(1);
	
	}
	
	//presumo che la data inserita sia stata inizializzata precedentemente e che quindi sia già stata verificata
}

//ora tutte le funzioni che restituiscono senza modificare
string Book::get_isbn() const
{return isbn;}

string Book::get_title() const
{return title;}

/*Book::Genres Book::get_gen() const
{return gen;}*/

Date Book::get_date() const
{return cpr_date;}

bool Book::get_ckt() const
{return ckt;}	


string default_isbn()
{
	static int a{-1};//,b{0},c{0};
	a++;
	string a1 = to_string(a);
	
	if(a<10){return "00"+a1+"n";}
	if(a>=10 && a<100){return "0"+a1+"n";}
	if(a>=100 && a<1000){return a1+"n";}
	else{cerr<<"maximum value for isbn reached \n";}
	
	
}
/*
void print_book(Book b) const
{
	cout<<" "<<b.get_isbn()<<" "<<b.get_title()<<" "<<b.get_gen()<<" "<<b.get_ckt()<<"\n";
}
*/

