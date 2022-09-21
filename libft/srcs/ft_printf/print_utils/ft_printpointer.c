/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:30:50 by hugrene           #+#    #+#             */
/*   Updated: 2022/09/08 17:30:52 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += print_long_as_hex(addr / 16);
		total += print_long_as_hex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87);
		write(1, &c, 1);
		total++;
	}
	return (total);
}

static int	get_hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += get_hex_size(addr / 16);
		total += get_hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

int	pf_printpointer(void *ptr, t_opt opt)
{
	long	addr;
	int		total;
	int		len;

	addr = (long unsigned)ptr;
	total = 0;
	len = get_hex_size(addr) + 2;
	while (len + total < opt.min_width)
		total += print_char(' ');
	total += print_str("0x");
	total += print_long_as_hex(addr);
	while (total < opt.offset)
		total += print_char(' ');
	return (total);
}
