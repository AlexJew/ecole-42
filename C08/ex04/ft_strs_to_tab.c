/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:46:43 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/07 14:46:53 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_putnbr(int nbr)
{
	char	ch;

	if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ch = '0' + nbr % 10;
		write(1, &ch, 1);
	}
	else
	{
		ch = '0' + nbr;
		write(1, &ch, 1);
	}
}

char	*ft_strcopy(char *src, char *dst)
{
	int		i;

	i = -1;
	while (src[++i])
		src[i] = dst[i];
	dst[i] = 0;
	return (dst);
}

t_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	i = 0;
	tab = malloc(ac * sizeof (t_stock_str *));
	if (tab == NULL)
		return (NULL);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].copy = av[i];
		if (i == ac - 1)
			tab[i].str = "";
		else
			tab[i].str = av[i];
		i++;
	}
	return (tab);
}
