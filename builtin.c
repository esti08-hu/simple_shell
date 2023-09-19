#include "shell.h"
/**
 * my_exit - exits the shell
 * @shell_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if shell_info->argv[0] != "exit"
 */
int my_exit(info_t *shell_info)
{
	int exit_check;

	if (shell_info->argv[1]) /* If there is an exit argument */
	{
		exit_check = error_atoi(shell_info->argv[1]);
		if (exit_check == -1)
		{
			shell_info->status = 2;
			print_error(shell_info, "Illegal number: ");
			_err_puts(shell_info->argv[1]);
			_err_putchar('\n');
			return (1);
		}
		shell_info->error_number = error_atoi(shell_info->argv[1]);
		return (-2);
	}
	shell_info->error_number = -1;
	return (-2);
}


