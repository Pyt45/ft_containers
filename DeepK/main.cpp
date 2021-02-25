#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>
#include <fstream>

void	create(std::string path) 
{ 
    // file pointer 
    std::fstream fout; 
  
    // opens an existing csv file or creates a new file. 
    fout.open(path, std::ios::out | std::ios::app); 
	
    std::cout << "Enter the details of 5 students: roll name maths phy chem bio" << std::endl; 
  
    int i, roll, phy, chem, math, bio; 
    std::string name; 
  
    // Read the input 
    for (i = 0; i < 5; i++) { 
  
        std::cin >> roll 
            >> name 
            >> math 
            >> phy 
            >> chem 
            >> bio; 
  
        // Insert the data to file 
        fout << roll << ", "
             << name << ", "
             << math << ", "
             << phy << ", "
             << chem << ", "
             << bio 
             << "\n"; 
    } 
}

void read_record(std::string path)
{
	std::fstream fin;
	std::vector<std::string> row;
	std::string line, word, temp;
	int		rollnum, roll2, count = 0;

	fin.open(path, std::ios::in);
	if (fin.bad())
	{
		std::cout << "Can not open this file" << std::endl;
		return ;
	}
	std::cout << "Enter the rool number: ";
	std::cin >> rollnum;

	while (fin >> temp)
	{
		row.clear();

		std::getline(fin, line);
		std::stringstream s(line);

		while (std::getline(s, word, ','))
			row.push_back(word);
		if (rollnum < row.size())
		{
			count = 1;
			std::cout << "Details of Roll " << row[0] << " : \n";
			std::cout << "Name: " << row[1] << "\n"; 
            std::cout << "Maths: " << row[2] << "\n"; 
            std::cout << "Physics: " << row[3] << "\n"; 
            std::cout << "Chemistry: " << row[4] << "\n"; 
            std::cout << "Biology: " << row[5] << "\n";
			break ;
		}
	}
	if (count == 0)
		std::cout << "Record not found\n";
	return ;
}

int		main()
{
	// create("data.csv");
	read_record("data.csv");
	return 0;
}