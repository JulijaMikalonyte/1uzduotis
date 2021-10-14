#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>

struct studentas{
	std::string Vardas, Pavarde;
	std::vector<int> nd = { 0 };
	float egzaminas;
	float galutinis = 0;
};

int Random(){
	return rand() % 10 + 1;
}

std::vector<int> nd_generavimas (int nd_kiekis){
	std::vector<int> skaiciai;
	for (int i = 0; i < nd_kiekis; i++){
		skaiciai.push_back(Random());
	}
	return skaiciai;
}

float galutinio_skaiciavimas(std::vector<int> skaiciai){
	studentas grupe;
	grupe.galutinis = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * Random();
	return grupe.galutinis;
}

int generavimas(std::vector<int> pazymiai){
	int kiekis;
	std::cout << "įveskite kokį kiekį studentų norite sugeneruoti: " << std::endl;
	std::cin >> kiekis;
	std::string pavadinimas = "Studentai_" + std::to_string(kiekis) + ".txt";
	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	std::ofstream out_data(pavadinimas);
	std::vector<int> skaiciai;
	studentas grupe;
	out_data << std::setw(20) << std::left << "Vardas"<< std::setw(20) << std::left << "Pavarde"<< std::setw(20) << std::left << "Galutinis(vid.)\n";

	for (int s = 1; s <= kiekis; s = s + 1){
		skaiciai = nd_generavimas(5);
		out_data << std::setw(20) << "Vardas" + std::to_string(s) <<
			std::setw(20) << "Pavarde" + std::to_string(s) <<
			std::setw(18) << galutinio_skaiciavimas(skaiciai) << std::endl;;
		skaiciai.clear();
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout <<std::to_string(kiekis) + " studentų failo sukūrimas užtruko: " << diff.count() << " s\n";
	return kiekis;
}

void readFromFile(std::vector<studentas>& grupe, int kiekis){
	int studento_nr = 0;
	std::ifstream fileRead;
	std::string pavadinimas = "Studentai_" + std::to_string(kiekis) + ".txt";
	std::string buff;
	fileRead.open(pavadinimas);

	if (fileRead.is_open()) {
		auto start = std::chrono::high_resolution_clock::now();
		auto st = start;
		getline(fileRead >> std::ws, buff);

		while (studento_nr < kiekis){
			grupe.resize(grupe.size() + 1);
			fileRead >> grupe.at(studento_nr).Vardas;
			fileRead >> grupe.at(studento_nr).Pavarde;
			fileRead >> grupe.at(studento_nr).galutinis;
			studento_nr++;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout <<" studentų failo nuskaitymas užtruko: " << diff.count() << " s\n";
	}
}

int main(){  //atspausdina rezultatus
	std::vector<int> skaiciai;

	int kiek = generavimas(skaiciai);
	std::vector<studentas> studentai;
	readFromFile(studentai, kiek);
	std::vector<studentas> protingi;
	std::vector<studentas> vargsiukai;
	int vargs = 0;
	int prot = 0;

	auto start = std::chrono::high_resolution_clock::now();
	auto st = start;
	for (int i = 0; i < kiek; i++) {
		float pazymys = 5.00;
		if (studentai.at(i).galutinis < pazymys) {
			vargsiukai.push_back(studentai.at(i));
			vargs++;
		}
	}

	for (int j = 0; j < kiek; j++) {
		float pazymys = 5.00;
		if (studentai.at(j).galutinis >= pazymys) {
			protingi.push_back(studentai.at(j));
			prot++;
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;
	std::cout << std::to_string(kiek)+ " studentų išrūšiavimas į dvi grupes užtruko : " << diff.count() << " s\n";

	std::string pavadinimas;
	pavadinimas = "vargsiukai_" + std::to_string(kiek) + ".txt";
	std::ofstream vargs_failas(pavadinimas);
	auto start1 = std::chrono::high_resolution_clock::now();
	auto st1 = start1;
	for (int i = 0; i < kiek; i++) {
		float pazymys = 5.00;
		if (studentai.at(i).galutinis < pazymys) {
			vargs_failas << studentai.at(i).Vardas << std::setw(20) << studentai.at(i).Pavarde << std::setw(18) << studentai.at(i).galutinis << std::endl;
		}
	}

	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff1 = end1 - start1;
	std::cout <<std::to_string(kiek) + " studentų failo išvedimas į vargšiukų failą užtruko : " << diff1.count() << " s\n";

	pavadinimas = "protingi_" + std::to_string(kiek) + ".txt";
	std::ofstream prot_failas(pavadinimas);
	auto start2= std::chrono::high_resolution_clock::now();
	auto st2 = start2;
	for (int j = 0; j < kiek; j++) {
		float paz = 5.00;
		if (studentai.at(j).galutinis >= paz) {
			prot_failas << studentai.at(j).Vardas << std::setw(20) << studentai.at(j).Pavarde << std::setw(18) << studentai.at(j).galutinis << std::endl;
		}
	}
  
	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff2 = end2 - start2;
	std::cout <<std::to_string(kiek) + " studentų failo išvedimas į protingų failą užtruko : " << diff2.count() << " s\n";
}