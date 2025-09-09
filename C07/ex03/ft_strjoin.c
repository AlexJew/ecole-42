/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:46:12 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/04 18:51:59 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);
/*
int main(void)
{
	char 	*strs[] = {NULL};
	char 	*sep = ",";
	int		size = 0;
	char	*result;

	result = ft_strjoin(size, strs, sep);
	printf("The result is %s", result);
	free(result);
}*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_strcat(char *src, char *dest)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
}

int	ft_compute_count(int size, char **strs, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (size <= 0)
		return (1);
	else
	{
		while (i < size)
			count += ft_strlen(strs[i++]);
		count += ft_strlen(sep) * (size - 1) + 1;
	}
	return (count);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		count;
	int		i;
	char	*result;

	count = ft_compute_count(size, strs, sep);
	result = malloc(count * sizeof (char));
	if (!result)
		return (0);
	i = 0;
	result[i] = '\0';
	if (size <= 0)
		return (result);
	while (i < size - 1)
	{
		ft_strcat(strs[i++], result);
		ft_strcat(sep, result);
	}
	ft_strcat(strs[i], result);
	result[count - 1] = '\0';
	return (result);
}
