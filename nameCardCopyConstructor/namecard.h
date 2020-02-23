#ifndef __NAMECARD_H__
#define __NAMECARD_H__

#include <iostream>

using namespace std;

namespace COMP_POS{
	enum {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard
{
	private:
		char * name;
		char * companyName;
		char * telephone;
		int rank;
		const char * returnRank() const;
		
	public:
		NameCard(const char*, const char*, const char*, int);
		NameCard(const NameCard &copy);
		~NameCard();
		void ShowNameCardInfo() const;
};

#endif