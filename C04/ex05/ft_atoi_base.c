/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:33:54 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/28 14:41:10 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

int	ft_get_sign(char *str)
{
	int	sign;

	sign = 1;
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
	return (sign);
}

char	*ft_skip_characters(char *str)
{
	while (*str == ' ' || *str == '\f'
		|| *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '+' || *str == '-')
		str++;
	return (str);
}

int	ft_find_char_in_base(char ch, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ch == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	res;	
	int	count;
	int	i;

	res = 0;
	i = 0;
	while (base[i])
		i++;
	count = i;
	i = 0;
	if (ft_check_base(base) == 0)
		return (0);
	sign = ft_get_sign(str);
	str = ft_skip_characters(str);
	while (ft_find_char_in_base(str[i], base) != -1 && str[i])
	{
		res *= count;
		res += ft_find_char_in_base(str[i], base);
		i++;
	}
	res *= sign;
	return (res);
}
/*
void	test_1(void)
{
	char	*str = " ---+--+1234ab567";
	char	*base = "0123456789";

	printf("\nTEST 1\n"
		"String: %s \n"
		"Custom result: %d \n",
		str, ft_atoi_base(str, base));
}

void	test_2(void)
{
	char	*str = "-ab567";
	char	*base = "0ab3456789";

	printf("\nTEST 2\n"
		"String: %s \n"
		"Custom result: %d \n",
		str, ft_atoi_base(str, base));
}

int	main(void)
{
	test_1();
	test_2();
}*/
