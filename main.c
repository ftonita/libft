#include <stdio.h>
#include "libft.h"

int	main(void)
{
	printf("\tLib_1\n");
	printf("ft_isalpha %d \n", ft_isalpha('1'));
	printf("ft_isdigit %d \n", ft_isdigit('1'));
	printf("ft_isalnum %d \n", ft_isalnum('1'));
	printf("ft_isascii %d \n", ft_isascii('1'));
	printf("ft_isprint %d \n", ft_isprint('1'));
	printf("\tLib_2\n");
	char *p;
	p = ft_strchr ("this is a test", ' ');
	printf("%s", p);
	return 0;
}