/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 09:53:38 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 09:31:16 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <bsd/string.h>
#include <string.h>
#include <stdio.h>

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;
	unsigned int	len_dest;

	i = 0;
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dest);
	if (size <= len_dest)
		return (size + len_src);
	while ((len_dest + i < size - 1) && (src[i] != 0))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[size - 1] = 0;
	return (len_dest + len_src);
}
/*
void	test_1(void)
{
	char	*dest = "Hello and ";
	char	*src = "goodbye";
	char	dest_1[100];
	char	dest_2[100];
	int	size = 5;
	int	res_1;
	int	res_2;

	strcpy(dest_1, dest);
	strcpy(dest_2, dest);
	res_1 = strlcat(dest_1, src, size);
	res_2 = ft_strlcat(dest_2, src, size);
	printf("\nPARAMETERS\n"
		"Source parameter: %s \n" 
		"Destination parameter: %s \n"
		"Size parameter: %d \n"
		"\nORIGINAL FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n"
		"\nCUSTOM FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n",
		src, dest, size, dest_1, res_1, dest_2, res_2);
}

void	test_2(void)
{
	char	*dest = "Hello ";
	char	*src = "Hello";
	char	dest_1[100];
	char	dest_2[100];
	int	size = 12;
	int	res_1;
	int	res_2;

	strcpy(dest_1, dest);
	strcpy(dest_2, dest);
	res_1 = strlcat(dest_1, src, size);
	res_2 = ft_strlcat(dest_2, src, size);
	printf("\nPARAMETERS\n"
		"Source parameter: %s \n" 
		"Destination parameter: %s \n"
		"Size parameter: %d \n"
		"\nORIGINAL FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n"
		"\nCUSTOM FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n",
		src, dest, size, dest_1, res_1, dest_2, res_2);
}

void	test_3(void)
{
	char	*dest = "Hello ";
	char	*src = "";
	char	dest_1[100];
	char	dest_2[100];
	int	size = 12;
	int	res_1;
	int	res_2;

	strcpy(dest_1, dest);
	strcpy(dest_2, dest);
	res_1 = strlcat(dest_1, src, size);
	res_2 = ft_strlcat(dest_2, src, size);
	printf("\nPARAMETERS\n"
		"Source parameter: %s \n" 
		"Destination parameter: %s \n"
		"Size parameter: %d \n"
		"\nORIGINAL FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n"
		"\nCUSTOM FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n",
		src, dest, size, dest_1, res_1, dest_2, res_2);
}

void	test_4(void)
{
	char	*dest = "";
	char	*src = "";
	char	dest_1[100];
	char	dest_2[100];
	int	size = 12;
	int	res_1;
	int	res_2;

	strcpy(dest_1, dest);
	strcpy(dest_2, dest);
	res_1 = strlcat(dest_1, src, size);
	res_2 = ft_strlcat(dest_2, src, size);
	printf("\nPARAMETERS\n"
		"Source parameter: %s \n" 
		"Destination parameter: %s \n"
		"Size parameter: %d \n"
		"\nORIGINAL FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n"
		"\nCUSTOM FUNCTION\n"
		"Result string: %s \n"
		"Result number: %d \n",
		src, dest, size, dest_1, res_1, dest_2, res_2);
}

int	main(void)
{
	test_1();
	test_2();
	test_3();
	test_4();
}*/
