/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:12:09 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/20 13:30:07 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	ch;

	if (n < 0)
	{
		ch = 'N';
		write(1, &ch, 1);
	}
	if (n >= 0)
	{
		ch = 'P';
		write(1, &ch, 1);
	}
}
/*
int	main(void)
{
	ft_is_negative(-2);
	ft_is_negative(0);
	ft_is_negative(4);
}*/
