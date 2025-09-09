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
#ifndef FT_BOOLEAN_H
# include <unistd.h>
# define FT_BOOLEAN_H

typedef int	t_bool;
# define TRUE 1
# define FALSE 0
# define EVEN(nbr) ((nbr%2) == 0)
# define EVEN_MSG "I have an even number of arguments"
# define ODD_MSG "I have an odd number of arguments"
# define SUCCESS 0

#endif
