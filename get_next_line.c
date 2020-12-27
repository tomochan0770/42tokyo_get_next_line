/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 17:25:00 by htomohit          #+#    #+#             */
/*   Updated: 2020/12/11 12:53:11 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		return_free(char **s1, char **s2, int ret)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (ret);
}

int		save_fd(char **save, char **buf)
{
	char	*tmp;

	if (*save != NULL)
	{
		if (!(tmp = ft_strjoin(*save, *buf)))
			return (return_free(save, buf, READ_ERROR));
		free(*save);
		*save = tmp;
	}
	else if (!(*save = ft_strdup(*buf)))
		return (return_free(buf, NULL, READ_ERROR));
	return (1);
}

int		cut_save(char **save, char **line)
{
	char	*tmp;
	int		idx;

	idx = ft_strchr(*save, '\n');
	if (idx < 0)
	{
		if (!(*line = ft_strdup(*save)))
			return (return_free(save, NULL, READ_ERROR));
		return (return_free(save, NULL, READ_EOF));
	}
	if (!(*line = ft_substr(*save, 0, idx - 1)))
		return (return_free(save, NULL, READ_ERROR));
	if (!(tmp = ft_substr(*save, idx, ft_strlen(*save) - idx)))
		return (return_free(save, NULL, READ_ERROR));
	free(*save);
	*save = tmp;
	return (READ);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	ssize_t		ret;

	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (READ_ERROR);
	if (save != NULL && (ft_strchr(save, '\n') > 0))
		return (cut_save(&save, line));
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (READ_ERROR);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(save_fd(&save, &buf)))
			return (return_free(&save, NULL, READ_ERROR));
		if (ft_strchr(save, '\n') > 0)
			break ;
	}
	free(buf);
	if (ret < 0)
		return (return_free(NULL, NULL, READ_ERROR));
	return (cut_save(&save, line));
}
