#include "libft.h"

static int	ft_count_word(const char	*s, int	c)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && ft_isprint(s[i]))
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				k++;
				i++;
		}
		i++;
	}
	return (k);
}

static int	ft_wlen(const char	*s, char	c)
{
	int	b;

	b = 0;
	while(s[b] != c && s[b])
		b++;
	return (b);
}

static char	**ft_msplit(char const	*s, char	c, int	i, char	**a)
{
	size_t	j;

	j = 0;
	while (s[i])
	{
		a[j] = (char *)malloc((ft_wlen(s + i, c) + 1) * sizeof(char));
		if (!a[j])
		{
			while (*(a + j))
				free(a[j--]);
			free(a);
			return (NULL);
		}
		ft_bzero(a[j], ft_wlen(s + i, c) + 1);
		ft_strlcat(a[j], s + i, (size_t)ft_wlen(s + i, c) + 1);
		j++;
		i += ft_wlen(s + i, c);
		while (s[i] && s[i] == c && c != '\0')
			i++;
	}
	a[j] = (0);
	return (a);
}
char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;

	a = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!a)
		return (0);
	i = 0;
	while (s[i] && s[i] == c && c != '\0')
		i++;
	return (ft_msplit(s, c, i, a));
}
/*
#include <stdlib.h>
#include <unistd.h>

void	ft_print_result(char const *s)
{
	printf("%s\n", s);
}

int		main(int argc, const char *argv[])
{
	char	**tabstr;
	int		i;
	int		arg;

	alarm(5);
	if (argc == 1)
		return (0);
	i = 0;
	if ((arg = atoi(argv[1])) == 1)
	{
		if (!(tabstr = ft_split("          ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 2)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 3)
	{
		if (!(tabstr = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 4)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'i')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 5)
	{
		if (!(tabstr = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z')))
			ft_print_result("NULL");
		else
		{
			while (tabstr[i] != NULL)
			{
				ft_print_result(tabstr[i]);
				write(1, "\n", 1);
				i++;
			}
		}
	}
	else if (arg == 6)
	{
		if (!(tabstr = ft_split("", 'z')))
			ft_print_result("NULL");
		else
			if (!tabstr[0])
				ft_print_result("ok\n");
	}
	return (0);
}

*/