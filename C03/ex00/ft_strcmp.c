/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:17:52 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 08:28:57 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
/*
void	test_1(void)
{
	char	s1[] = "ABC";
	char	s2[] = "ABC";

	printf("Original result: %d \n", strcmp(s1, s2));
	printf("Custom result: %d \n", ft_strcmp(s1, s2));
}

void	test_2(void)
{
	char	s1[]= "ABC";
	char	s2[] = "ABCD";

	printf("Original result: %d \n", strcmp(s1, s2));
	printf("Custom result: %d \n", ft_strcmp(s1, s2));
}

void	test_3(void)
{

	char	s1[]= "ABC";
	char	s2[] = "AB";

	printf("Original result: %d \n", strcmp(s1, s2));
	printf("Custom result: %d \n", ft_strcmp(s1, s2));
}

int	main(void)
{
	test_1();
	test_2();
	test_3();
}*/
