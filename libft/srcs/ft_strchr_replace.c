/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_replace.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnelson <dnelson@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/25 12:49:40 by dnelson           #+#    #+#             */
/*   Updated: 2017/07/25 12:50:56 by dnelson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strchr_replace(char *str, char c, size_t start, size_t end)
{
	while (start < end)
	{
		str[start] = c;
		++start;
	}
}
