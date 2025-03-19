#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

double map_values(double val)
{
	int a = 1;
	int b = 5;
	int c = -1;
	int d = 2;
	
	double new_value = c + (d-c)*(val-a)/(b-a);
	
	return new_value;
}

int main()
{
	const std::string ifilename = "data.txt"; 
	const std::string ofilename = "results.txt";
	
    std::ifstream ifs(ifilename); 
	std::ofstream ofs(ofilename);
	
    if (ifs.fail()) {
        std::cerr << "Can't open the file " << ifilename << std::endl;
        return 1;
    }
	
	int index = 1;
	double value = 0;
	std::string line;
	
	ofs << "# N Mean\n";

    while (!ifs.eof()) {
		for(; std::getline(ifs, line); ) {
			value += map_values(std::stod(line)); //è sbgliato stod avendo usato getline-> da modificare con istream stream...
			double mean = value/index;
			ofs << index << " " << std::setprecision(16) << std::scientific << mean << "\n";
			index++;
		}
    }
	
	ifs.close();
	ofs.close();
	
	std::cout << "File " << ofilename << " created" << std::endl;
	
    return 0;
}
