#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
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

float galutinis(std::vector<int> skaiciai) {
	studentas Eil;
	Eil.GP = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate_random();
	return Eil.GP;
}

int generavimas(std::vector<int> pazymiai){
	int kiek;
	std::cout << "iveskite studentu skaiciu: " << std::endl;
	std::cin >> kiek;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::ofstream out_data(pavadinimas);
	std::vector<int> skaiciai;
	studentas Eil;
	out_data << std::setw(20) << std::left << "Vardas"<< std::setw(20) <<std::left << "Pavarde"<< std::setw(20) << std::left << "Galutinis(vid.)" << std::endl;
	for (int s = 1; s <= kiek; s = s + 1)	{
		skaiciai = auto_pazymiai(5);
		out_data << std::setw(20) << "Vardas" + std::to_string(s) <<std::setw(20) << "Pavarde" + std::to_string(s) <<std::setw(18) << galutinis(skaiciai) << std::endl;;
		skaiciai.clear();
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
	for (int i = 0; i < kiek; i++){
		float paz = 5.00;
		if (get(studentai, i).GP < paz){
			vargsiukai.push_back(get(studentai, i));
			vargs++;
		}
	}

	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		int _gp = get(studentai, j).GP;
		if (get(studentai, j).GP >= paz){
			protingi.push_back(get(studentai, j));
			prot++;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << "Failo rusiavimas su " + std::to_string(kiek) + " studentais i dvi grupes uztruko : " << diff.count() << " s\n";
	std::string pav;

}
