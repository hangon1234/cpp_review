#include <iostream>
#include <cstring>

using namespace std;

class Gun
{
	private:
		int bullet;
		
	public:
		Gun(int bnum) : bullet(bnum) {}
		void Shot()
		{
			if(bullet ==0)
				cout << "Hut BBANG!" << endl;
			else
			{
				bullet--;
				cout << "BBANG!" << endl;
			}
		}
};

class Police
{
	private:
		int handcuffs;
		Gun * pistol;
	
	public:
		Police(int bnum, int bcuffs) : handcuffs(bcuffs)
		{
			if(bnum > 0)
				pistol = new Gun(bnum);
			else
				pistol = NULL;
		}
		void PutHandcuff()
		{
			if(handcuffs == 0)
				cout << "Hut SNAP!" << endl;
			else{
				cout << "SNAP!" << endl;
				handcuffs--;
			}
		}
		void Shot()
		{
			if(pistol == NULL)
				cout << "Hut BBANG!" << endl;
			else
				pistol->Shot();
		}
		~Police()
		{
			if(pistol != NULL)
				delete pistol;
		}
		
		//copy constructor
		Police(const Police &arg) : handcuffs(arg.handcuffs)
		{
			if(arg.pistol != NULL)
				pistol = new Gun(*(arg.pistol));
			else
				pistol = NULL;
		}
		
		//assign operator overloading
		Police& operator=(const Police &arg)
		{
			handcuffs = arg.handcuffs;
			if(arg.pistol != NULL)
			{
				delete pistol;
				pistol = new Gun(*(arg.pistol));
			}else{
				delete pistol;
				pistol = NULL;
			}
			
			return *this;
		}
};

int main(void)
{
	Police pman1(1, 1); //bunm, bcuffs
	
	// Copy constructor
	Police pman2(pman1); //Police pman2 = pman1 is also correct
	pman2.Shot();
	pman2.Shot();
	pman2.PutHandcuff();
	pman2.PutHandcuff();
	cout << "****pman2 done****" << endl;
	
	//assign operator overloading
	Police pman3(1, 0);
	pman2 = pman3;
	pman2.Shot();
	pman2.Shot();
	pman2.PutHandcuff();
	cout << "****pman2 assigned and done****" << endl;
	
	return 0;
}