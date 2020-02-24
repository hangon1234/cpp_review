#include <iostream>
#include <cstring>

using namespace std;

class Book
{
	private:
		char * title;
		char * isbn;
		int price;
	public:
		Book(const char * title, const char * isbn, int price);
		~Book(){delete []title; delete []isbn;}
		void ShowBookInfo();
		
		//copy constructor
		Book(const Book &arg) : price(arg.price)
		{
			title = new char[strlen(arg.title)+1];
			strcpy(title, arg.title);
			isbn = new char[strlen(arg.isbn)+1];
			strcpy(isbn, arg.isbn);
		}
		
		//assign operator overloading
		Book& operator=(const Book &arg)
		{
			price = arg.price;
			delete []title; delete []isbn;
			title = new char[strlen(arg.title)+1];
			strcpy(title, arg.title);
			isbn = new char[strlen(arg.isbn)+1];
			strcpy(isbn, arg.isbn);
			return *this;
		}
};

Book::Book(const char * title, const char * isbn, int price)
 : price(price)
 {
	this->title = new char[strlen(title)+1];
	strcpy(this->title, title);
	this->isbn = new char[strlen(isbn)+1];
	strcpy(this->isbn, isbn);
 }
 
 void Book::ShowBookInfo()
 {
	 cout << "Title : " << title << endl;
	 cout << "ISBN : " << isbn << endl;
	 cout << "Price : " << price << endl;
 }
 
class EBook : public Book
{
	private:
		char * DRMKey;
	public:
		EBook(const char * title, const char * isbn, int price, const char * DRMKey);
		~EBook(){delete []DRMKey;}
		void ShowEBookInfo();
		//copy constructor
		EBook(const EBook &arg) : Book(arg)
		{
			delete []DRMKey;
			DRMKey = new char[strlen(arg.DRMKey)+1];
			strcpy(DRMKey, arg.DRMKey);
		}
		//assign operator overloading
		EBook& operator=(const EBook &arg)
		{
			Book::operator=(arg);
			delete []DRMKey;
			DRMKey = new char[strlen(arg.DRMKey)+1];
			strcpy(DRMKey, arg.DRMKey);
			return *this;
		}
};

EBook::EBook(const char * title, const char * isbn, int price, const char * DRMKey) : Book(title, isbn, price)
{
	this->DRMKey = new char[strlen(DRMKey)+1];
	strcpy(this->DRMKey, DRMKey);
}

void EBook::ShowEBookInfo()
{
	ShowBookInfo();
	cout << "Auth Key : " << DRMKey << endl;
}

int main(void)
{
	//book
	Book book1("Good c++", "555-12345-890-0", 20000);
	book1.ShowBookInfo();
	cout << endl;
	//Copy constructor
	cout << "test book copy constructor" << endl;
	Book book2 = book1;
	book2.ShowBookInfo();
	cout << "end of book copy constructor" << endl;
	//assign operator= overloading
	cout << "test operator= overloading" << endl;
	Book book3("New book", "111-22222-333-4", 15400);
	book2 = book3;
	book2.ShowBookInfo();
	cout << "end of operator overloading test" << endl;
	
	//ebook
	cout << endl << "New ebook" << endl;
	EBook ebook1("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook1.ShowEBookInfo();
	//copy constructor
	cout << "copy constructor test" << endl;
	EBook ebook2 = ebook1;
	ebook2.ShowBookInfo();
	cout << "end of copy constructor test" << endl;
	//assign operator= overloading
	EBook ebook3("EBook3", "111-22222-332-4", 5000, "secret");
	ebook3.ShowBookInfo();
	ebook2 = ebook3;
	ebook2.ShowEBookInfo();
	cout << "End of program!" << endl;
	
	return 0;
}