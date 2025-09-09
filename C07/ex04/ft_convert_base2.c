/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajewell <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 08:27:58 by ajewell           #+#    #+#             */
/*   Updated: 2025/09/05 08:30:38 by ajewell          ###   ####lausanne.ch   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_check_base(char *base);
char	*ft_skip_characters(char *nbr);
int		ft_get_sign(char*nbr);
int		ft_get_index(char ch, char *str);
int		ft_check_compatibility(char *nbr, char *base);
long	ft_get_number(char *nbr, char *base_from, int sign);
int		ft_get_size(long nbr, int len);
char	*put_number(long nbr, char *base_to, char *res);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) <= 1)
		return (0);
	i = 0;
	while (i < ft_strlen(base))
	{
		if (base[i] == '+'
			|| base[i] == '-'
			|| base[i] == ' '
			|| ('\t' <= base[i] && base[i] <= '\r'))
			return (0);
		j = i - 1;
		while (j >= 0)
		{
			if (base[i] == base[j])
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

int	ft_get_sign(char *nbr)
{
	int	sign;

	sign = 1;
	while (*nbr)
	{
		if (*nbr == ' '
			|| ('\t' <= *nbr && *nbr <= '\r'))
		{
			nbr++;
			continue ;
		}
		if (*nbr == '-')
			sign *= -1;
		else if (*nbr != '+')
			break ;
		nbr++;
	}
	return (sign);
}

char	*ft_skip_characters(char	*nbr)
{
	while (*nbr)
	{
		if (*nbr == ' '
			|| ('\t' <= *nbr && *nbr <= '\r'))
			nbr++;
		else if (*nbr == '-' || *nbr == '+')
			nbr++;
		else
			break ;
	}
	return (nbr);
}

int	ft_get_index(char ch, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ch)
			return (i);
		i++;
	}
	return (-1);
}
/*
void	test_check_base_1(void)
{
	char	*base = "1234 5678";

	printf("The result from checking the base '%s' is %d\n",
		   base, ft_check_base(base));
}

void	test_check_base_2(void)
{
	char	*base = "123456781";

	printf("The result from checking the base '%s' is %d\n",
		   base, ft_check_base(base));
}

void	test_check_base_3(void)
{
	char	*base = "12345678";

	printf("The result from checking the base '%s' is %d\n",
		   base, ft_check_base(base));
}

void	test_skip_characters_1(void)
{
	char	*str = "       ----++--67845";

	printf("The result from skipping the characters on '%s' is ", str);
	printf("'%s'\n", ft_skip_characters(str));
}

void	test_get_sign_1(void)
{
	char	*str = "----++--67845";

	printf("The result from getting sign on '%s' is %d\n",
	str, ft_get_sign(str));
}

void	test_get_index_1(void)
{
	char	ch = '5';
	char	*str = "0123456789";

	printf("The index '%c' in '%s' is %d\n",
		   ch, str, ft_get_index(ch, str));
}

void	test_get_index_2(void)
{
	char	ch = 'a';
	char	*str = "0123456789";

	printf("The index '%c' in '%s' is %d\n",
		   ch, str, ft_get_index(ch, str));
}

void	test_get_number_1(void)
{
	char	*nbr = "123456789101112131415";
	char	*base_from = "0123456789";
	int		sign = -1;

	printf("The conversion to int from '%s' with base '%s'
		   and sign '%d' is %ld\n",
		   nbr, base_from, sign, ft_get_number(nbr, base_from, sign));
}

void	test_get_number_2(void)
{
	char	*nbr = "abc";
	char	*base_from = "0abcd";
	int		sign = -1;

	printf("The conversion to int from '%s' with base '%s'
		   and sign '%d' is %ld\n",
		   nbr, base_from, sign, ft_get_number(nbr, base_from, sign));
}

void	test_get_size_1(void)
{
	int	nbr = 4;
	int	len = 2;

	printf("The number of characters required to write '%d'
		   with a base '%d' is '%d'\n",
		   nbr, len, ft_get_size(nbr, len));
}

void	test_get_size_2(void)
{
	int	nbr = 0;
	int	len = 2;

	printf("The number of characters required to write '%d'
		   with a base '%d' is '%d'\n",
		   nbr, len, ft_get_size(nbr, len));
}

void	test_put_number_1(void)
{
	int	nbr = -527;
	char	*base_to = "0123456789";
	char	res[5] = "";

	printf("The result from '%d' with base '%s' is '%s'\n",
		   nbr, base_to, put_number(nbr, base_to, res));
}

void	test_put_number_2(void)
{
	int		nbr = -527;
	char	*base_to = "abcdefghij";
	char	res[5] = "";

	printf("The result from '%d' with base '%s' is '%s'\n",
		   nbr, base_to, put_number(nbr, base_to, res));
}

void	test_convert_base_1(void)
{
	char *nbr = "-527";
	char *base_from = "0123456789";
	char *base_to = "abcdefghij";

	printf("The result from '%s' from base '%s' to base '%s' is '%s'\n",
		   nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));
}

void	test_convert_base_2(void)
{
	char *nbr = "527";
	char *base_from = "0123456789";
	char *base_to = "abcdefghij";

	printf("The result from '%s' from base '%s' to base '%s' is '%s'\n",
		   nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));
}

void	test_convert_base_3(void)
{
	char *nbr = "";
	char *base_from = "0123456789";
	char *base_to = "abcdefghij";

	printf("The result from '%s' from base '%s' to base '%s' is '%s'\n",
		   nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));
}

void	test_convert_base_4(void)
{
	char *nbr = "123456789101112131415";
	char *base_from = "0123456789";
	char *base_to = "abcdefghij";

	printf("The result from '%s' from base '%s' to base '%s' is '%s'\n",
		   nbr, base_from, base_to, ft_convert_base(nbr, base_from, base_to));
}

int	main(void)
{
	test_check_base_1();
	test_check_base_2();
	test_check_base_3();
	test_skip_characters_1();
	test_get_sign_1();
	test_get_index_1();
	test_get_index_2();
	test_get_number_1();
	test_get_number_2();
	test_get_size_1();
	test_get_size_2();
	test_put_number_1();
	test_put_number_2();
	test_convert_base_1();
	test_convert_base_2();
	test_convert_base_3();
	test_convert_base_4();
}*/