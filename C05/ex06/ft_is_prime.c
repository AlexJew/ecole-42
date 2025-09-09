/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:21:50 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/29 09:32:24 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb);
/*
int	main(void)
{
	int	nb_1 = -5;
	int	nb_2 = 0;
	int	nb_3 = 1;
	int	nb_4 = 2;
	int	nb_5 = 3;
	int	nb_6 = 4;
	int	nb_7 = 7;
	int	nb_8 = 9;

	printf("%d is prime ? %d\n", nb_1, ft_is_prime(nb_1));
	printf("%d is prime ? %d\n", nb_2, ft_is_prime(nb_2));
	printf("%d is prime ? %d\n", nb_3, ft_is_prime(nb_3));
	printf("%d is prime ? %d\n", nb_4, ft_is_prime(nb_4));
	printf("%d is prime ? %d\n", nb_5, ft_is_prime(nb_5));
	printf("%d is prime ? %d\n", nb_6, ft_is_prime(nb_6));
	printf("%d is prime ? %d\n", nb_7, ft_is_prime(nb_7));
	printf("%d is prime ? %d\n", nb_8, ft_is_prime(nb_8));
}*/

int	ft_is_prime(int nb)
{
	int	i;
	int	div;

	i = 2;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i <= nb / 2)
	{
		div = nb / i;
		if (nb == div * i)
			return (0);
		i++;
	}
	return (1);
}
