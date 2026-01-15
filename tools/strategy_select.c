#include "../push_swap.h"

void	init_radix(char *argv[], t_list **a_list, t_count *count)
{
	if (sorted(a_list) == 0)
		exit(2);
	radix_sort(argv, a_list, count);
}

void	complex_sort(char *argv[], t_list **a_list, t_count *count)
{
	int	size;

	if (sorted(a_list) == 0)
		exit(2);
	size = ft_lstsize(*a_list);
	if (size == 3)
		sort3(argv, a_list, count);
	// else if (size == 5)
	// 	sort5();
	else
		init_radix(argv, a_list, count);
}

void	adaptive(char *argv[], t_list **list, t_count *count)
{
	float	dis;

	dis = disorder(list);
	if (dis < 0.2)
		simple_sort(argv, list, count);
	else if (dis >= 0.2 && dis < 0.5)
		bucket_sort(argv, list, count);
	else if (dis >= 0.5)
		complex_sort(argv, list, count);
}

void	strat_select(char *argv[], t_list **list, t_count *count)
{
	t_flag flag;
	t_flag isbench;

	isbench = arg_error(argv);
	if (isbench == BENCH)
		flag = second_flag(argv);
	else
		flag = arg_error(argv);
	if (flag == ADAPTIVE || flag == NO_FLAG)
		adaptive(argv, list, count);
	else if (flag == SIMPLE)
		simple_sort(argv, list, count);
	else if (flag == MEDIUM)
		bucket_sort(argv, list, count);
	else if (flag == COMPLEX)
		init_radix(argv, list, count);
}