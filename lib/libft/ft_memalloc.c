/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lloyet <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/11 14:40:14 by lloyet       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 17:39:25 by lloyet      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;

	if ((mem = (void *)malloc(sizeof(void) * (size))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		((char *)mem)[i++] = 0;
	return (mem);
}
