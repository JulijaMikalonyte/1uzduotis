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


float galutinio_skaiciavimas(std::vector<int> skaiciai){
	studentas grupe;
	grupe.galutinis = 0.4 * std::accumulate(skaiciai.begin(), skaiciai.end(), 0) / skaiciai.size() + 0.6;
	return grupe.galutinis;
}



int main(){  //atspausdina rezultatus
	std::vector<int> skaiciai;

	std::vector<studentas> studentai;
	std::vector<studentas> protingi;
	std::vector<studentas> vargsiukai;
	int vargs = 0;
	int prot = 0;

}