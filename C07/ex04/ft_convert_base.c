/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:27:58 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/05 08:30:38 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
int		ft_check_base(char *base);
char	*ft_skip_characters(char *nbr);
int		ft_get_sign(char*nbr);
int		ft_get_index(char ch, char *str);
long	ft_get_number(char *nbr, char *base_from, int sign);
int		ft_get_size(long nbr, int len);
char	*put_number(long nbr, char *base_to, char *res);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_check_compatibility(char *nbr, char *base)
{
	nbr = ft_skip_characters(nbr);
	if (ft_strlen(nbr) == 0)
		return (0);
	while (*nbr)
	{
		if (ft_get_index(*nbr, base) == -1)
			return (0);
		nbr++;
	}
	return (1);
}

long	ft_get_number(char *nbr, char *base_from, int sign)
{
	int		len;
	long	res;

	len = ft_strlen(base_from);
	res = 0;
	while (*nbr)
	{
		res *= len;
		res += ft_get_index(*nbr, base_from);
		nbr++;
	}
	return (res * sign);
}

int	ft_get_size(long nbr, int len)
{
	int	i;

	i = 0;
	if (nbr == 0)
		i++;
	else if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr != 0)
	{
		nbr /= len;
		i++;
	}
	return (i + 1);
}

char	*put_number(long nbr, char *base_to, char *res)
{
	int		i;
	int		j;
	char	*store;

	i = 0;
	j = 0;
	store = malloc(20 * sizeof (char));
	if (nbr < 0)
	{
		res[0] = '-';
		nbr *= -1;
		i++;
	}
	if (nbr == 0)
		res[0] = base_to[0];
	while (nbr > 0)
	{
		store[j] = base_to[nbr % ft_strlen(base_to)];
		nbr /= ft_strlen(base_to);
		j++;
	}
	while (j-- > 0)
		res[i++] = store[j];
	res[i] = '\0';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	int		sign;
	char	*res;

	if (!(ft_check_base(base_from) && ft_check_base(base_to)))
		return (NULL);
	sign = ft_get_sign(nbr);
	nbr = ft_skip_characters(nbr);
	if (!(ft_check_compatibility(nbr, base_from)))
		return (NULL);
	num = ft_get_number(nbr, base_from, sign);
	if (!(-2147483648 <= num && num <= 2147483647))
		return (NULL);
	res = malloc(ft_get_size(num, ft_strlen(base_to)) * sizeof (char));
	if (res == NULL)
		return (NULL);
	*res = '\0';
	res = put_number(num, base_to, res);
	return (res);
}
