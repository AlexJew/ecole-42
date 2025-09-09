/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:44:10 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/29 08:54:41 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index);
/*
int	main(void)
{
	int	index_1 = -5;
	int	index_2 = 0;
	int	index_3 = 1;
	int	index_4 = 2;
	int	index_5 = 3;
	int	index_6 = 4;
	int	index_7 = 5;
	int	index_8 = 6;

	printf("Index %d is %d\n", index_1, ft_fibonacci(index_1));
	printf("Index %d is %d\n", index_2, ft_fibonacci(index_2));
	printf("Index %d is %d\n", index_3, ft_fibonacci(index_3));
	printf("Index %d is %d\n", index_4, ft_fibonacci(index_4));
	printf("Index %d is %d\n", index_5, ft_fibonacci(index_5));
	printf("Index %d is %d\n", index_6, ft_fibonacci(index_6));
	printf("Index %d is %d\n", index_7, ft_fibonacci(index_7));
	printf("Index %d is %d\n", index_8, ft_fibonacci(index_8));
}*/

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	else
		return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
