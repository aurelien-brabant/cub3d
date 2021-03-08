/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 14:45:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/03/08 21:28:46 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>

#include "libft/io.h"
#include "libft/cstring.h"
#include "libft/cla.h"

#include "cub3d.h"
#include "parsing.h"
#include "msg.h"
#include "gfx.h"

static void	check_dotcub_filepath(void *cla, int *c3d_fd, char *err,
		char **filepath)
{
	ft_cla_pos_var(cla, filepath, 0, NULL);
	*c3d_fd = open(*filepath, O_RDONLY);
	if (*c3d_fd == -1 || read(*c3d_fd, NULL, 0) == -1)
	{
		if (*c3d_fd != -1)
			close(*c3d_fd);
		ft_snprintf(err, ERR_LEN, "%s: %s", *filepath, strerror(errno));
	}
	else if (!ft_strhssfx(*filepath, ".cub"))
		ft_snprintf(err, ERR_LEN, "Expected extension .cub.");
}

static void	check_opt(void *cla, char **allowed_opt, uint8_t *opt)
{
	size_t	i;

	i = 0;
	while (i < OPT_TOTAL - 1)
	{
		if (ft_cla_bool_var(cla, NULL, allowed_opt[i], false))
			*opt |= (1 << i);
		++i;
	}
}

static void	parse_cla(t_cub3d *c3d, int ac, char **av)
{
	static char		*allowed_opt[] = {"save", "parse-only", "save-name=",
		NULL};
	t_cla_config	conf;
	void			*cla;
	char			err[ERR_LEN];

	cla = ft_cla_init(ac, av);
	conf = ft_cla_get_config();
	conf.max_pos = 1;
	conf.min_pos = 1;
	conf.allowed_opt = allowed_opt;
	if (!ft_cla_sanity_check(cla, &conf, err))
		ft_snprintf(c3d->err, ERR_LEN, "%s\nUsage: %s", err, PROG_USAGE);
	else
	{
		check_dotcub_filepath(cla, &c3d->fildes, c3d->err,
				&c3d->mapdat.map_name);
		check_opt(cla, allowed_opt, &c3d->opt);
	}
	ft_cla_str_var(cla, &c3d->screenshot_name, "save-name", "screenshot.bmp");
	free(cla);
	cub3d_shift_state(c3d, NULL);
}

bool	is_loop_alive(t_cub3d *c3d)
{
	if (c3d->err[0] != '\0')
		return (false);
	if (c3d->opt & OPT_PARSE_ONLY && c3d->state == ST_INGAME)
		return (false);
	if (c3d->state == ST_STOPPING)
		return (false);
	return (true);
}

int	main(int ac, char **av)
{
	t_cub3d	c3d;

	c3d.state = ST_INITIALIZING;
	c3d.err[0] = '\0';
	c3d.opt = 0;
	while (is_loop_alive(&c3d))
	{
		if (c3d.state == ST_INITIALIZING)
			cub3d_init(&c3d);
		else if (c3d.state == ST_PARSING_ARGS)
			parse_cla(&c3d, ac, av);
		else if (c3d.state == ST_PARSING_ID)
			parse_id(&c3d);
		else if (c3d.state == ST_PARSING_MAP)
			parse_map(&c3d);
		else if (c3d.state == ST_INGAME)
			init_gfx(&c3d);
		else
			ft_snprintf(c3d.err, ERR_LEN, "Loop exited sooner than expected.");
	}
	cub3d_destroy(&c3d);
}
