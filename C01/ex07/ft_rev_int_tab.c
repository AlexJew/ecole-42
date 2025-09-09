/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:01:54 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/22 11:36:28 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	i_max;

	i = 0;
	i_max = size - 1;
	while (i <= i_max / 2)
	{
		ft_swap(&tab[i], &tab[i_max - i]);
		i++;
	}
}
/*
int	main(void)
{
	int	arr[4] = { 1, 2, 3, 4};
	int	size;
	int	i;

	size = 4;
	i = 0;
	ft_rev_int_tab(arr, size);
	while (i < size)
	{
		printf("%d",arr[i++]);
	}
}*/
