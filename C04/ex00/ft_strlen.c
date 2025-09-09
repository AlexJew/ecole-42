/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 09:50:28 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/27 10:05:33 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
void	test_1(void)
{
	char	*str = "Hello";

	printf("For string: %s, original result: %lu \n", str, strlen(str));
	printf("For string: %s, custom result: %d \n", str, ft_strlen(str));
}

void	test_2(void)
{
	char	*str = "";

	printf("For string: %s, original result: %lu \n", str, strlen(str));
	printf("For string: %s, custom result: %d \n", str, ft_strlen(str));
}

int	main(void)
{
	test_1();
	test_2();
}*/
