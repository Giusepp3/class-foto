#ifndef PHSTACK_H
#define PHSTACK_H
#include <iostream>
#include <cstring>
#include <fstream>
//#include "err.h"
#include "foto.h"

using namespace std;

namespace photos{
	
	typedef foto T;
	
	struct Nodo;
	
	struct Nodo{
		T elem;
		Nodo* next;
	};
	
	class pila{
		private:
			int sz;
			Nodo* testa;
			
		public:
			pila();
			pila(const char*);
			~pila();
			bool top(T &)const;
			bool empty()const{return sz==0;}
			bool full()const{return false;}
			bool push(const T&);
			bool pop(T &); //throw(err);
			void save_file(const char* filename)const;
			void stampa()const;
	};
	
	
	
	
	
	
}

#endif //PHSTACK_H
