/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcanales <zcanales@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 14:07:25 by zcanales          #+#    #+#             */
/*   Updated: 2022/05/25 17:24:02 by cdiaz-fl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

char	*get_next_line(int fd);
char	*find_next_line(char *holder);
char	*save_holder(char *buf, char *holder);
char	*new_holder(char	*holder);
char	*read_file(int fd, char *holder);
void	get_rgb(void *object, char *s, char c);
void	get_pos(void *object, char **head, char c, char *s);
void	get_n_vec(void *object, char **head, char c, char *s);

#endif
