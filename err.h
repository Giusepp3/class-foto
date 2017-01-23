#ifndef ERR_H
#define ERR_H
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class err{
	private:
		string errfunc;
		string errmsg;
	public:
		err(const char* a, const char* b){errfunc=a; errmsg=b;}
		friend ostream & operator<<(ostream & out, const err & e){out << errfunc << endl << errmsg << endl;}
	
};


#endif //ERR_H
