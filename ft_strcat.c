/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:18 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:19 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_strcat(int **old_mas, int *new_mas, size_t len_new, size_t len_old)
{
	size_t	i;
	size_t	j;
	int		*new_old_mas;

	i = 0;
	j = 0;
	new_old_mas = malloc(sizeof(int) * (len_old + len_new));
	if (new_old_mas == NULL)
		free_old_new(old_mas, new_mas);
	while (i < len_old)
	{
		new_old_mas[j] = (*old_mas)[i];
		i++;
		j++;
	}
	i = 0;
	while (i < len_new)
	{
		new_old_mas[j] = new_mas[i];
		i++;
		j++;
	}
	free(*old_mas);
	free(new_mas);
	return (new_old_mas);
}
