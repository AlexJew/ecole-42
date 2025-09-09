/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:30:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/28 16:50:29 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power);
/*
int	main(void)
{
	printf("Power of -1 to 5 is %d\n", ft_iterative_power(-1, 5));
	printf("Power of 0 to 0 is %d\n", ft_iterative_power(0, 0));
	printf("Power of 0 to 5 is %d\n", ft_iterative_power(0, 5));
	printf("Power of 2 to 4 is %d\n", ft_iterative_power(2, 4));
	printf("Power of 4 to -3 is %d\n", ft_iterative_power(4, -3));
}*/

int	ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
