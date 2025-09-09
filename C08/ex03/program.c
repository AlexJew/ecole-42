/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:46:43 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/07 14:46:53 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */
#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point -> x = 42;
	point -> y = 21;
}

int	main(void)
{
	t_point	point;

	set_point(&point);
	printf("Value of x: '%d' and of y: '%d'\n", point.x, point.y);
	return (0);
}
