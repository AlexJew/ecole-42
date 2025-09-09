/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:33:53 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/20 14:23:15 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_digits(int n1, int n2, int n3)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	write(1, &n1, 1);
	write(1, &n2, 1);
	write(1, &n3, 1);
	if (n1 != 55 || n2 != 56 || n3 != 57)
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	ft_print_comb(void)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = 48;
	while (n1 <= 57)
	{
		n2 = n1 + 1;
		while (n2 <= 57)
		{
			n3 = n2 + 1;
			while (n3 <= 57)
			{
				print_digits(n1, n2, n3);
				n3++;
			}
			n2++;
		}
		n1++;
	}
}
/*
int	main(void)
{
	ft_print_comb();
}*/
