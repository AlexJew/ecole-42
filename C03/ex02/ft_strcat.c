/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 16:52:39 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 08:54:36 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	while (dest[i] != 0)
		i++;
	len = i;
	i = 0;
	while (src[i] != 0)
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

	ft_strcat(dest, src);
	printf("%s \n", dest);
}

void	test_2(void)
{
	char	src[] = "Hello";
	char	dest[] = "Goodbye";

	strcat(dest, src);
	printf("%s \n", dest);
}

int	main(void)
{
	test_1();
	test_2();
}*/
