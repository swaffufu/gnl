/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:40:38 by marvin            #+#    #+#             */
/*   Updated: 2025/06/13 14:40:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_line(int fd, char **stash)
{
	char	*buffer;
	ssize_t	bytes_read;

	bytes_read = 0;
	if (!*stash)
		*stash = ft_strdup("");
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(*stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		*stash = ft_join(*stash, buffer);
	}
	free(buffer);
	if (bytes_read == -1 || (**stash == '\0'))
	{
		free(*stash);
		*stash = NULL;
	}
	return (*stash);
}

char	*ft_line(char *buffer)
{
	char	*line;
	size_t	len;
	size_t	i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\n')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (i < len)
	{
		line[i] = buffer[i];
        i++;
	}
	line[len] = '\0';
	return (line);
}

char	*ft_renew_buffer(char *buffer)
{
	char	*new;
	size_t	len;

	if (!buffer)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] && buffer[len] == '\n')
		len++;
	new = ft_substr(buffer, len, ft_strlen(buffer) - len);
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!read_line(fd, &stash[fd]))
		return (NULL);
	line = ft_line(stash[fd]);
	if (!line)
		return (NULL);
	stash[fd] = ft_renew_buffer(stash[fd]);
	return (line);
}
