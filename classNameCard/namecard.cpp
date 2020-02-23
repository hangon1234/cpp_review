#include "namecard.h"
#include <cstring>

using namespace std;

NameCard::NameCard(const char * _name, const char * _companyName,
						const char * _telephone, int rank) : rank(rank)
{
	name = new char[strlen(_name)+1];
	strcpy(name, _name);
	
	companyName = new char[strlen(_companyName)+1];
	strcpy(companyName, _companyName);
	
	telephone = new char[strlen(_telephone)+1];
	strcpy(telephone, _telephone);
}

NameCard::~NameCard()
{
	delete []name;
	delete []companyName;
	delete []telephone;
}

void NameCard::ShowNameCardInfo() const
{
	cout << "Name: " << name << endl;
	cout << "Company: " << companyName << endl;
	cout << "Telephone: " << telephone << endl;
	cout << "Rank: " << returnRank() << endl << endl;;
}

const char* NameCard::returnRank() const
{
	switch(rank)
	{
		case COMP_POS::CLERK:
			return "CLERK";
		case COMP_POS::SENIOR:
			return "SENIOR";
		case COMP_POS::ASSIST:
			return "ASSIST";
		case COMP_POS::MANAGER:
			return "MANAGER";
		default:
			return "";
	};
}