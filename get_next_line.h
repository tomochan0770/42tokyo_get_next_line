/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 02:18:20 by htomohit          #+#    #+#             */
/*   Updated: 2020/12/11 12:53:43 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "stdio.h"
# include "stdlib.h"
# include "limits.h"
# include "unistd.h"
# include "fcntl.h"

# define READ 1
# define READ_EOF 0
# define READ_ERROR -1

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, size_t idx, size_t len);
char	*ft_strdup(const char *s1);

#endif
