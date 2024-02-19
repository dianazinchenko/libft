/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dzinchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:21:44 by dzinchen          #+#    #+#             */
/*   Updated: 2023/10/10 11:45:22 by dzinchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (2);
	if (n > 0)
		digits++;
	else
		digits += 2;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	int		digits;
	char	*array;

	digits = get_digits(n);
	array = malloc(digits);
	if (!array)
		return (NULL);
	if (n == 0)
		array[0] = '0';
	else if (n < 0)
		array[0] = '-';
	array[digits - 1] = '\0';
	while (n != 0)
	{
		if (n < 0)
			array[digits - 2] = n % 10 * (-1) + '0';
		else
			array[digits - 2] = n % 10 + '0';
		n /= 10;
		digits--;
	}
	return (array);
}
