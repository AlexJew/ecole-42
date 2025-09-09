/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:05:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/25 10:36:22 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] < 65) || (str[i] > 90 && str[i] < 97) || (str[i] > 122))
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
	char	str[] = "Hello";

	printf("%d \n", ft_str_is_alpha(str));
}

void	test_error_1(void)
{
	char	str[] = "He!!o";

	printf("%d \n", ft_str_is_alpha(str));
}

int	main(void)
{
	test_standard();
	test_error_1();
}*/
