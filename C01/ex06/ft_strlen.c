/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 10:49:53 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/22 10:57:47 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
/*
int	main(void)
{
	char	*str;
	int	length;

	str = "LOL";
	length = ft_strlen(str);
	printf("The number of characters is %d", length); //Outputs 3//
}*/
