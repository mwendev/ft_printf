/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwen <mwen@student.42wolfsburg.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:40:28 by mwen              #+#    #+#             */
/*   Updated: 2021/06/20 16:15:02 by mwen             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putcharint(char *nb, long long cp_nb, t_flags flags)
{
	int	ret;

	ret = 0;
	if (cp_nb < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		ret += ft_treat_width(flags.dot, ft_strlen(nb), 1);
	ret += ft_putstrprec(nb, ft_strlen(nb));
	return (ret);
}

static int	ft_treat_charint(char *nb, long long cp_nb, t_flags flags)
{
	int	ret;

	ret = 0;
	if (flags.minus == 1)
	{
		ret += ft_putcharint(nb, cp_nb, flags);
		if ((size_t)flags.width > ft_strlen(nb))
			flags.zero = 0;
	}
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(nb))
		flags.dot = ft_strlen(nb);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		ret += ft_treat_width(flags.width, 0, 0);
	}
	else
		ret += ft_treat_width(flags.width, ft_strlen(nb), flags.zero);
	if (flags.minus == 0)
		ret += ft_putcharint(nb, cp_nb, flags);
	return (ret);
}

int	ft_treat_int(long long nb, t_flags flags)
{
	char		*nb_in_char;
	long long	cp_nb;
	int			ret;

	cp_nb = nb;
	ret = 0;
	if (flags.dot == 0 && nb == 0)
	{
		ret += ft_treat_width(flags.width, 0, 0);
		return (ret);
	}
	if (nb < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot < 0)
			ft_putchar('-');
		nb *= -1;
		flags.zero = 1;
		flags.width--;
		ret++;
	}
	nb_in_char = ft_itoa(nb);
	ret += ft_treat_charint(nb_in_char, cp_nb, flags);
	free(nb_in_char);
	return (ret);
}
