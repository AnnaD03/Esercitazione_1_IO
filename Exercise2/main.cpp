#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

double map_values(double &val)
{
	int a = 1;
	int b = 5;
	int c = -1;
	int d = 2;
	
	double new_value = c + (d - c) * (val - a) / (b - a);
	
	return new_value;
}

int main()
{
	const std::string ifilename = "data.txt"; 
	const std::string ofilename = "result.txt";
	
    std::ifstream ifs(ifilename); 
	std::ofstream ofs(ofilename);
	
    if (ifs.fail()) //controllo errori nell'apertura corretta del file data.txt
	{
        std::cerr << "Errore nell'apertura del file " << ifilename << std::endl; 
        return 1;
    }
	
	double value; //variabile ausiliaria in cui si memorizzano i valori nelle righe lette
	double sum = 0.0;
	double mean = 0.0;
	unsigned int index = 1;
	
	ofs << "# N Mean" << std::endl;

    while (ifs >> value) 
	{
		sum += map_values(value);
		mean = sum/index;
		ofs << index << " " << std::setprecision(16) << std::scientific << mean << std::endl;
		index++;
    }
	
	ifs.close();
	ofs.close();
	
    return 0;
}
