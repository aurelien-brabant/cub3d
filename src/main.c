/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 14:45:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/01/04 12:26:39 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>

#include "core.h"

#include "libft/dvector.h"
#include "libft/io.h"
#include "libft/string.h"

static void	parse_args(t_cub3d *c3d, int ac, char **av)
{
	if (ac == 0 || ac > 2)
	{
		ft_snprintf(c3d->err, ERR_LEN, "Too few/much args. Usage: %s",
			PROG_USAGE);
		return ;
	}
	c3d->dotcub_fd = open(av[0], O_RDONLY);
	if (c3d->dotcub_fd == -1 || read(c3d->dotcub_fd, NULL, 0) == -1)
		ft_snprintf(c3d->err, ERR_LEN, "%s: %s", av[0], strerror(errno));
	else if (!ft_strhssfx(av[0], ".cub"))
		ft_snprintf(c3d->err, ERR_LEN, "Expected .cub file extension.");
	else if (ac == 2)
	{
		//need a true strcmp here
		if (ft_strncmp(av[1], "--save", ft_strlen(av[1])) != 0)
			ft_snprintf(c3d->err, ERR_LEN, "Unknown arg: \"%s\"", av[1]);
		else
			c3d->meta |= META_SAVE;
	}
	cub3d_shift_state(c3d, NULL);
}

int	main(int ac, char **av)
{
	t_cub3d	c3d;

	c3d.state = ST_NONE;
	while (c3d.state != ST_STOPPED)
	{
		if (c3d.state == ST_PARSING_ARGS)
			parse_args(&c3d, ac - 1, av + 1);
		else if (c3d.state == ST_PARSING_ID)
			break ;
		else
			cub3d_init(&c3d);
		if (c3d.err[0] != '\0')
			break ;
	}
	cub3d_destroy(&c3d);
}
