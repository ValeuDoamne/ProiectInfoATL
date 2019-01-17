#include "Registru.h"

Registru::Registru()
	:n{""}, an{0}, lun{0} { }

Registru::Registru(string nn, int aan, int lluna) // Initializarea unei variabile
	:n{nn}, an{aan}, lun{lluna} { } // Ex: p{"Alexa Cosmin", 23, 5}

bool Registru::is_valid(){
	if(lun > 12 || lun < 0){
		return false;
	}
	if(an > 100 || an < 0){
		return false;
	}
	return true;
}


istream& operator>>(istream& is, Registru& p){  // Declararea operatorului de citire
	string n1,n2; // Numele si Prenumele
	int a,l; // Anul si Luna
	is >> n1 >> n2 >> a >> l; // citire sub forma Nume Prenume Anul Luna
	p = Registru{n1+' '+n2, a, l}; // variabila citita
	return is;
}

ostream& operator<<(ostream& os,const Registru& p){
	return os << p.nume() << ' ' << p.anul() << ' ' << p.luna(); // Afisarea unei variabile
}

