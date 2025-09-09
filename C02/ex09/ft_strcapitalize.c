/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 12:13:01 by ajewell           #+#    #+#             */
/*   Updated: 2025/08/25 13:00:00 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_ch_is_alpha(char *ch)
{
	if ((*ch < 65) || (*ch > 90 && *ch < 97) || (*ch > 122))
		return (0);
	return (1);
}

int	ft_ch_is_num(char *ch)
{
	if ((*ch < 48) || (*ch > 57))
		return (0);
	return (1);
}

char	*ft_ch_lowcase(char *ch)
{
	if (*ch >= 'A' && *ch <= 'Z')
		*ch += 32;
	return (ch);
}

char	*ft_ch_upcase(char *ch)
{
	if (*ch >= 'a' && *ch <= 'z')
		*ch -= 32;
	return (ch);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (str[i] != 0)
	{
		if (w == 0 && (ft_ch_is_alpha(&str[i]) || ft_ch_is_num(&str[i])))
		{
			w = 1;
			ft_ch_upcase(&str[i]);
		}
		else if (w == 1 && (ft_ch_is_alpha(&str[i]) || ft_ch_is_num(&str[i])))
			ft_ch_lowcase(&str[i]);
		else
			w = 0;
		i++;
	}
	return (str);
}
/*
void	test_1(void)
{
	char	src[]= "hi, how are you? 42words forty-two; fifty+and+one";
//	char	src[] = "test test";

	ft_strcapitalize(src);
	printf("%s \n", src);
}

int	main(void)
{
	test_1();
}*/
