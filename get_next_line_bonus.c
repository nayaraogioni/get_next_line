/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:08:16 by nogioni-          #+#    #+#             */
/*   Updated: 2024/08/09 18:09:04 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_from_file(int fd, char *bucket_buffer)
{
	char		*cup_buffer;
	int			bytes_read;

	cup_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(bucket_buffer, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			free(bucket_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		if (!cup_buffer)
			return (NULL);
		bucket_buffer = ft_strjoin(bucket_buffer, cup_buffer);
	}
	free(cup_buffer);
	return (bucket_buffer);
}

static char	*extract_line(char *bucket_buffer)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!bucket_buffer[i])
		return (NULL);
	while (bucket_buffer[i] != '\0' && bucket_buffer[i] != '\n')
		i++;
	if (bucket_buffer[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = -1;
	while (bucket_buffer[++i] != '\0' && bucket_buffer[i] != '\n')
		line[j++] = bucket_buffer[i];
	if (bucket_buffer[i] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*obter_rest(char *bucket_buffer)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	j = 0;
	while (bucket_buffer[i] != '\0' && bucket_buffer[i] != '\n')
		i++;
	if (bucket_buffer[i] == '\0')
	{
		free(bucket_buffer);
		return (NULL);
	}
	rest = malloc(sizeof(char) * (ft_strlen(bucket_buffer) - i + 1));
	i++;
	while (bucket_buffer[i] != '\0')
	{
		rest[j] = bucket_buffer[i];
		j++;
		i++;
	}
	rest[j] = '\0';
	free(bucket_buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*bucket_buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bucket_buffer[fd] = read_from_file(fd, bucket_buffer[fd]);
	if (!bucket_buffer[fd])
		return (NULL);
	line = extract_line(bucket_buffer[fd]);
	bucket_buffer[fd] = obter_rest(bucket_buffer[fd]);
	return (line);
}

/* int main() {
    char *filename;
    char *line;
    int fd;
    filename = "test1.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
    filename = "test2.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    printf("\n");
    filename = "test3.txt";
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }
    printf("Reading from %s:\n", filename);
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
} */
