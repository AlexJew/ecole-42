/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:23:25 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/21 15:39:34 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	rem;

	div = *a / *b;
	rem = *a % *b;
	*a = div;
	*b = rem;
}
/*
int	main(void)
{
	int	a;
	int	b;
	int*	pa;
	int*	pb;

	a = 42;
	b = 5;
	pa = &a;
	pb = &b;
	ft_ultimate_div_mod(pa, pb);
	printf("The quotient is %d \n", a); //expecting 8// 
	printf("The remainder is %d", b); //expecting 2//
}*/
