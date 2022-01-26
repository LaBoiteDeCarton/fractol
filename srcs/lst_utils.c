#include "fct.h"

t_list	*ft_lstnieme(t_list *lst, int n)
{
	if (n < 0)
		return (lst);
	while (n-- > 0)
	{
		if (!lst->next)
			return(NULL);
		lst = lst->next;
	}
	return(lst);
}

void	ft_lstdelfront(t_list **lst)
{
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(tmp, &free_col);
	}
}