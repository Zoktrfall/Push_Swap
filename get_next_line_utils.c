/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aafrikya <aafrikya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:55:26 by aafrikya          #+#    #+#             */
/*   Updated: 2023/03/01 15:55:27 by aafrikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	characters_ptr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
		{
			count++;
			break ;
		}
		count++;
	}
	return (count);
}

int	characters_str(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		if (str[count] == '\n')
		{
			count++;
			break ;
		}
		count++;
	}
	return (count);
}

char	*adds(char *ptr)
{
	int		i;
	char	*str;

	i = 0;
	str = malloc(sizeof(char) * ft_strlen(ptr) + 1);
	if (str == NULL)
		return (NULL);
	while (ptr[i] != '\0')
	{
		str[i] = ptr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_exlusive(char *str, char *ptr)
{
	int		i;
	int		j;
	char	*new_str;

	i = 0;
	j = 0;
	if (str == NULL && ft_strlen(ptr) > 0)
		return (adds(ptr));
	new_str = malloc(sizeof(char) * (ft_strlen(ptr) + ft_strlen(str) + 1));
	if (new_str == NULL)
		return (NULL);
	while (str[i] != '\0')
		new_str[j++] = str[i++];
	i = 0;
	while (ptr[i] != '\0')
		new_str[j++] = ptr[i++];
	new_str[j] = '\0';
	free(str);
	return (new_str);
}
