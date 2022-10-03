#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	from_binary(char *str)
{
	int		i;
	char	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		c = c * 2 + (str[i] - '0');
		i++;
	}
	return (c);
}

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

static char	*make_str(void)
{
	int	i;
	char	*bin;

	i = 0;
	bin = (char *)malloc(sizeof(char) * 9);
	while (i < 9)
	{
		bin[i] = '\0';
		i++;
	}
	return (bin);
}


void	signal_handler(int sig)
{
	char	*str;
	char	c;

	str = make_str();
	if (sig == SIGUSR1)
		str[str_len(str)] = '0';
	else if (sig == SIGUSR2)
		str[str_len(str)] = '1';
	if (str_len(str) == 8)
	{
		c = from_binary(str);
		write (1, &c, 1);
	}
}

int	main()
{
	signal(SIGUSR1, signal_handler());
	signal(SIGUSR2, signal_handler());
	printf("%c\n", from_binary("01000100"));
	return (0);
}