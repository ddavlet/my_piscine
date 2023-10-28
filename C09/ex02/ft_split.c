#include <stdio.h>
#include <stdlib.h>

int	ft_is_in_charset (char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_split (char *str, char *charset)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (ft_is_in_charset(str[i], charset) == 1 && ft_is_in_charset(str[i+1], charset) == 0)
			count++;
		i++;
	}
	return count;
}

int	ft_lengt (char *src, char *charset)
{
	int	i;

	i = 1;
	while (!ft_is_in_charset(src[i], charset) && src[i])
		i++;
	return i;
}
void ft_strcpy (char *dest, char *src,int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		*(dest++) = *(src++);
		i++;
	}
		*dest = 0;
}
char **ft_word(char **strs, char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (ft_is_in_charset(str[0], charset) == 0)
	{
		strs[0] = (char *)malloc((ft_lengt(str, charset) + 1) * sizeof(char));
		ft_strcpy (strs[0], str, ft_lengt(str, charset));
		j++;
		str++;
	}
	while (*str)
	{
		if (ft_is_in_charset(*str, charset) == 1 && *(str + 1) != 0)
		{
			strs[j] = (char *)malloc((ft_lengt(str, charset) + 1) * sizeof(char));
			ft_strcpy(strs[j], str + 1, ft_lengt(str, charset) - 1);
			j++;
		}
		str++;
	}
	return strs;
}

char **ft_split(char *str, char *charset)
{
	char	**strs;
	int		i;

	i = 0;
	strs = (char **)malloc((ft_count_split(str, charset) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	ft_word (strs, str, charset);
	return strs;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <input_string> <charset>\n", argv[0]);
        return 1;
    }

    char *input_string = argv[1];
    char *charset = argv[2];

    char **result = ft_split(input_string, charset);

    if (result) {
        printf("Split strings:\n");
        for (int i = 0; result[i] != NULL; i++) {
            printf("Split %d: %s\n", i, result[i]);
            free(result[i]); // Free memory allocated for each split string
        }
        free(result); // Free memory allocated for the array of strings
    } else {
        printf("Memory allocation failed for split strings.\n");
    }

    return 0;
}
