# include "TemperatureDatabase.h"
# include <fstream>
# include <iostream>

using std::cout, std::endl, std::string, std::ofstream;

TemperatureDatabase::TemperatureDatabase() {}
TemperatureDatabase::~TemperatureDatabase() {}

void TemperatureDatabase::loadData(const string& filename) {
	// TODO: implement this function
	std::ifstream myFile;
	std::stringstream ss;
	string h;
	myFile.open(filename);
	if (!myFile.is_open()){
		std::cout << "Error: Unable to open " << filename << std::endl;	
	}
	else {
		LinkedList myList;
		string location;
		int year;
		int month;
		double temperature;
		while (!myFile.eof()){
			getline(myFile,h);
			//std::cout << h << std::endl;
			ss.str(h);
			//std::cout << ss.str() << std::endl;
			ss >> location >> year >> month >> temperature;
			if (ss.fail()){
				if (ss.str().empty()){
					continue;
				}
				std::cout << "Error: Other invalid input" << std::endl;
				ss.clear();
				continue;
			}
			if (year > MAX_YEAR || year < MIN_YEAR){
				std::cout << "Error: Invalid year " << year << std::endl;
				ss.clear();
				continue;
			}
			if (month <= 0 || month > 12){
				std::cout << "Error: Invalid month " << month << std::endl;	
				ss.clear();
				continue;
			}
			if (temperature > 50.0 || temperature < -50.0){
				if (temperature == -99.99){
					continue;
					ss.clear();
				}
				std::cout << "Error: Invalid temperature " << temperature << std::endl;
				ss.clear();
				continue;
			}
			myList.insert(location, year, month, temperature);
			ss.clear();
		}
	}
	myFile.close();
}

void TemperatureDatabase::outputData(const string& filename) {
	ofstream dataout("sorted." + filename);
	
	if (!dataout.is_open()) {
		cout << "Error: Unable to open " << filename << endl;
		exit(1);
	}

	dataout << records.print();
}

void TemperatureDatabase::performQuery(const string& filename) {
	// TODO: implement this function
}
