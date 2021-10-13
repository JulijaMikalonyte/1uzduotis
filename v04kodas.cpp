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



