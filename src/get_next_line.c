/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/27 15:19:11 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/25 07:36:24 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static int		stop_read(char *line_, char *buff, char **line)
{
	char	*n;

	n = ft_strchr(buff, '\n');
	*n = '\0';
	*line = ft_strjoin(line_, buff);
	free(line_);
	ft_memcpy(buff, n + 1, (long)BUFF_SIZE - (long)n + (long)buff);
	return (1);
}

void			get_return_state(int i, int ret, char **line, char *line_)
{
	if (i == 1 && ret != -1)
		*line = line_;
	else
		free(line_);
	return ;
}

int				get_next_line(const int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1] = {0};
	char			*line_;
	int				i;
	int				ret;
	char			*tmp;

	line_ = ft_memalloc(1);
	if (ft_strchr(buff, '\n'))
		return (stop_read(line_, buff, line));
	free(line_);
	line_ = ft_strdup(buff);
	i = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		i = 1;
		buff[ret] = '\0';
		if (ft_strchr(buff, '\n'))
			return (stop_read(line_, buff, line));
		tmp = line_;
		line_ = ft_strjoin(line_, buff);
		free(tmp);
	}
	get_return_state(i, ret, line, line_);
	return (ret == -1 ? -1 : i);
}
