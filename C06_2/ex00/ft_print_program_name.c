/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:11:24 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/03 13:20:17 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	char	new_line;

	i = 0;
	new_line = '\n';
	argc = 0;
	while (argv[0][i] != 0)
	{
		write(1, &argv[0][i], 1);
		i++;
	}
	write(1, &new_line, 1);
}
