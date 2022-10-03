#include <signal.h>
#include <unistd.h>
#include <stdlib.h>


char	*make_str(void)
{
	int	i;
	char	*bin;

	i = 0;
	bin = (char *)malloc(sizeof(char) * 9);
	while (i < 8)
	{
		bin[i] = '0';
		i++;
	}
	bin[8] = '\0';
	return (bin);
}


char *make_binary(char c)
{
	int	n;
	int	i;
	char	*bin;

	i = 7;

	n = c;
	bin = make_str();
	while (n)
	{
		bin[i] = n % 2 + '0';
		n /= 2;
		i--;
	}
	return (bin);
}

void	send_signal(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
	}
	free (str);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		int	pid;
		char	*message;

		pid = ft_atoi(argv[1]);
		message = argv[2];
		while (*message)
		{
			send_signal(make_binary(message), pid);

			message++;
		}



	}

	return (0);
}
