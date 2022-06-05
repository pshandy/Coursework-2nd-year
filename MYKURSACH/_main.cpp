#include "Program.hpp"
#include "Company.hpp"

Company *comp = new Company();

int getNumber() {
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n') || number < 0)
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите: ";
	}
	return (number);
}

int getMode() {
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n') || (number != 0 && number != 1))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "Ошибка ввода. Повторите: ";
	}
	return (number);
}

void Add()
{
	int number;
	int mode = 0;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	if (mode == FORWARD && !comp->addStation(number))
	{
		std::cout << "Добавление не успешно!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_addStation(number))
	{
		std::cout << "Добавление не успешно!\n";
		return ;
	}

	std::cout << "Добавление успешно!\n";
}

void AddQ()
{
	int number;
	int number1;
	int mode;
	std::string fuel;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	std::cout << "Введите номер бензоколонки: ";
	number1 = getNumber();

	std::cout << "Введите марку безина: ";
	std::cin.ignore(123456, '\n');
	std::getline(std::cin, fuel);
	//std::cin >> fuel;

	if (mode == FORWARD && !comp->addPump(number, number1, fuel))
	{
		std::cout << "Добавление не успешно!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_addPump(number, number1, fuel))
	{
		std::cout << "Добавление не успешно!\n";
		return ;
	}

	std::cout << "Добавление успешно!\n";
}
void Del()
{
	int number;
	int	mode;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	if (mode == FORWARD && !comp->delStation(number))
	{
		std::cout << "Удаление не успешно!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_delStation(number))
	{
		std::cout << "Удаление не успешно!\n";
		return ;
	}

	std::cout << "Удаление успешно!\n";
}

void DelQ()
{
	int number;
	int mode;

	std::cout << "Введите номер автозаправки, в которой требуется удалить бензоколонку: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	if (mode == FORWARD && !comp->delPump(number))
	{
		std::cout << "Удаление не успешно!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_delPump(number))
	{
		std::cout << "Удаление не успешно!\n";
		return ;
	}

	std::cout << "Удаление успешно!\n";
}

void Find()
{
	int number;
	int	mode;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	if (mode == FORWARD && !comp->isStationPresent(number))
	{
		std::cout << "Заправка не найдена!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_isStationPresent(number))
	{
		std::cout << "Заправка не найдена!\n";
		return ;
	}

	std::cout << "Заправка найдена!\n";
	comp->showStation(number);
}
void FindQ()
{
	int number;
	int mode;
	int	number1;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getMode();

	std::cout << "Введите номер бензоколонки: ";
	number1 = getNumber();

	if (mode == FORWARD && !comp->isPumpInStationPresent(number, number1))
	{
		std::cout << "Бензоколонка не найдена!\n";
		return ;
	}

	else if (mode == BACKWARD && !comp->_isPumpInStationPresent(number, number1))
	{
		std::cout << "Бензоколонка не найдена!\n";
		return ;
	}

	std::cout << "Бензоколонка найдена!\n";
	comp->showPump(number, number1);

}

bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it))
    	++it;
    return !s.empty() && it == s.end();
}

bool loadFile(Company *company)
{
	std::ifstream infile;
	infile.open(FILE_PATH);
	if (!infile.is_open())
	{
		std::cout << "Ошибка при открытии файла.\n";
		return (false);
	}

	int currentLine = 0;
	std::string line;
	while (getline(infile, line))
	{
		if (currentLine == 0)
			company->setName(line);
		else
		{
			int currentParam = 0;
			std::istringstream stream(line);
			std::string argument;

			std::string stationNumber;
			std::string pumpNumber;
			std::string pumpBrand;

			while (getline(stream, argument, ';'))
			{
				if (currentParam == 0)
				{
					if (!is_number(argument))
					{
						std::cout << "Аргумент должен быть числом (строка "
								<< currentLine << " аргумент " << currentParam << ")" << std::endl;
						return (false);
					}
					stationNumber = argument;
				}
				else if (currentParam == 1)
				{
					if (!is_number(argument))
					{
						std::cout << "Аргумент должен быть числом (строка "
								<< currentLine << " аргумент " << currentParam << ")" << std::endl;
						return (false);
					}

					pumpNumber = argument;
				}
				else if (currentParam == 2)
					pumpBrand = argument;
				currentParam++;
			}

			if (!(currentParam == 1 || currentParam == 3))
			{
				std::cout << "Неправильное количество аргументов на строке " << currentLine
						<< " в аргументе №: " << currentParam << std::endl;
				return (false);
			}

			if (currentParam == 1)
				company->addStation(std::stoi(stationNumber));

			else if (currentParam == 3)
			{
				company->addStation(std::stoi(stationNumber));
				company->addPump(std::stoi(stationNumber), std::stoi(pumpNumber), pumpBrand);
			}
		}
		currentLine++;
	}

	return (true);
}

bool exportFile(Company *company)
{
	std::ofstream outfile;

	outfile.open(FILE_PATH);
	if (!outfile.is_open())
	{
		std::cout << "Ошибка при открытии файла.\n";
		return (false);
	}
	outfile << "\xEF\xBB\xBF";
	outfile << company->getName() << std::endl;
	company->writeToFile(outfile);
	std::cout << "Выгружено.\n";
	return (true);
}

void Show()
{
	{
		int mode;
		std::cout << "Проход по списку прямой(0)/обратный(1):";
		mode = getMode();
		system("clear");
		std::cout << "\n----------------------------------------------------\n";
		std::cout << "|        Бензиновая компания '" << comp->getName() << "'";
		std::cout << "\n----------------------------------------------------";
		std::cout << "\n|     Номер     |" << "         Номер           Марка          ";
		std::cout << "\n| автозаправки  |" << "      бензоколонки      бензина         \n";
		if (mode == FORWARD)
			comp->show();
		else if (mode == BACKWARD)
			comp->_show();
		std::cout << "----------------------------------------------------\n";
	}
}

void ShowMode(int mode)
{
	{
		system("clear");
		std::cout << "\n----------------------------------------------------\n";
		std::cout << "|        Бензиновая компания '" << comp->getName() << "'";
		std::cout << "\n----------------------------------------------------";
		std::cout << "\n|     Номер     |" << "         Номер           Марка          ";
		std::cout << "\n| автозаправки  |" << "      бензоколонки      бензина         \n";
		if (mode == FORWARD)
			comp->show();
		else if (mode == BACKWARD)
			comp->_show();
		std::cout << "----------------------------------------------------\n";
	}
}

int main() {
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);
	int n;
	int mode = FORWARD;
	while (true) {
		ShowMode(mode);
		std::cout << "\n Выберите действие:\n";
		std::cout << " 1. Добавить автозаправку\n";
		std::cout << " 2. Добавить бензоколонку\n";
		std::cout << " 3. Удалить автозаправку\n";
		std::cout << " 4. Удалить бензоколонку\n";
		std::cout << " 5. Найти автозаправку\n";
		std::cout << " 6. Найти бензоколонку\n";
		std::cout << " 7. Переименовать бензиновую компанию\n";
		std::cout << " 8. Удалить бензиновую компанию и создать пустую\n";
		std::cout << " 9. Загрузить бензиновую компанию из файла\n";
		std::cout << " 10. Выгрузить бензиновую компанию в файл\n";
		std::cout << " 11. Вывод в прямом направлении.\n";
		std::cout << " 12. Вывод в обратном направлении.\n";
		std::cout << " 0. Выход\n";
		n = getNumber();
		if (n == 1)
			Add();
		else if (n == 2)
			AddQ();
		else if (n == 3)
			Del();
		else if (n == 4)
			DelQ();
		else if (n == 5)
			Find();
		else if (n == 6)
			FindQ();
		else if (n == 7)
		{
			std::string newName;
			std::cout << "Введите название бензиновой компании: ";
			std::cin >> newName;
			comp->setName(newName);
		}
		else if (n == 8)
		{
			delete(comp);
			comp = new Company();
		}
		else if (n == 9)
		{
			delete(comp);
			comp = new Company();
			if (!loadFile(comp))
			{
				delete(comp);
				comp = new Company();
			}
		}
		else if (n == 10)
			exportFile(comp);
		else if (n == 11)
			mode = FORWARD;
		else if (n == 12)
			mode = BACKWARD;
		else if (n == 0)
		{
			delete(comp);
			break;
		}
		std::cin.ignore();
		std::cout << "Нажмите чтобы продолжить." << std::endl;
		std::cin.ignore();
	}
}

