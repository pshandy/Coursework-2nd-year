
#include <iostream>
#include <fstream>
#include <string>

std::string	replace(std::string line, const std::string& str1, const std::string& str2)
{
	size_t start;
	size_t end;
	size_t str1_len;

	start = 0;
	str1_len = str1.size();
	while ((end = line.find(str1, start)) != std::string::npos)
	{
		line.erase(end, str1_len);
		line.insert(end, str2);
		start = end + 1;
	}
	return (line);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Неправильное количество аргументов!\n";
		return (1);
	}

	std::ifstream infile;
	infile.open(argv[1]);
	if (!infile.is_open())
	{
		std::cout << "Файл с исх. данными открыть не удалось!\n";
		return (1);
	}

	std::string buff;
	std::ofstream outfile;
	outfile.open(std::string(argv[1]).append(".replace"));
	while (std::getline(infile, buff))
		outfile << replace(buff, argv[2], argv[3]) << std::endl;
	outfile.close();
	infile.close();

}
