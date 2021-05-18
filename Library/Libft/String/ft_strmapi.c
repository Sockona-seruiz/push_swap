/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: felix <felix@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:23:59 by fgalaup           #+#    #+#             */
/*   Updated: 2021/03/16 16:52:44 by felix            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *source, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	string_lenght;
	char			*string;

	string_lenght = ft_strlen(source);
	string = ft_managed_malloc((string_lenght + 1) * sizeof(char));
	if (string == NULL)
		return (NULL);
	string[string_lenght] = '\0';
	i = 0;
	if (source != NULL)
	{
		while (i < string_lenght)
		{
			string[i] = f(i, source[i]);
			i++;
		}
	}
	return (string);
}
