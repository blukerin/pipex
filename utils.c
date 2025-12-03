#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <pthread.h>
#include <limits.h>


void	exit_error(int n)
{
	if (n == 1)
		write (2, "Error: Invalid number of arguments\n", 36);
	if (n == 2)
		write (2, "Error: Invalid argument\n", 25);
	if (n == 3)
		write (2, "Error: Argument too big\n", 25);
	if (n == 4)
		write (2, "Error: Argument too little\n", 28);
	exit (1);
}
void	check_overflow(char *argv[])
{
	int		i;
	int		j;
	long	n;

	i = 0;
	n = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			n = (n * 10) + (argv[i][j] - 32);
			j++;
		}
		if (n > INT_MAX)
			exit_error(3);
		if (n < 1)
			exit_error(4);
		i++;
	}
	
}

void	are_numbers(char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] < '0' && argv[i][j] > '9')
				exit_error(2);
			j++;
		}
		i++;
	}
}



void	parse_args(int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		exit_error(1);
	are_numbers(argv);
	check_overflow(argv);
}


int	main(int argc, char *argv[])
{
	parse_args(argc, argv);
	return (0);
}
