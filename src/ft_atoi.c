/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alcristi <alcristi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 16:53:49 by alcristi          #+#    #+#             */
/*   Updated: 2021/08/21 23:14:35 by alcristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_overflow(int num, int c_minus)
{
	unsigned int	nb;

	nb = num;
	if (nb > 2147483648 && c_minus)
		return (0);
	if (nb > 2147483647 && !c_minus)
		return (-1);
	return (1);
}

static size_t	ft_skipSpace(const char *nptr)
{
	size_t	i;

	i = 0;
	while (nptr[i] == '\n' || nptr[i] == '\f' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == ' ')
		i++;
	return (i);
}

static int	ft_isnegative(const char *nptr, size_t n)
{
	if (!ft_isdigit(nptr[n + 1]))
		return (-1);
	if (nptr[n] == '-')
		return (1);
	else if (nptr[n] == '+')
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *nptr)
{
	size_t	skipSpace;
	int		negative;
	int		total;
	int		ret;

	negative = 0;
	total = 0;
	skipSpace = ft_skipSpace(nptr);
	if (ft_strlen(nptr) == 0)
		return (0);
	if (! ft_isdigit(nptr[skipSpace]))
		negative = ft_isnegative(nptr, skipSpace++);
	if (negative == -1)
		return (0);
	while (nptr[skipSpace] && ft_isdigit(nptr[skipSpace]))
		total = (total * 10) + (nptr[skipSpace++] - 48);
	ret = ft_check_overflow(total, negative);
	if (ret != 1)
		return (ret);
	if (negative == 1)
		total *= -1;
	return (total);
}
