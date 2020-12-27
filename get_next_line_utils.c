/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:23:44 by htomohit          #+#    #+#             */
/*   Updated: 2020/12/11 12:41:33 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

size_t		ft_strlen(const char *s)
{
	size_t len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int			ft_strchr(const char *s, char c)
{
	int		i;
	int		n;

	if (!s)
		return (-1);
	n = ft_strlen(s);
	i = 0;
	while (i < n)
	{
		if ((unsigned char)(s[i]) == (unsigned char)c)
			return ((i + 1));
		i++;
	}
	return (-1);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*dst;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

char		*ft_substr(char const *s, size_t idx, size_t len)
{
	char	*dest;
	size_t	i;

	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = s[idx + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*dest;

	if (!s1)
	{
		if (!(dest = malloc(sizeof(char) * 1)))
			return (NULL);
		dest[0] = '\0';
	}
	else
	{
		len = ft_strlen(s1);
		if (!(dest = malloc(sizeof(char) * (len + 1))))
			return (NULL);
		i = 0;
		while (s1[i])
		{
			dest[i] = s1[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
