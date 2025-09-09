/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:51 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 17:35:16 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

void	ft_putchar(char ch)
{
	write(1, &ch, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	ft_putchar('0' + nb % 10);
}
/*
void	test_1(void)
{
	int	nb = 5432;

	ft_putnbr(nb);
	ft_putchar('\n');
}	

void	test_2(void)
{
	int	nb = 0;

	ft_putnbr(nb);
	ft_putchar('\n');
}	

void	test_3(void)
{
	int	nb = -5959;

	ft_putnbr(nb);
	ft_putchar('\n');
}

void	test_4(void)
{
	int	nb = INT_MIN;

	ft_putnbr(nb);
	ft_putchar('\n');
}

void	test_5(void)
{
	int	nb = INT_MAX;

	ft_putnbr(nb);
	ft_putchar('\n');
}

void	test_6(void)
{
	int	nb = 1000000000;

	ft_putnbr(nb);
	ft_putchar('\n');
}

int	main(void)
{
	test_1();
	test_2();
	test_3();
	test_4();
	test_5();
	test_6();
}*/
