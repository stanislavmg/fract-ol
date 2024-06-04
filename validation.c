#include "fractol.h"

static int	check_sign(char *str)
{
	if (!str)
		return (1);
	if (ft_isalpha(*str))
		return (1);
	if ((*str == '+' || *str == '-')
		&& (*(str + 1) == '+' || *(str + 1) == '-'))
		return (1);
	if ((*str == '+' || *str == '-') && !ft_isdigit(*(str + 1)))
		return (1);
	if ('.' == *str)
		return (1);
	if (!*str)
		return (1);
	return (0);
}

void	ft_putstr(char *s)
{
	size_t	i;

	if (!s)
		return ;
	i = ft_strlen(s);
	write(1, s, i);
}

int	check_arg(char *s)
{
	int		i;
	char	point;

	i = 0;
	point = 0;
	while (ft_isspace(*s))
		s++;
	if (check_sign(s))
		exit_fail("Invalid arguments\n");
	if ('+' == *s || '-' == *s)
		s++;
	while (s[i] && !ft_isspace(s[i]))
	{
		if ('.' == s[i] && !ft_isdigit(s[i + 1]))
			return (1);
		else if ('.' == s[i] && !point)
			point = 1;
		else if ('.' == s[i] && point)
			return (1);
		else if (!ft_isdigit(s[i]))
			return (1);
		i++;
	}
	while (ft_isspace(s[i]))
		i++;
	if (s[i])
		return (1);
	return (0);
}
