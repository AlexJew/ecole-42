/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:05:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/25 10:55:51 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] < 48) || (str[i] > 57))
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
	char	str[] = "454590";

	printf("%d \n", ft_str_is_numeric(str));
}

void	test_error_1(void)
{
	char	str[] = "454$898";

	printf("%d \n", ft_str_is_numeric(str));
}

int	main(void)
{
	test_standard();
	test_error_1();
}*/
