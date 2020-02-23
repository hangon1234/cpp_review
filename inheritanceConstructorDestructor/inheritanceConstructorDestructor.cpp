#include <iostream>
#include <cstring>

using namespace std;

class MyFriendInfo
{
	private:
		char * name;
		int age;
		
	public:
		void ShowMyFriendInfo()
		{
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
		}
		MyFriendInfo(const char * name, int age) : age(age)
		{
			this->name = new char[strlen(name)+1];
			strcpy(this->name, name);
		}
		~MyFriendInfo(){ delete []name; }
};

class MyFriendDetailInfo : public MyFriendInfo
{
	private:
		char * addr;
		char * phone;
		
	public:
		void ShowMyFriendDetailInfo()
		{
			ShowMyFriendInfo();
			cout << "Address : " << addr << endl;
			cout << "Telephone : " << phone << endl << endl;
		}
		
		MyFriendDetailInfo(const char * name, int age, const char * address, const char * phone)
		: MyFriendInfo(name, age)
		{
			addr = new char[strlen(name)+1];
			strcpy(addr, address);
			this->phone = new char[strlen(phone)+1];
			strcpy(this->phone, phone);
		}
		~MyFriendDetailInfo(){ delete []addr; delete []phone; }
};

int main(void)
{
	const char * name = "Kim, Hangon";
	const int age = 24;
	const char * address = "Yongin";
	const char * phone = "010-1234-5678";
	
	MyFriendDetailInfo myFriend(name, age, address, phone);
	myFriend.ShowMyFriendDetailInfo();
	return 0;
}