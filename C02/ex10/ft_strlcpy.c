/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:09:54 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/26 09:01:21 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "new_string.h"
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (ft_strlen(src));
}

void	test_custom(void)
{
	char	dest[]="Goodbye world!";
	char	*src;
	unsigned int	n;
	unsigned int	res;

	src = "Hello";
	n = 8;

	res = ft_strlcpy(dest, src, n);
	printf("Example with n=%d: %d (src: %s and dest: %s) \n", n, res, src, dest);
}

void	test_original(void)
{
	char    dest[]="Goodbye world!";
	char    *src;   
 	unsigned int    n;
	unsigned int	res; 

 	src = "Hello";
 	n = 8;

	res = strlcpy(dest, src, n);
	printf("Example with n=%d: %d (src: %s and dest: %s) \n", n, res, src, dest);
}

int	main(void)
{
	test_custom();
	test_original();
}
