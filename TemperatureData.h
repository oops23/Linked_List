# ifndef TEMPERATUREDATA
# define TEMPERATUREDATA

# include <string>
const int MAX_YEAR = 2023;
const int MIN_YEAR = 1800;

struct TemperatureData {
	public:
		// TODO: add member variables as needed
		std::string id;
		int year;
		int month;
		double temperature;
		TemperatureData();
		TemperatureData(std::string id, int year, int month, double temperature);
		virtual ~TemperatureData();
		bool operator<(const TemperatureData& b);
};

# endif
