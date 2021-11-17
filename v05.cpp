#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>
#include <chrono>
#include <list>
#include <algorithm>
#include <functional>
#include <array>
#include <string_view>

struct duomenys {
	std::string Vard, Pav;
	std::vector<int> paz = { 0 };
	int egz;
	float GP = 0;
};

duomenys get(std::list<duomenys> _list, int _i) {
	std::list<duomenys>::iterator it = _list.begin();
	for (int i = 0; i < _i; i++) {
		++it;
	}
	return *it;
};

int generate_random()
{
	return rand() % 10 + 1;
};

void Rusiavimas(std::list<duomenys>& studentai, std::list<duomenys>& protingi, std::list<duomenys>& vargsiukai) {
	duomenys Eil;

	auto start = std::chrono::high_resolution_clock::now();

	for (duomenys Eil : studentai) {
		if (Eil.GP < 5) {
			vargsiukai.push_back(Eil);
		}
		else {
			protingi.push_back(Eil);
		}
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> diff = end - start;

	std::cout << "Failo rusiavimas su  i dvi grupes uztruko : " << diff.count() << " s\n";
}

void Nuskaitymas(std::list<duomenys>& studentai, int kiek)
{
	int student_counter = 0;
	std::ifstream fileRead;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::string buff;
	fileRead.open(pavadinimas);
	if (fileRead.is_open()) {
		getline(fileRead >> std::ws, buff);

		auto start = std::chrono::high_resolution_clock::now();

		while (student_counter < kiek)
		{
			duomenys duom;
			fileRead >> duom.Vard;
			fileRead >> duom.Pav;
			fileRead >> duom.GP;
			studentai.push_back(duom);
			student_counter++;
		}

		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> diff = end - start;
		std::cout << "Failo nuskaitymas uztruko: " << diff.count() << " s\n";
	}
};

float galutinis(std::vector<int> skaiciai, int pasirinkimas) {
	duomenys Eil;

	if (pasirinkimas == 1) {
		Eil.GP = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6 * generate_random();
		return Eil.GP;
	}
	else {
		float med = 0;
		typedef std::vector<duomenys>::size_type int_vecSize;
		int_vecSize int_size = skaiciai.size();
		std::sort(skaiciai.begin(), skaiciai.end());
		int_vecSize vidurys = int_size / 2;
		if (int_size % 2 != 0)
			med = skaiciai[vidurys];
		else
			med = (skaiciai[vidurys] + skaiciai[vidurys - 1]) / 2.0;
		Eil.GP = med * 0.4 + generate_random() * 0.6;
		return Eil.GP;
	}
}

std::vector<int> auto_marks(int how_many_marks){
	std::vector<int> skaiciai;
	for (int i = 0; i < how_many_marks; i++)
	{
		skaiciai.push_back(generate_random());
	}
	return skaiciai;
}

int generavimas(std::vector<int> pazymiai, int pasirinkimas)
{
	int kiek;
	std::cout << "iveskite studentu skaiciu: " << std::endl;
	std::cin >> kiek;
	std::string pavadinimas = "Studentai_" + std::to_string(kiek) + ".txt";
	std::ofstream out_data(pavadinimas);
	std::vector<int> skaiciai;
	duomenys Eil;
	out_data << std::setw(20) << std::left << "Vardas"
		<< std::setw(20) << std::left << "Pavarde"
		<< std::setw(20) << std::left << "Galutinis" << std::endl;
	for (int s = 1; s <= kiek; s = s + 1) {
		skaiciai = auto_marks(5);
		out_data << std::setw(20) << "Vardas" + std::to_string(s) <<
			std::setw(20) << "Pavarde" + std::to_string(s) <<
			std::setw(18) << galutinis(skaiciai, pasirinkimas) << std::endl;;
		skaiciai.clear();
	}
	return kiek;
}

int main(){

	int pasirinkimas;
	std::cout << "jei norite skaiciuoti pagal vidurki iveskite 1, jei pagal mediana-bet koki kita simboli: " << std::endl;
	std::cin >> pasirinkimas;

	std::vector<int> skaiciai;
	int kiek = generavimas(skaiciai, pasirinkimas);

	std::list<duomenys> studentai;
	std::list<duomenys> protingi;
	std::list<duomenys> vargsiukai;

	Nuskaitymas(studentai, kiek);
	Rusiavimas(studentai, protingi, vargsiukai);
}