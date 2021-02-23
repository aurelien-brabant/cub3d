/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrabant <abrabant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:54:03 by abrabant          #+#    #+#             */
/*   Updated: 2021/02/22 21:54:09 by abrabant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

/*
** cub3D USER CONFIGURATION
**
** Anything put in this header is intended to be modified
** modified by the user.
**
** DON'T FORGET to run 'make reconfig' when changes have been made.
*/

# define FOV_ANGLE 90

/*
** KEYBINDINGS CONFIGURATION
**
** Presets for QWERTY (WASD) and AZERTY (ZQSD) are available below.
** Uncomment the keybindings you want, and comment those
** you don't want.
**
** This way of setting the keybindings is not the best we can do,
** but that's the easiest way I found to do it while respecting
** the norm.
*/

/*
** GENERAL PRESETS
*/

# define KB_QUIT			0xff1b // Escape key
# define KB_TURN_LEFT		0xff51 // Left arrow
# define KB_TURN_RIGHT		0xff53 // Right arrow

/*
** AZERTY PRESETS
*/

/*
# define KB_MOVE_FORWARD	0x007a // z
# define KB_MOVE_BACKWARD	0x0073 // s
# define KB_MOVE_LEFT		0x0071 // q
# define KB_MOVE_RIGHT		0x0064 // d
*/

/*
** QWERTY PRESETS
*/

# define KB_MOVE_FORWARD	0x0077 // w
# define KB_MOVE_BACKWARD	0x0073 // s
# define KB_MOVE_LEFT		0x0061 // a
# define KB_MOVE_RIGHT		0x0064 // d

#endif
