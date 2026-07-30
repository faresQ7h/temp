#include "Harl.hpp"

static int	get_level(std::string level)
{
	std::string	levels[4];

	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]"
			<< std::endl;
		return (0);
	}
	switch (get_level(argv[1]))
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
	return (0);
}
