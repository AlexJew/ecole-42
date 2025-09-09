/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:26:45 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/20 15:37:42 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_write_digits(int n)
{
	char	ch1;
	char	ch2;
	char	zero;
	int	quotient;
	int	remainder;

	zero = '0';
	if (n <= 9)
	{
		ch1 = '0';
		ch2 = '0' + n;
	}
	else
	{
		remainder = n % 10;
		quotient = (n - remainder) / 10;
		ch1 = '0' + quotient;
		ch2 = '0' + remainder;
	}
	write(1, &ch1, 1);
	write(1, &ch2, 1);
}

void	ft_print_combined_digits(int n1, int n2)
{
	char	comma;
	char	space;

	comma = ',';
	space = ' ';
	ft_write_digits(n1);
	write(1, &space, 1);
	ft_write_digits(n2);
	if (n1 != 98 || n2 != 99)
	{
		write(1, &comma, 1);
		write(1, &space, 1);
	}
}

void	ft_print_comb_2(void)
{
	int	n1;
	int	n2;

	n1 = 0;
	n2 = 1;
	while (n1 < 99)
	{
		n2 = n1 + 1;
		while (n2 < 100)
		{
			ft_print_combined_digits(n1, n2);
			n2++;
		}
		n1++;
	}
}
/*int main(void)
{
	ft_print_comb_2();
}*/
