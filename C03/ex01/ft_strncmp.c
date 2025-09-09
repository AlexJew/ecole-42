/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:17:52 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 08:37:08 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while (s1[i] != 0 && s2[i] != 0 && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}
/*
void	test_1(void)
{
	char	s1[] = "ABC";
	char	s2[] = "AB";
	unsigned int	n = 3;

	printf("Test result with n=%d: %d \n", n, ft_strncmp(s1, s2, n));
	printf("Original result with n=%d: %d \n", n, strncmp(s1, s2, n));
}

void	test_2(void)
{
	char	s1[]= "ABC";
	char	s2[] = "AB";
	unsigned int	n = 2;

	printf("Result with n=%d: %d \n", n, ft_strncmp(s1, s2, n));
	printf("Original result with n=%d: %d \n", n, strncmp(s1, s2, n));
}

void	test_3(void)
{
	char	s1[]= "ABC";
	char	s2[] = "";
	unsigned int	n = 2;

	printf("Result with n=%d: %d \n", n, ft_strncmp(s1, s2, n));
	printf("Original result with n=%d: %d \n", n, strncmp(s1, s2, n));
}

void	test_4(void)
{
	char	s1[]= "";
	char	s2[] = "AB";
	unsigned int	n = 2;

	printf("Result with n=%d: %d \n", n, ft_strncmp(s1, s2, n));
	printf("Original result with n=%d: %d \n", n, strncmp(s1, s2, n));
}

void	test_5(void)
{
	char	s1[] = "";
	char	s2[] = "AB";
	unsigned int	n = 3;

	printf("Test result with n=%d: %d \n", n, ft_strncmp(s1, s2, n));
	printf("Original result with n=%d: %d \n", n, strncmp(s1, s2, n));
}

int	main(void)
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
}*/
