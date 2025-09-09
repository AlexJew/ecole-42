/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 15:33:51 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/28 11:20:33 by ajewell          ###   ####lausanne.ch   */
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

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 0)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nb, char *base)
{
	long	count;
	long	nbr;

	count = ft_strlen(base);
	nbr = nb;
	if (ft_check_base(base) == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > count - 1)
	{
		ft_putnbr_base(nbr / count, base);
	}
	ft_putchar(base[nbr % count]);
}
/*
void	test_putnbr_base_1(void)
{
	int	nb = 5432;
	char	*base = "0123456789";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}	

void	test_putnbr_base_2(void)
{
	int	nb = 5432;
	char	*base = "abcdefghij";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}	

void	test_putnbr_base_3(void)
{
	int	nb = 5432;
	char	*base = "0123456789ABCDEF";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}

void	test_4(void)
{
	int	nb = INT_MIN;
	char	*base = "0123456789";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}

void	test_5(void)
{
	int	nb = INT_MAX;
	char	*base = "0123456789";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}

void	test_6(void)
{
	int	nb = 1000000000;
	char	*base = "0123456789";

	ft_putnbr_base(nb, base);
	ft_putchar('\n');
}

int	main(void)
{
	test_putnbr_base_1();
	test_putnbr_base_2();
	test_putnbr_base_3();
}*/
