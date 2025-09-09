/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:55:23 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/29 09:21:08 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb);
/*
int	main(void)
{
	int	nb_1 = -5;
	int	nb_2 = 0;
	int	nb_3 = 1;
	int	nb_4 = 2;
	int	nb_5 = 4;
	int	nb_6 = 25;

	printf("Square root of %d is %d\n", nb_1, ft_sqrt(nb_1));
	printf("Square root of %d is %d\n", nb_2, ft_sqrt(nb_2));
	printf("Square root of %d is %d\n", nb_3, ft_sqrt(nb_3));
	printf("Square root of %d is %d\n", nb_4, ft_sqrt(nb_4));
	printf("Square root of %d is %d\n", nb_5, ft_sqrt(nb_5));
	printf("Square root of %d is %d\n", nb_6, ft_sqrt(nb_6));
}*/

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
