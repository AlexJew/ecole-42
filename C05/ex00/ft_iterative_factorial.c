/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 15:30:18 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/28 16:12:14 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb);
/*
int	main(void)
{
	printf("Factorial of -1 is %d\n", ft_iterative_factorial(-1));
	printf("Factorial of 0 is %d\n", ft_iterative_factorial(0));
	printf("Factorial of 1 is %d\n", ft_iterative_factorial(1));
	printf("Factorial of 2 is %d\n", ft_iterative_factorial(2));
	printf("Factorial of 4 is %d\n", ft_iterative_factorial(4));
}*/

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = nb;
	while (i-- > 1)
		nb *= i;
	return (nb);
}
