#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include <list>

struct studentas {
	std::string Vardas, Pavarde;
	std::vector<int> paz = { 0 };
	int egzaminas;
	float GP = 0;
};

studentas get(std::list<studentas> _list, int _i) {
	std::list<studentas>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
}

int generate_random(){
	return rand() % 10 + 1;
}

std::vector<int> auto_pazymiai(int how_many_marks){
	std::vector<int> skaiciai;
	for (int i = 0; i < how_many_marks; i++)	{
		skaiciai.push_back(generate_random());
	}
	return skaiciai;
}





void readFromFile(std::list<studentas>& Eil, int kiek){
	int student_counter = 0;
	std::ifstream fileRead;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::string buff;
	fileRead.open(pavadinimas);
	
}

int main(){  //atspausdina rezultatus
	std::vector<int> skaiciai;

	int kiek = generavimas(skaiciai);
	std::list<studentas> studentai;
	readFromFile(studentai, kiek);
	std::list<studentas> protingi;
	std::list<studentas> vargsiukai;
	int vargs = 0;
	int prot = 0;

}
