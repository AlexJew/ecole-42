/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:38:02 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/21 15:22:30 by ajewell          ###   ####lausanne.ch   */
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
/*
void	main(void)
{
	int	a;
	int	b;
	int*	pa;
	int*	pb;

	a = 0;
	b = 1;
	pa = &a;
	pb = &b;
	ft_swap(pa, pb);
	printf("Your value for a is %d \n", a); //expecting 1//
	printf("Your value for b is %d", b); //expecting 0//
}*/
