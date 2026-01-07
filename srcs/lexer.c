#include "../minishell.h"

//This function handles you the chain of tokens made from the input to the prog 
t_token	*lexer(char *input, t_error *err)
{
	t_token	*chain;

	chain = NULL;
	ft_create_chain(&chain, ft_split_mini(input, ' ', err));
	err->lexer = 0;
	return (chain);
}
