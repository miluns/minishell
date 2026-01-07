#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_bzero(void *buffer, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchar(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*get_next_line(int fd);

#endif
