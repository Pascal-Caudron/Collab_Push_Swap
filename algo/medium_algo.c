#include "../push_swap.h"

int	square_root(int size)
{
	int	val;

	val = 0;
	while (val * val < size)
		val++;
	printf("val = %d\n", val);
	return (val);
}

void	bucket_sort(char *argv[], t_list **a_list, t_count *count)
{
	t_list	**b_list;
	int		bucket_size;
	int		size;
	int		nb_values;
	int		bucket_limit;

	b_list = malloc(sizeof(t_list *));
	size = ft_lstsize((*a_list));
	presort_index(a_list);
	nb_values = 0;
	bucket_size = square_root(size);
	bucket_limit = bucket_size; // doit coder square root
	while (nb_values < size)
	{
		if ((*a_list)->data < bucket_size)
		{
			pb(argv, a_list, b_list, count);
			nb_values++;
		}
		else
			ra(argv, a_list, count);
	}
	if (bucket_size == nb_values && nb_values < size)
		bucket_size += bucket_limit;
	while (*b_list)
	{
		if (sorted(a_list) == 0)
			pa(argv, a_list, b_list, count);
		else
			rb(argv, a_list, count);
	}
	free(b_list);
}
