/*

	Proiect: Registru Discoteca implementare orientata pe obiecte C++
	Autor: Alexa Constantin-Cosmin

	Se compileaza folosind comanda: g++ main.cpp
*/


#include <iostream> // Declararea bibiliotecilor STL
#include <fstream>
#include <vector>  
#include <string>
#include <istream>
#include <ostream>


using namespace std; // spatiul standard de lucru


class Registru{ 		// Declararea Clasei Registru
	string n;
	int lun, an; // variabilele private folosite

public:
	Registru() 	// Declararea variabilei defaule ex: "Registru p;"
		:n{""}, an{0}, lun{0} { } 
	Registru(string nn, int aan, int lluna) // Initializarea unei variabile
		:n{nn}, an{aan}, lun{lluna} { } // Ex: p{"Alexa Cosmin", 23, 5}
	int anul() const {return an;} // afisarea anului
	int luna() const {return lun;} // afisarea lunii
	string nume() const  {return n;} // afisarea numelui
	bool is_valid(); // Verificarea datelor
};


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

void citire(vector<Registru>& v,int frecventa[]){ // Declarare functiei de citire
	cout << "Introduceti numele fisierului: ";
	string fisier; 
	cin >> fisier; // citirea fisierului
	ifstream fin{fisier}; // deschiderea fisierului
	Registru p; // Varibila de tip Registru care va fi citita
	while(fin >> p){  // Citirea din fisier pana la EOF
		if(p.is_valid()){ // Verificarea validitatii
			v.push_back(p); // Formarea vectorului
			frecventa[p.anul()]++; // Vectorul de frecventa cu anii
		}
	}
}

void prelucrare(const vector<Registru>& v,int& ani, int& luni){
	ani = 0;
	luni = 0;
	for(Registru p : v){ // Folosirea ranged loop fiind mai usor decat for(int i = 0;i < v.size(); i++)
		ani += p.anul(); // Adunarea anilor
		luni += p.luna(); // Adunarea lunilor
		if(luni > 12){  // Verificarea lunilor sa nu prezinte valori peste un an
			ani++;
			luni/=12;
		}
	
	}
}

void afisare(const vector<Registru>& v,int frecventa[], int ani, int luni){
	cout << "Introduceti fisierul de iesire: ";
	string fisier;
	cin >> fisier;
	ofstream fout{fisier};
	for(int i = 0; i < 100; i++)
		if(frecventa[i] != 0){ // verificare de persoane existente cu ani
			if(frecventa[i] == 1)
				fout << "Este o persoana de " << i << " ani\n"; // Persoanelor cu aceeasi ani
			else fout << "Sunt " << frecventa[i] << " persoane cu " << i << " ani\n";
		}
	fout << "Media de varsta este " << ani/v.size() << " " << luni/v.size(); // Media ceruta a problemei
}

int main(){
	vector<Registru> v; // vectorul de persoane
	int frecventa[100]; // frecvanta anilor
	for(int i = 0; i < 100; i++)
		frecventa[i] = 0; // initializarea vectorului de frecventa cu 0
	int ani,luni; // anii si lunile persoanelor
	citire(v, frecventa);
	prelucrare(v, ani, luni); // apelurile functiilor
	afisare(v, frecventa, ani, luni);
	return 0;
}
