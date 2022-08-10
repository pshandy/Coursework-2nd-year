#include "Zombie.hpp"

int main()
{
	Zombie	*Zptr;

	Zptr = newZombie("Dynamic");
	Zptr->announce();
	randomChump("Static");
	delete(Zptr);
}
