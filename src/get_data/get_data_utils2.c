/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdiaz-fl <cdiaz-fl@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:08:30 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 14:07:18 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	is_float(char *s, int *i, int j, int nb)
{
	int	sign_dot[2];

	sign_dot[0] = 0;
	sign_dot[1] = 0;
	while (s[++j])
	{
		if (s[j] && (s[j] == '+' || s[j] == '-'))
			sign_dot[0]++;
		if (s[j] >= '0' && s[j] <= '9')
		{
			while (s[j] && s[j] >= '0' && s[j] <= '9' && ++nb)
				j++;
			if (s[j] && s[j] == '.' && j++)
				sign_dot[1]++;
			while (s[j] && s[j] >= '0' && s[j] <= '9' && ++nb)
				j++;
			break ;
		}
	}
	if (!nb || (nb == 1 && sign_dot[1]) || sign_dot[0] > 1)
		return (0);
	*i = j - 1;
	if (s[j] && s[j] == ',')
		*i = j;
	return (1);
}
