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



int generavimas(std::vector<int> pazymiai){
	int kiek;
	std::cout << "iveskite studentu skaiciu: " << std::endl;
	std::cin >> kiek;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::ofstream out_data(pavadinimas);
	std::vector<int> skaiciai;
	studentas Eil;
	
	}
	return kiek;
}

void readFromFile(std::list<studentas>& Eil, int kiek){
	int student_counter = 0;
	std::ifstream fileRead;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {
		auto start = std::chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> std::ws, buff);
		while (student_counter < kiek){
			studentas duom;
			fileRead >> duom.Vardas;
			fileRead >> duom.Pavarde;
			fileRead >> duom.GP;
			Eil.push_back(duom);
			student_counter++;
		}
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "Failo su " + std::to_string(kiek) + " studentu/-ais nuskaitymas uztruko: " << diff.count() << " s\n";
	}
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

	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	f

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Failo rusiavimas su " + std::to_string(kiek) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";
	std::string pav;

}
