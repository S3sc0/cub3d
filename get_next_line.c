/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 09:35:04 by aamzouar          #+#    #+#             */
/*   Updated: 2019/12/25 09:35:07 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_n(char *str)
{
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\n' && len != i)
		i++;
	if (len != i)
		return (i);
	return (-1);
}

void	ft_free(char **s)
{
	free(*s);
	*s = NULL;
}

int		fill_line(char ***line, char **str, int ret, char *buff)
{
	char	*tmp;
	int		str_len;

	str_len = ft_strlen(*str);
	if (ret <= 0 && check_n(*str) == -1)
	{
		**line = ft_substr(*str, 0, str_len);
		**str = '\0';
		ft_free(&buff);
		ft_free(str);
		return (ret);
	}
	tmp = *str;
	**line = ft_substr(*str, 0, ret);
	*str = ft_substr(*str, (ret + 1), str_len - ret);
	ft_free(&tmp);
	ft_free(&buff);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	char		*buff;
	char		*tmp;
	static char	*str[4864];

	if (!(buff = malloc(sizeof(char) * BUFFER_SIZE + 1)) &&
			fd < 0 && BUFFER_SIZE < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	*line = "";
	while (1)
	{
		if ((ret = check_n(str[fd])) != -1)
			return (fill_line(&line, &str[fd], ret, buff));
		else if (!(ret = read(fd, buff, BUFFER_SIZE)) || ret == -1)
			return (fill_line(&line, &str[fd], ret, buff));
		buff[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(str[fd], buff);
		ft_free(&tmp);
	}
	return (1);
}
