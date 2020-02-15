/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 18:07:40 by aamzouar          #+#    #+#             */
/*   Updated: 2019/11/22 14:20:30 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(char const *s1);
int		ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		get_next_line(int fd, char **line);

#endif
