/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:33:54 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 15:33:03 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	ft_atoi(char *str)
{
	int	sign;
	int	res;	

	sign = 1;
	res = 0;
	while (*str == ' ' || *str == '\f'
		|| *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		res *= 10;
		res += *str - '0';
		str++;
	}
	res *= sign;
	return (res);
}
/*
void	test_1(void)
{
	char	*str = " ---+--+1234ab567";

	printf("\nTEST 1\n"
		"String: %s \n"
		"Original result: %d \n"
		"Custom result: %d \n",
		str, atoi(str), ft_atoi(str));
}

void	test_2(void)
{
	char	*str = "-1234ab567";

	printf("\nTEST 2\n"
		"String: %s \n"
		"Original result: %d \n"
		"Custom result: %d \n",
		str, atoi(str), ft_atoi(str));
}

int	main(void)
{
	test_1();
	test_2();
}*/
