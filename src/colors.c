/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   colors.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/10/06 12:14:10 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/10/06 12:46:51 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../inc/fdf.h"

int		get_color(char *str)
{
	int	color;
	int i;

	i = 0;
	color = 0;
	while (str[i])
	{
		if (str[i] == ',')
		{
			while (str[++i] == '0' || str[i] == 'x')
				i++;
			while (str[i])
			{
				color += str[i]-48;
				if (str[i+1])
					color = color << 4;
				i++;
			}
			return (color);
		}
		i++;
	}
	return (color);
}
