#include <stdio.h>
#include <stdlib.h>

int	is_charset(char ch, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (ch == charset[i++])
			return (1);
	}
	return (0);
}

char **make_array(char *str, char *charset)
{
	int		count;
	int		i;
	char	**array;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((i == 0 || is_charset(str[i - 1], charset)) && !is_charset(str[i], charset))
			count++;
		i++;
	}
	array = malloc((count + 1) * sizeof (char*));
	if (array == NULL)
		return NULL;
	array[count] = NULL;
	return (array);
}

int	count_string(char *str, char *charset, int index)
{
	int	count;

	count = 0;
	while(!is_charset(str[index], charset) && str[index])
	{
		count++;
		index++;
	}
	return (count);
}

char **ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		count;
	char	**array;

	array = make_array(str, charset);
	i = 0;
	j = 0;
	while (str[j])
	{
		k = 0;
		count = 0;
		if ((j == 0 || is_charset(str[j-1], charset)) && !is_charset(str[j], charset))
		{
			count = count_string(str, charset, j);
			array[i] = malloc((count + 1) * sizeof(char));
			while (k < count)
				array[i][k++] = str[j++];
			i++;
		}
		else
			j++;
	}
	return (array);
}
/*
void	test_1(void)
{
	char	*str = "ABC,!DEF???";
	char	*charset = ",!?";
	char	**array;

	array = ft_split(str, charset);
	printf("Initial string: '%s', initial charset: '%s'\n", str, charset);
	while (*array)
	{
		printf("- '%s'\n", *array);
		array++;
	}
	printf("\n");
}

void	test_2(void)
{
	char	*str = "ABC,!DEF??? ";
	char	*charset = ",!?";
	char	**array;

	array = ft_split(str, charset);
	printf("Initial string: '%s', initial charset: '%s'\n", str, charset);
	while (*array)
	{
		printf("- '%s'\n", *array);
		array++;
	}
	printf("\n");
}

int	main(void)
{
	test_1();
	test_2();
}*/