#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 3

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>	//
# include <fcntl.h>	//

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *s, char c);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s1);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *b, int c, size_t len);

#endif