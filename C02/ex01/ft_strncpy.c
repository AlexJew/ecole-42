/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 09:09:54 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/25 10:41:46 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != 0 && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
/*
void	test_custom(void)
{
	char	dest[]="Goodbye world!";
	char	*src;
	unsigned int	n;

	src = "Hello";
	n = 8;

	ft_strncpy(dest, src, n);
	printf("This is an example with n=%d: %s \n", n, dest);
}

void	test_original(void)
{
	char    dest[]="Goodbye world!";
	char    *src;   
 	unsigned int    n;
 
 	src = "Hello";
 	n = 8;

	strncpy(dest, src, n);
	printf("This is an example with n=%d: %s", n, dest);
}

int	main(void)
{
	test_custom();
	test_original();
}
*/
