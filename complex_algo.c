#include "push_swap.h"

int	getMax(t_list **list)
{
	int		max;
	t_list	*tmp;

	// int		max_index;
	tmp = (*list);
	max = tmp->data;
	// max_index = 0;
	while (tmp)
	{
		if (tmp->data > max)
			max = tmp->data;
		tmp = tmp->next;
	}
	// tmp = (*list);
	// while (tmp)
	// {
	// 	if (tmp->data == max)
	// 		// return (++max_index);
	// 	// max_index++;
	// 	tmp = tmp->next;
	// }
	return (max);
}

int	max_bits(t_list **list)
{
	int	max;
	int	bits;

	max = getMax(list);
	bits = 0;
	while (max > 0)
	{
		max /= 2;
		bits++;
	}
	return (bits);
}

// int	getBits(int digit, int pos)
// {
// 	int	power;
// 	int	count;

// 	count = 0;
// 	power = 1;
// 	while (count < pos)
// 	{
// 		power *= 2;
// 		count++;
// 	}
// 	return ((digit / power) % 2);
// }

int	getBits(int digit, int pos)
{
	return ((digit >> pos) & 1);
}
void	radix_sort(t_list **b_list, t_list **a_list, t_count *count)
{
	int		m_bits;
	int		size;
	int		count_bits;
	int		index;
	t_list	*tmp;
	int		bits;

	size = ft_lstsize((*a_list));
	m_bits = max_bits(a_list);
	count_bits = 0;
	while (count_bits < m_bits)
	{
		index = 0;
		while (index < size)
		{
			tmp = (*a_list);
			bits = getBits(tmp->data, count_bits);
			if (bits == 0)
				pb(a_list, b_list, count);
			else
				ra(a_list, count);
			index++;
		}
		count_bits++;
	}
	while (*b_list)
		pa(a_list, b_list, count);
}
