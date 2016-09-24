/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:55:23 by adompe            #+#    #+#             */
/*   Updated: 2015/12/16 11:11:32 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s1[j] != '\0')
		j++;
	while (i < (int)n)
	{
		s1[j + i] = s2[i];
		i++;
	}
	s1[i + j] = '\0';
	return (s1);
}
