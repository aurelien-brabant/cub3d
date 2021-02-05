/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 14:45:29 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/05 18:14:26 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <stdlib.h>

#include "cub3d_core.h"
#include "cub3d_parsing.h"
#include "cub3d_msg.h"

#include "cub3d_types.h"
#include "libft/io.h"
#include "libft/string.h"
#include "libft/cla.h"

static void	check_dotcub_filepath(void *cla, int *c3d_fd, char *err)
{
	char		*filepath;

	ft_cla_pos_var(cla, &filepath, 0, NULL);
	*c3d_fd = open(filepath, O_RDONLY);
	if (*c3d_fd == -1 || read(*c3d_fd, NULL, 0) == -1)
	{
		if (*c3d_fd != -1)
			close(*c3d_fd);
		ft_snprintf(err, ERR_LEN, "%s:%s", filepath, strerror(errno));
	}
	else if (!ft_strhssfx(filepath, ".cub"))
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
	static char		*allowed_opt[] = {"save", "parse-only", NULL};
	t_cla_config	conf;
	void			*cla;
	char			err[10000];

	cla = ft_cla_init(ac, av);
	conf = ft_cla_get_config();
	conf.max_pos = 1;
	conf.min_pos = 1;
	conf.allowed_opt = allowed_opt;
	if (!ft_cla_sanity_check(cla, &conf, err))
		ft_snprintf(c3d->err, ERR_LEN, "%s\nUsage: %s", err, PROG_USAGE);
	else
	{
		check_dotcub_filepath(cla, &c3d->fildes, c3d->err);
		check_opt(cla, allowed_opt, &c3d->opt);
	}
	free(cla);
	cub3d_shift_state(c3d, NULL);
}

int	loop_check(t_cub3d *c3d)
{
	if (c3d->err[0] != '\0')
		return (0);
	if (c3d->opt & OPT_PARSE_ONLY && c3d->state == ST_INGAME)
		return (0);
	if (c3d->state == ST_STOPPING)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_cub3d	c3d;

	c3d.state = ST_INITIALIZING;
	c3d.err[0] = '\0';
	c3d.opt = 0;
	while (loop_check(&c3d))
	{
		if (c3d.state == ST_INITIALIZING)
			cub3d_init(&c3d);
		else if (c3d.state == ST_PARSING_ARGS)
			parse_cla(&c3d, ac, av);
		else if (c3d.state == ST_PARSING_ID)
			parse_id(&c3d);
		else if (c3d.state == ST_PARSING_MAP)
			parse_map(&c3d);
		else
			ft_snprintf(c3d.err, ERR_LEN, "Loop exited sooner than expected.");
	}
	cub3d_destroy(&c3d);
}
