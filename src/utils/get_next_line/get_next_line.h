/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsagong <dsagong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 08:37:31 by dsagong           #+#    #+#             */
/*   Updated: 2025/11/14 16:42:00 by dsagong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnl_ft_strchr(const char *s, int c);
char	*gnl_ft_strjoin(char const *s1, char const *s2);
char	*gnl_ft_strdup(const char *s);
char	*make_line(char *rest);
char	*realloc_rest(char *rest);

#endif
