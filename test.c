#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


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
int main()
{
    printf("%s\n", make_binary('D'));
    return (0);
}