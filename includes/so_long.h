/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbastard <jbastard@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-17 10:17:12 by jbastard          #+#    #+#             */
/*   Updated: 2025-02-17 10:17:12 by jbastard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/include/libft.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <stdbool.h>
# include <sys/time.h>
# include <time.h>

# define ESCKEY 65307
# define WKEY 119
# define UPARROW 65362
# define AKEY 97
# define LEFTARROW 65361
# define SKEY 115
# define DOWNARROW 65364
# define DKEY 100
# define RIGHTARROW 65363

# define SIZE 64

# define BORDER '1'
# define EMPTY '0'

typedef struct s_solong
{
	struct timeval	last_frame_time;
	int				frame_counter;
	void			*mlx;
	void			*win;
	int				winwidth;
	int				winheight;
	char			**map;
	int				mapwidth;
	int				mapheight;
	int				collectibles;
	void			*ground[4];
	void			*border[4];
	void			*corner[4];
	void			*ruins[4];
	void			*door[3];
	void			*endbanner[6];
	void			*tendbanner[6];
	void			*downcount[12];
	void			*num[11];
	void			*water[2];
	void			*playeridle[4];
	void			*minos_ir[4];
	void			*minos_il[4];
	void			*minos_attack[8];
	void			*comestibles[2];
	int				movecount;
	int				pposx;
	int				pposy;
	int				eposx;
	int				eposy;
	int				end;
}	t_solong;

//CORE
	//INIT.C
void	set_zero(t_solong	*solong);
void	init_map(t_solong	*solong, char *argv1);
void	init_win(t_solong	*solong, char *argv1);
	//MAIN.C
int		main(int argc, char **argv);

//ERROR
	//ERROR_HANDLER.C
void	destroy_image_iterate(t_solong *solong, void **images, int count);
void	free_textures(t_solong *solong);
void	free_map(char **str, int bexit);
void	data_free(t_solong	*solong, char *error);
int		close_window(t_solong *solong);

//GAME
	//INPUTS.C
int		hook_handler(int keycode, t_solong	*solong);
void	claim_hook(t_solong	*solong);
	//PLAYER_MOVES
void	player_update(t_solong	*solong, int where);
void	player_mov(t_solong	*solong, int keycode);

//GRAPHICS
	//ANIMATION.C
void	put_monsters(t_solong *solong, int spriteIndex, char c);
int		update_frame(t_solong *solong, int target_fps);
void	game_loop(t_solong *solong);
int		animate(t_solong *solong);
	//DISPLAY_MAP.C
void	fill_down_water(t_solong *solong);
void	put_random_4(t_solong	*solong, void	*img_ptr[4], int x, int y);
void	wich_one(t_solong	*solong, int x, int y);
void	display_map(t_solong	*solong);
	//DISPLAY_MOVES.C
void	end_of_game(t_solong *solong);
void	were_is_player(t_solong *solong);
	//DISPLAY_UI.C
void	put_banner(t_solong *solong, void **texture, int x, int y);
void	display_count(t_solong *solong, int x, int y);
void	display_move_count(t_solong *solong, int x, int y);
void	update_move_count(t_solong	*solong);
void	update_collectibles_count(t_solong *solong);
	//LOAD_ALL_SPRITES.C
void	load_sprites(t_solong *solong);
void	set_null_sprites(t_solong *solong);
void	set_null_array(void **array, int count);
	//LOAD_CHAR.C
void	load_player_idle(t_solong *solong);
void	load_attack(t_solong *solong);
void	load_minos_il(t_solong *solong);
void	load_minos_ir(t_solong *solong);
	//LOAD_SPRITES_ENVIRONMENT.C
void	load_ground(t_solong *solong);
void	load_corner(t_solong *solong);
void	load_border(t_solong *solong);
void	load_environment(t_solong *solong);
void	load_water(t_solong *solong);
	//LOAD_SPRITES_UI.C
void	load_num(t_solong *solong);
void	load_count(t_solong	*solong);
void	load_ground_end_banner(t_solong	*solong);
void	load_end_banner(t_solong *solong);

//PARSING
	//FLOOD_FILL.C
void	map_flood_fill(char **map, int y, int x);
void	map_dup(char **map, char ***copy);
int		map_compare(char **map, char **copy);
int		is_valid_path(t_solong solong);
	//MAP_CHECKER.C
int		is_true_map(t_solong *solong);
int		is_all_valid_char(t_solong	solong);
int		is_full(char **map, char c);
int		is_walled(t_solong	solong);
int		is_rectangle(char **map);
	//PARSING.C
void	put_bszero(char *str);
int		get_height(char *argv1);

//UTILS
	//UTILS.C
int		is_dot_ber(char	*path);
void	find_player(t_solong	*solong);
void	put_image(t_solong	*solong, void	*img, int x, int y);
void	is_screen_sized(t_solong	*solong);

#endif
