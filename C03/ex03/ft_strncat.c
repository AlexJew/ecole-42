/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:52:39 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 09:00:06 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (dest[i] != 0)
		i++;
	len = i;
	i = 0;
	while (src[i] != 0 && i < nb)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = 0;
	return (dest);
}
/*
void	test_1(void)
{
	char	src[] = "Hello";
	char	dest[] = "Goodbye";
	unsigned int	nb = 12;

	ft_strncat(dest, src, nb);
	printf("%s \n", dest);
}

void	test_2(void)
{
	char	src[] = "Hello";
	char	dest[] = "Goodbye";
	unsigned int	nb = 12;

	strncat(dest, src, nb);
	printf("%s \n", dest);
}

int	main(void)
{
	test_1();
	test_2();
}*/
