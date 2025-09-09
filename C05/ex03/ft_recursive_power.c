/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:30:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/28 16:51:37 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power);
/*
int	main(void)
{
	printf("Power of -1 to 5 is %d\n", ft_recursive_power(-1, 5));
	printf("Power of 0 to 0 is %d\n", ft_recursive_power(0, 0));
	printf("Power of 0 to 5 is %d\n", ft_recursive_power(0, 5));
	printf("Power of 2 to 4 is %d\n", ft_recursive_power(2, 4));
	printf("Power of 2 to -3 is %d\n", ft_recursive_power(2, -3));
}*/

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power == 1)
		return (nb);
	else
		nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
