#include <iostream> // Declararea bibiliotecilor STL
#include <fstream>
#include <vector>  
#include <string>
#include <istream>
#include <ostream>

using namespace std;

class Registru{ 		// Declararea Clasei Registru
	string n;
	int lun, an; // variabilele private folosite

public:
	Registru();
	Registru(string nn, int aan, int lluna);
	int anul() const {return an;} // afisarea anului
	int luna() const {return lun;} // afisarea lunii
	string nume() const  {return n;} // afisarea numelui
	bool is_valid(); // Verificarea datelor
};

istream& operator>>(istream& is, Registru& p);
ostream& operator<<(ostream& os, const Registru& p);
