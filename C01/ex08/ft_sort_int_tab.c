/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:37:37 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/22 12:05:57 by ajewell          ###   ####lausanne.ch   */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	i_temp;

	i = 0;
	while (i < size)
	{
		i_temp = i;
		while (i_temp > 0)
		{
			if (tab[i_temp] < tab[i_temp - 1])
			{
				ft_swap(&tab[i_temp], &tab[i_temp - 1]);
			}
			i_temp--;
		}
		i++;
	}
}
/*
int	main(void)
{
	int	arr[7] = { 1, 2, 3, 2, 4, 0, 2};
	int	size;
	int	i;

	size = 7;
	i = 0;
	ft_sort_int_tab(arr, size);
	while (i < size)
	{
		printf("%d",arr[i++]);
	}
}*/
