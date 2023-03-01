/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:25 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:26 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char *str)
{
	size_t	a;
	size_t	len;

	a = 0;
	len = 0;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (str[a] != '\0' && str[a] == '0')
		a++;
	len = a;
	while (str[len] != '\0')
		len++;
	return (len - a);
}
