/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:54:41 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/04 15:20:22 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		*ft_range(int min, int max);
void	put_range(int *range);
void	test_1(void);
/*
int	main(void)
{
	test_1();
}

void	test_1(void)
{
	int	min = 5;
	int max = 12;

	printf("Min: %d, max: %d, result: ", min, max);
	put_range(ft_range(min, max));
	printf("\n");
}*/

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	i = 0;
	if (min >= max)
		return (NULL);
	range = malloc((max - min) * sizeof (int));
	while (min < max)
		range[i++] = min++;
	return (range);
}

void	put_range(int *range)
{
	int	i;

	i = 0;
	while (range[i])
		printf("%d, ", range[i++]);
}
