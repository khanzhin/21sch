/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharlin <lcharlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:24:27 by lcharlin          #+#    #+#             */
/*   Updated: 2019/10/21 15:29:13 by lcharlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct		s_tetro
{
	int			*tetro_id;
	char			letter;
	struct s_tetro	*next;
}					t_tetro;

void				ft_usage(int argc);
void				ft_check_access(int fd);
void				ft_check_file(int fd);
int					ft_check_for_symbols(char *line);
void				ft_check_connection(char *str);
void				ft_figures_counter(int i);
void				ft_check_horizontal_line(char *str);
void				ft_check_eof(int fd);
t_tetro				*ft_str_to_int(int fd, char *line);
void				ft_pe4at(int *nb);
int					*ft_chr_min_x_y(int *coordinates);
int					*ft_to_the_left_corner(int *coordinates, int x, int y);


t_tetro *ft_create_node(int *nb);
t_tetro *append(t_tetro *head, int *nb);
void	ft_print_result2(int n);
void	ft_print_result(char *s);
void ft_map_size(t_tetro head);
char **ft_map_create(int n);
void ft_place_figure(char **map_zero, t_tetro *head);

#endif
