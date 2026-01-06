/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:56 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/06 01:17:34 by bjmrzd           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				index;
	int				index2;
}					t_list;

typedef struct s_count
{
	int				sa_count;
	int				sb_count;
	int				ss_count;
	int				rb_count;
	int				ra_count;
	int				rr_count;
	int				rra_count;
	int				rrb_count;
	int				rrr_count;
	int				pa_count;
	int				pb_count;
	int				total_count;
}					t_count;

typedef enum e_flag
{
	NO_FLAG = 0,
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	BENCH,
}					t_flag;

t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
t_flag				arg_error(int argc, char *argv[]);
t_flag				second_flag(int argc, char *argv[]);

float				disorder(t_list **list);

void				ra(t_list **list, t_count *count);
void				sa(t_list **list, t_count *count);
void				rra(t_list **list, t_count *count);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				parsing(int argc, char *argv[], t_list **a);
void				parsing_str(int argc, char *argv[], t_list **a, int num);
void				*ft_calloc(size_t nmemb, size_t size);
void				error_arg(void);
void				simple_sort(int argc, char *argv[], t_list **list,
						t_count *count);
void				pb(t_list **a, t_list **b, t_count *count);
void				pa(t_list **a, t_list **b, t_count *count);
void				bench(int argc, char *argv[], t_list **list,
						t_count *count);
void				strategy(int argc, char *argv[]);
void				init_count(t_count *count);
void				sort3(t_list **a_list, t_count *count);
void				selection_sort(t_list **a_list, t_count *count);

int					count_ops(t_count *count);
int					duplicate_parsing(t_list **list);
int					ft_atoi(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					sorted(t_list *list);
int					ft_isdigit(char *c);
int					ft_lstsize(t_list *lst);
int					flag_count(char *argv[], int arg_index);
int					ft_printf(const char *str, ...);
int					print_ptr(void *ptr);
int					print_unsigned(unsigned int n);
int					print_hexa(unsigned long long n, const char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(const char *s, int fd);
int					getMin(t_list **list);

char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				**delim_split(char const *s, char **split_s, char c);
char				**free_split(char **split_s, size_t count);
char				*ft_substr(const char *s, unsigned int start, size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				len_split(char const *s, char c);
#endif