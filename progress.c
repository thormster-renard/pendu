/*
** progress.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Jan  4 02:34:04 2020 thormster
** Last update Sat Jan  4 02:40:22 2020 thormster
*/

#include	"hangout.h"

int		check_progress(t_pendu *pendu, int *letters_found)
{
  int		i;

  i = 0;
  while (i != pendu->size)
  {
    if (letters_found[i] == 0)
      return (0);
    i += 1;
  }
  return (1);
}

void		display_progress(t_pendu *pendu, int *letters_found)
{
  int		i;

  i = 0;
  xputstr("\nMot à découvrir : ");
  while (i != pendu->size)
  {
    if (letters_found[i] == 1)
      xputchar(pendu->secret[i]);
    else
      xputchar('*');
    i += 1;
  }
  xputchar('\n');
}
