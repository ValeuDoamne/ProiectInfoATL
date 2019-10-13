/*
	Proiect: Registru Discoteca implementare orientata pe obiecte C++
	Autor: Alexa Constantin-Cosmin

	Aceasta versiune nu necesita numarul de n persoane la inceputul fisierului

	Se compileaza folosind comanda: g++ main.cpp Registru.cpp
*/

#include "Registru.h"

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
	fout << "Media de varsta este " << ani/v.size() << " " << luni/v.size() << endl; // Media ceruta a problemei
}

int main(){
	vector<Registru> v; // vectorul de persoane
	int frecventa[100] = { 0 }; // frecvanta anilor
	int ani,luni; // anii si lunile persoanelor
	citire(v, frecventa);
	prelucrare(v, ani, luni); // apelurile functiilor
	afisare(v, frecventa, ani, luni);
	return 0;
}
