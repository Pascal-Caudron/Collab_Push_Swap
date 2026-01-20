/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjmrzd <bjmrzd@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:02:56 by brouzaud          #+#    #+#             */
/*   Updated: 2026/01/17 17:05:49 by bjmrzd           ###   ########.fr       */
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
	int				data;
	int				index;
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

typedef struct s_dis
{
	float			dis;
}					t_dis;

t_list				*ft_lstnew(int content);
t_list				*ft_lstlast(t_list *lst);
t_list				**sort_logic(char *argv[], t_list **a_list, t_count *count);
t_flag				arg_error(char *argv[]);
t_flag				second_flag(char *argv[], t_list **a_list);

float				disorder(t_list **list);

void				ra(char *argv[], t_list **list, t_count *count);
void				rb(char *argv[], t_list **list, t_count *count);
void				sa(char *argv[], t_list **list, t_count *count);
void				sb(char *argv[], t_list **list, t_count *count);
void				rra(char *argv[], t_list **list, t_count *count);
void				rrb(char *argv[], t_list **list, t_count *count);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				parsing(int argc, char *argv[], t_list **a);
void				parsing_str(int argc, char *argv[], t_list **a, int num);
void				*ft_calloc(size_t nmemb, size_t size);
void				error_arg(t_list **a_list);
void				simple_sort(char *argv[], t_list **list, t_count *count);
void				pb(char *argv[], t_list **a, t_list **b, t_count *count);
void				pa(char *argv[], t_list **a, t_list **b, t_count *count);
void				bench(char *argv[], t_count *count, t_dis *init_dis,
						t_list **a_list);
void				strategy(char *argv[], t_list **a_list);
void				init_count(t_count *count);
void				sort3(char *argv[], t_list **a_list, t_count *count);
void				selection_sort(char *argv[], t_list **a_list,
						t_count *count);
void				radix_sort(char *argv[], t_list **a_list, t_count *count);
void				init_radix(char *argv[], t_list **a_list, t_count *count);
void				adaptive(char *argv[], t_list **list, t_count *count);
void				strat_select(char *argv[], t_list **list, t_count *count);
void				init_disorder(t_list **list, t_dis *init);
void				complex_sort(char *argv[], t_list **a_list, t_count *count);
void				free_list(t_list **list);
void				presort_index(t_list **a_list);
void				bucket_sort(char *argv[], t_list **a_list, t_count *count);
void				medium_push_back(char *argv[], t_list **a_list,
						t_list **b_list, t_count *count);

int					count_ops(t_count *count);
int					duplicate_parsing(t_list **list);
int					ft_atoi(const char *nptr, t_list **a_list);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					sorted(t_list **list);
int					ft_isdigit(char *c);
int					ft_lstsize(t_list *lst);
int					flag_count(char *argv[], int arg_index, t_list **a_list);
int					ft_printf(const char *str, ...);
int					print_ptr(void *ptr);
int					print_unsigned(unsigned int n);
int					print_hexa(unsigned long long n, const char c);
int					ft_putchar_fd(char c, int fd);
int					ft_putnbr_fd(int n, int fd);
int					ft_putstr_fd(const char *s, int fd);
int					get_min(t_list **list);
int					min_index(t_list **list);
int					max_bits(t_list **list);
int					print_float(float number, int fd);
int					square_root(int size);
int					max_index(t_list **list);
int					get_max(t_list **list);

char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				**delim_split(char const *s, char **split_s, char c);
char				**free_split(char **split_s, size_t count);
char				*ft_substr(const char *s, unsigned int start, size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				len_split(char const *s, char c);
#endif