/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamatku <smamatku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:44:34 by smamatku          #+#    #+#             */
/*   Updated: 2022/08/14 19:45:57 by smamatku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_buff(char *buf, int loc)
{
	char	*result;

	result = NULL;
	if (loc == -1)
		result = NULL;
	else
		result = ft_strjoin(NULL, &buf[loc + 1]);
	free(buf);
	buf = NULL;
	return (result);
}

char	*get_res(char *buf, int loc)
{
	char	c;
	char	*result;

	if (!buf)
		return (NULL);
	if (loc == -1)
	{
		result = ft_strjoin(NULL, buf);
		return (result);
	}
	c = buf[loc + 1];
	buf[loc + 1] = '\0';
	result = ft_strjoin(NULL, buf);
	buf[loc + 1] = c;
	return (result);
}

char	*ft_read(int fd, char *buf, int *loc)
{
	char	s[BUFFER_SIZE + 1];
	int		read_c;
	int		i;

	i = 0;
	read_c = 0;
	while (ft_strchr(buf, &i, loc) == -1)
	{
		read_c = read(fd, s, BUFFER_SIZE);
		if (read_c <= 0)
			break ;
		s[read_c] = '\0';
		buf = ft_strjoin(buf, s);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*result;
	int			loc;

	loc = 0;
	result = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = ft_read(fd, buf, &loc);
	if (buf == NULL)
		return (NULL);
	result = get_res(buf, loc);
	buf = create_buff(buf, loc);
	if (result[0] == '\0')
		result = NULL;
	return (result);
}
