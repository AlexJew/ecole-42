/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:09:10 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/23 15:42:34 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != 0)
	{
		dest[i] = src [i];
		i ++;
	}
	dest[i] = 0;
	return (dest);
}
/*
int	main(void)
{
	char	src[] = "LOL";
	char	dest[4];

	ft_strcpy(dest, src);
	printf("%s", dest);
}*/
