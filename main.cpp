# include "TemperatureDatabase.h"
# include <iostream>

using std::cout, std::endl;

int main(int argc, char** argv) {
	/*
	if (argc < 3) {
		cout << "Usage: " << argv[0] << " data_file query_file" << endl;
		return 1;
	} else {
		TemperatureDatabase database;
		database.loadData(argv[1]);
		database.outputData(argv[1]); // comment out before submitting Part 2
		database.performQuery(argv[2]); // will be done in Part 2
	}
	*/
	LinkedList list;
	list.insert("4110488", 2015, 1, 0.54);
	list.insert("4110488", 2015, 2, 0.54);
	list.insert("4110488", 1980, 1, 0.54);
	list.insert("4110488", 2016, 1, 0.54);
	LinkedList copyList(list);
	std::cout << list;
	std::cout << copyList;
	/*
	TemperatureDatabase h;
	h.loadData("s050_TX-70s.dat");
	*/

}
