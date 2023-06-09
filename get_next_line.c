/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmangall <lmangall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:23:21 by lmangall          #+#    #+#             */
/*   Updated: 2023/01/22 14:25:08 by lmangall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
// #include <stdio.h>
// #include <fcntl.h>

char	*read_to_stored_s(int fd, char *stored_s)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rd_bytes = 1;
	while (!ft_strchr(stored_s, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(buff);
			free(stored_s);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		stored_s = ft_strjoin(stored_s, buff);
	}
	free(buff);
	return (stored_s);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stored_s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	stored_s = read_to_stored_s(fd, stored_s);
	if (!stored_s)
		return (NULL);
	line = stored_s_to_str(stored_s);
	stored_s = new_stored_s(stored_s);
	return (line);
}
// int     main(void)
// {
//         char    *line;
//         int             i;
//         int             fd;

//         fd1 = open("file1.txt", O_RDONLY);
//         i = 1;
//                         printf("fd: %d \n", fd);
//         while (i < 7)
//         {
//                 line = get_next_line(fd);
//                 printf("line [%02d]: %s\n", i, line);

//                 free(line);
//                 i++;
//         }
//         close(fd);
//         return (0);
// }