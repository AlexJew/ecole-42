/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:53:38 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 09:08:12 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (*to_find == 0)
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return (&str[i]);
			j++;
		}
		i++;
	}
	return (0);
}
/*
void	test_1(void)
{
	char	*str = "Hello and goodbye";
	char	*to_find = "good";

	printf("\nTEST 1\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

void	test_2(void)
{
	char	*str = "Hello and goodbye";
	char	*to_find = "o";

	printf("\nTEST 2\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

void	test_3(void)
{
	char	*str = "Hello and goodbye";
	char	*to_find = "";

	printf("\nTest 3\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

void	test_4(void)
{
	char	*str = "Hello and goodbye";
	char	*to_find = "ciao";

	printf("\nTest 4\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

void	test_5(void)
{
	char	*str = "";
	char	*to_find = "ciao";

	printf("\nTest 5\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

void	test_6(void)
{
	char	*str = "";
	char	*to_find = "";

	printf("\nTest 6\n"
		"String haystack: %s \n" 
		"Substring needle: %s \n"
		"Original result: %s \n"
		"Custom result: %s \n",
		str, to_find, strstr(str, to_find), ft_strstr(str, to_find));
}

int	main(void)
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
}*/
