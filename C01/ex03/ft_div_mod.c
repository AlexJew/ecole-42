/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:44:33 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/21 15:03:00 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
/*
int main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;
	int	*pdiv;
	int	*pmod;
	char	ch_div;
	char	ch_mod;

	a = 37;
	b = 7;
	pdiv = &div;
	pmod = &mod;
	ft_div_mod(a, b, pdiv, pmod);
	ch_div = '0'+div;
	ch_mod = '0'+mod;
	write(1,&ch_div,1); //expecting 5//
	write(1,&ch_mod,1); //expecting 2//
}*/
