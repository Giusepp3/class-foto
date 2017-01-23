#include "foto.h"

namespace photos{
	
	foto::foto(){
		titolo = new char[1];
		strcpy(titolo,"");
		formato = new char[1];
		strcpy(formato,"");
		
	}
	
	foto::foto(const char* t, const char* f){
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
		formato = new char[strlen(f)+1];
		strcpy(formato,f);
		
	}
	
	foto::foto(const foto & f){
		titolo = new char[strlen(f.titolo)+1];
		strcpy(titolo,f.titolo);
		formato = new char[strlen(f.formato)+1];
		strcpy(formato,f.formato);
		
	}
	
	foto::~foto(){
		delete [] titolo;
		delete [] formato;
	}
	
	void foto::set_titolo(const char* t){
		if(titolo) delete [] titolo;
		titolo = new char[strlen(t)+1];
		strcpy(titolo,t);
	}
	
	foto& foto::operator=(const foto & f){
		if(this==&f) return *this;
		set_titolo(f.titolo);
		set_formato(f.formato);
		return *this;
	}
	
	void foto::set_formato(const char* f){
		if(formato) delete [] formato;
		formato = new char[strlen(f)+1];
		strcpy(formato,f);
		
	}
	
	void foto::print(ostream & of)const{
		of << titolo << ' ' << formato << ' ';
				
	}
	
	ostream & operator<<(ostream & of, const foto & f){
		f.print(of);
		return of;
		
	}
	
	void foto::read(istream & in){
		char buffer[800];
		in.getline(buffer,799);
		set_titolo(buffer);
		in.getline(buffer,799);
		set_formato(buffer);
		
	}
	
	istream & operator>>(istream & in, foto & f){
		f.read(in);
		return in;
	}
	
	void foto::serialize(ofstream & of)const{
		int len;
		len=strlen(titolo);
		of.write((char*)&len,sizeof(len));
		of.write(titolo,len);
		len=strlen(formato);
		of.write((char*)&len,sizeof(len));
		of.write(formato,len);
		
	}
	
	ofstream & operator<<(ofstream & of, const foto & f){
		f.serialize(of);
		return of;
	}
	
	void foto::deserialize(ifstream & in){
		int len;
		char* buffer;
		in.read((char*)&len,sizeof(len));
		buffer= new char[len+1];
		in.read(buffer,len);
		buffer[len]='\0';
		set_titolo(buffer);
		delete [] buffer;
		in.read((char*)&len,sizeof(len));
		buffer = new char[len+1];
		in.read(buffer,len);
		buffer[len]='\0';
		set_formato(buffer);
		delete [] buffer;
		
	}
	
	ifstream & operator>>(ifstream & in, foto & f){
		f.deserialize(in);
		return in;
		
	}
	
	
	
	
}
