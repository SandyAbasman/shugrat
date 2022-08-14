/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamatku <smamatku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:44:37 by smamatku          #+#    #+#             */
/*   Updated: 2022/08/14 20:31:41 by smamatku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_read(int fd, char *buf, int *loc);
char	*create_result(char *buf, int loc);
char	*fill_buf(char *buf, int loc);
int		ft_strlen(char *s);
int		ft_strchr(char *str, int *i, int *give_loc);
char	*ft_strjoin(char *s1, char *s2);

#endif