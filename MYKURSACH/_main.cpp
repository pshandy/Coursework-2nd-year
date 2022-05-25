#include "Program.hpp"
#include "Company.hpp"

Company *comp = new Company();

int getNumber() {
	int number;
	while (!(std::cin >> number) || (std::cin.peek() != '\n'))
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
	mode = getNumber();

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
	mode = getNumber();

	std::cout << "Введите номер бензоколонки: ";
	number1 = getNumber();

	std::cout << "Введите марку безина: ";
	std::cin >> fuel;

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
	mode = getNumber();

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
	mode = getNumber();

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
	mode = getNumber();

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
}
void FindQ()
{
	int number;
	int mode;
	int	number1;

	std::cout << "Введите номер автозаправки: ";
	number = getNumber();

	std::cout << "Проход по списку прямой(0)/обратный(1):";
	mode = getNumber();

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

}
void Show()
{
	{
		int mode;
		std::cout << "\nПроход по списку прямой(0)/обратный(1):";
		mode = getNumber();
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
	while (true) {
		Show();
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
//			delete(comp);
//			comp = new Company();
//			if (file.InputData(comp)) std::cout << "Загрузка успешна!";
//			else
//			{
//				std::cout << "Ошибка!";
//				delete(comp);
//				comp = new Company();
//			}
		}
		else if (n == 10)
		{
//			if (comp != NULL)
//			{
//				if (file.OutputData(comp))
//					std::cout << "Выгрузка успешна!";
//				else
//					std::cout << "Ошибка";
//			}
//			else
//				std::cout << "Ошибка!";
		}
		else if (n == 0)
		{
			delete(comp);
			break;
		}
	}
}

