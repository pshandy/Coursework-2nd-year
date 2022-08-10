#include <string>
#include <iostream>

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "brain:   " << &brain << std::endl;
	std::cout << "brainPTR:" << stringPTR << std::endl;
	std::cout << "brainREF:" << &stringREF << std::endl;

	std::cout << "brain value:   " << brain << std::endl;
	std::cout << "brainPTR value:" << *stringPTR << std::endl;
	std::cout << "brainREF value:" << stringREF << std::endl;
}
