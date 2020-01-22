/*
** main.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Thu Jan  2 00:23:33 2020 thormster
** Last update Wed Jan  8 21:42:00 2020 thormster
*/

#include	"hangout.h"

char		*get_secret_word(FILE *file)
{
  char		*secret;
  int		cursor;
  int		i;

  i = 0;
  cursor = 0;
  if ((secret = malloc(27 * sizeof(char))) == NULL)
    return (NULL);
  while (cursor != EOF)
  {
    cursor = fgetc(file);
    secret[i++] = cursor;
  }
  secret[i - 2] = '\0';
  return (secret);
}

int		main(int ac, char **av)
{
  FILE		*file;
  t_pendu	*pendu;

  if ((file = init_file(ac, av)) == NULL)
    return (ERR);
  if ((pendu = init_struct()) == NULL)
    return (ERR);
  if ((pendu->secret = get_secret_word(file)) == NULL)
    return (ERR);
  pendu->size = xstrlen(pendu->secret);
  if ((pendu->letters_found = init_letters_found_tb(pendu)) == NULL)
    return (ERR);
  if ((fclose(file)) == -1)
    return (-1);
  if ((welcome()) == ERR)
    return (ERR);
  if ((start_game(pendu)) == ERR)
    return (ERR);
  return (0);
}
