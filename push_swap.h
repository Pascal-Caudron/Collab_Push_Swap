#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				data;
	int				index;
}					t_list;

typedef struct s_stack // peut etre tout mettre dans la une meme struct
{
	struct s_list *a;
	struct s_list *b;
	int a_len;
	int b_len;
}					t_stack;

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

void				ra(t_list **list);
void				sa(t_list **list);
void				rra(t_list **list);
void				ft_lstadd_back(t_list **lst, t_list *node);
void				parsing(int argc, char *argv[], t_list **a);
void				parsing_str(int argc, char *argv[], t_list **a, int num);
void				*ft_calloc(size_t nmemb, size_t size);
void				error_arg(void);
void				bubble_sort(t_list **a_list);

int					duplicate_parsing(t_list **list);
int					ft_atoi(const char *nptr);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					sorted(t_list *list);
int					ft_isdigit(char *c);
int					ft_lstsize(t_list *lst);

char				**ft_split(char const *s, char c);
char				**delim_split(char const *s, char **split_s, char c);
char				**free_split(char **split_s, size_t count);
char				*ft_substr(const char *s, unsigned int start, size_t len);

size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
size_t				len_split(char const *s, char c);
#endif