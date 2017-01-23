#include <iostream>
#include <cstring>
#include <fstream>
#include "foto.h"
#include "pila.h"

using namespace std;

using namespace photos;


int main(int argc, char** argv) {
	
	foto f;
	pila p;

	for(int i=0;i<5;i++){
		cin >> f;
		p.push(f);
	}
	
	p.save_file("pila.bin");
	
	pila p2("pila.bin");
	
	p2.stampa();
	
	return 0;
}
