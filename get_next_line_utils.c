/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamatku <smamatku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:44:32 by smamatku          #+#    #+#             */
/*   Updated: 2022/05/22 11:44:44 by smamatku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(char *str, int *i, int *give_loc)
{
	while (*i < (ft_strlen(str)))
	{
		if (str[*i] == '\n')
		{
			*give_loc = *i;
			return (*i);
		}
		(*i)++;
	}
	*give_loc = -1;
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		li[3];
	char	*str;

	if (s2 == NULL || s2[0] == '\0')
		return (NULL);
	li[0] = ft_strlen(s1);
	li[1] = ft_strlen(s2);
	li[2] = 0;
	str = (char *)malloc(sizeof(char) * (li[0] + li[1] + 1));
	if (!str)
		return (NULL);
	while (li[2] < li[0] + li[1] + 1)
	{
		if (li[2] < li[0])
			str[li[2]] = s1[li[2]];
		if (li[2] >= li[0])
			str[li[2]] = s2[li[2] - li[0]];
		li[2]++;
	}
	str[li[0] + li[1]] = '\0';
	if (s1 != NULL)
		free(s1);
	s1 = NULL;
	return (str);
}
