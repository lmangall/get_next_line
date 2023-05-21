/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:23:15 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/18 20:11:18 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	return (len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *stored_s, char *buff)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (!stored_s)
	{
		stored_s = (char *)malloc(sizeof(char));
		stored_s[0] = '\0';
	}
	if (!stored_s || !buff)
		return (0);
	str = malloc (sizeof(char) * ((ft_strlen(stored_s) + ft_strlen(buff)) + 1));
	if (!stored_s || str == NULL)
		return (0);
	i = -1;
	j = 0;
	if (stored_s)
		while (stored_s[++i] != '\0')
			str[i] = stored_s[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(stored_s) + ft_strlen(buff)] = '\0';
	free(stored_s);
	return (str);
}

char	*stored_s_to_str(char *stored_s)
{
	int		i;
	char	*str;

	i = 0;
	if (!stored_s[i])
		return (0);
	while (stored_s[i] && stored_s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (stored_s[i] && stored_s[i] != '\n')
	{
		str[i] = stored_s[i];
		i++;
	}
	if (stored_s[i] == '\n')
	{
		str[i] = stored_s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*new_stored_s(char	*stored_s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stored_s[i] && stored_s[i] != '\n')
		i++;
	if (!stored_s[i])
	{
		free(stored_s);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stored_s) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (stored_s[i])
		str[j++] = stored_s[i++];
	str[j] = '\0';
	free(stored_s);
	return (str);
}
