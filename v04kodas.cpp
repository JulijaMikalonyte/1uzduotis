#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <numeric>


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
	std::vector<int> skaiciai;
	studentas grupe;
}


int main(){  //atspausdina rezultatus
	std::vector<int> skaiciai;

	int kiek = generavimas(skaiciai);
	std::vector<studentas> studentai;
	std::vector<studentas> protingi;
	std::vector<studentas> vargsiukai;
	int vargs = 0;
	int prot = 0;

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

}