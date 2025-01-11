#include "../../includes/minishell.h"

int	execute_builtin(t_node *cmd, char ***env)
{
	char	**args;

	if (!cmd->value)
		free_and_error(NULL, NULL, "execute_builtin error: cmd not found", 1);
	args = ft_split(cmd->value, ' ');
	if (!args)
		free_and_error(NULL, NULL, "execute_builtin: error splitting arguments",
			1);
	if (!strcmp(args[0], "export") || !strcmp(args[0], "unset")
		|| !strcmp(args[0], "cd"))
		nforked_commands(cmd->value, env);
	else if (!strcmp(args[0], "echo") || !strcmp(args[0], "env")
		|| !strcmp(args[0], "pwd"))
		forked_commands(cmd->value, env);
	free(args);
	return (1);
}

void	execute_relative_absolute(char *cmd, char **args, char ***envp)
{
	if (cmd[0] == '/' || (cmd[0] == '.' && (cmd[1] == '/' || cmd[1] == '.')))
	{
		if (access(cmd, X_OK) == 0)
		{
			if (execve(cmd, args, *envp) == -1)
			{
				free_triple_pointer(envp);
				free_and_error(cmd, args, "error executing ./minishell", 1);
			}
		}
	}
}

int	execute_command(t_node *cmd, char ***env)
{
	int		len;
	char	**args;
	char	*path;
	char	*full_command;

	args = ft_split(cmd->value, ' ');
	if (!args)
		free_and_error(NULL, args, "minishell: args malloc error", 1);
	execute_relative_absolute(cmd->value, args, env);
	path = get_path(args[0], env);
	if (!path)
	{
		printf("minishell: %s: command not found\n", args[0]);
		exit(EXIT_FAILURE);
	}
	len = ft_strlen(path) + ft_strlen(args[0]);
	full_command = malloc(sizeof(char) * (len + 1));
	if (!full_command)
		free_and_error(full_command, NULL, "minishell: malloc error", 1);
	ft_strcpy(full_command, path);
	if (execve(full_command, args, *env) == -1)
		free_and_error(NULL, NULL, "minishell: execve error", 1);
	free(full_command);
	exit(EXIT_SUCCESS);
}

int	execute_simple_command(t_node *cmd, char ***env)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
		free_and_error(NULL, NULL,
			"Execute_simple_command: error creating new process", 1);
	if (pid == 0)
	{
		execute_command(cmd, env);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}
