/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:41 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/04 18:52:34 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_ultimate_range(int **range, int min, int max);
void	put_ultimate_range(int **range);
//void	test_1(void);
/*
int	main(void)
{
	test_1();
}

void	test_1(void)
{
	int	min = 5;
	int max = 12;
	int	**range;

	range = malloc(sizeof(int**));
	if (!range)
		return ;
	ft_ultimate_range(range, min, max);
	printf("Min: %d, max: %d, result: ", min, max);
	put_ultimate_range(range);
	printf("\n");
}*/

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = malloc((max - min) * sizeof (int));
	if (!tab)
		return (-1);
	while (min < max)
	{
		tab[i++] = min++;
	}
	*range = tab;
	return (i);
}
/*
void	put_ultimate_range(int **range)
{
	int	i;

	i = 0;
	while (range[0][i])
		printf("%d, ", range[0][i++]);
}*/
