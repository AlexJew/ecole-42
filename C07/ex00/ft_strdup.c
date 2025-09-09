/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 13:11:44 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/04 14:53:55 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(char *src);
/*
int main(void )
{
	char	*str_1 = "Hello";
	char	*str_1_dup_ori;
	char	*str_1_dup_cust;
	

	str_1_dup_ori = strdup(str_1);
	str_1_dup_cust = ft_strdup(str_1);
	printf("Initial string: %s\n"
		   "Duplicated string (original): %s\n"
		   "Duplicated string (custom): %s\n", 
			str_1, str_1_dup_ori, str_1_dup_cust);

	free(str_1_dup_ori);
	free(str_1_dup_cust);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_strcpy(char *src, char *dst)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

char	*ft_strdup(char *src)
{
	char	*dst;

	dst = malloc(ft_strlen(src) * sizeof (char) + 1);
	if (!dst)
		return (NULL);
	ft_strcpy(src, dst);
	return (dst);
}
