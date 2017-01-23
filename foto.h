#ifndef FOTO_H
#define FOTO_H
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

namespace photos{
	
	class foto{
		private:
			char* titolo;
			char* formato;
			void print(ostream & of)const;
			void read(istream & in);
			
		public:
			foto();
			foto(const char* t, const char* f);
			foto(const foto & f);
			~foto();
			foto & operator=(const foto & f);
			char* get_titolo()const{return titolo;}
			char* get_formato()const{return formato;}
			void set_titolo(const char*);
			void set_formato(const char*);
			void serialize(ofstream & of)const;
			void deserialize(ifstream & in);
			friend ostream & operator<<(ostream & of, const foto & );
			friend istream & operator>>(istream & in, foto & );
			friend ofstream & operator<<(ofstream & of, const foto &);
			friend ifstream & operator>>(ifstream & in, const foto &);
			
			
			
			
		
	};
	
	
	
	
	
	
}

#endif //FOTO_H
