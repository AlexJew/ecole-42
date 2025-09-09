/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 14:25:04 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/21 15:10:12 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
/*
int	main(void)
{
	int	nbr;
	int	*pnbr;
	char	ch1;
	char	ch2;

	nbr = 5;
	pnbr = &nbr;
	ft_ft(pnbr);
	ch1 = '0' + nbr / 10;
	ch2 = '0' + nbr % 10;
	write(1,&ch1,1); //should output 4//
	write(1,&ch2,1); //should output 2//
}*/
