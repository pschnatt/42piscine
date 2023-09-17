/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scrattan <scrattan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 06:49:06 by thakitwo          #+#    #+#             */
/*   Updated: 2023/06/26 12:31:32 by scrattan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct str
{
	char				*value;
	long long int		key;

}	t_strc;

int					count_word(int fd, t_strc *s_dict);
int					pstr(char *str, t_strc *s_dict);
int					find_pos(long long int ans);
int					trim(char *str, t_strc *s_dict, int pos);
t_strc				*ft_read(char *file_path);
int					find_len_str(char *str);
long long int		ft_atoi(char *str);
void				ft_convert(long int val, int size, t_strc *dict, int recur);

#endif