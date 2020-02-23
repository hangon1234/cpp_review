#include <iostream>
#include <cstring>

using namespace std;

class Book
{
	private:
		char * title;
		char * isbn;
		const int price;
	public:
		Book(const char * title, const char * isbn, int price);
		~Book(){delete []title; delete []isbn;}
		void ShowBookInfo();
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
	Book book("Good c++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout << endl;
	EBook ebook("Good C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	return 0;
}