/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:16:37 by zcanales          #+#    #+#             */
/*   Updated: 2022/04/26 08:53:49 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math.h"
#include <stdio.h>

double	ft_atof(char *s, float base)
{
	double	sum;
	double	rest;
	double	neg;
	int		i;

	sum = 0.0;
	rest = 0.0;
	i = 0;
	neg = 1.0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+')
		i++;
	else if (s[i] == '-' && ++i)
		neg = -1.0;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
		sum = (sum * base) + (double)(s[i++] - '0');
	if (s[i] && s[i] == '.')
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		rest += (double)(s[i++] - '0') / base;
		base *= 10;
	}
	return ((sum + rest) * neg);
}
