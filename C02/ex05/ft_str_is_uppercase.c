/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:05:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/25 11:28:47 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] < 65 || str[i] > 90)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
/*
void	test_standard(void)
{
	char	str[] = "ABDCD";

	printf("%d \n", ft_str_is_uppercase(str));
}

void	test_error_1(void)
{
	char	str[] = "HfdaDfa";

	printf("%d \n", ft_str_is_uppercase(str));
}

int	main(void)
{
	test_standard();
	test_error_1();
}*/
