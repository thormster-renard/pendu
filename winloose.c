/*
** winloose.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Jan  4 02:32:46 2020 thormster
** Last update Tue Jan  7 20:11:48 2020 thormster
*/

#include	"hangout.h"

int		lostgame(t_pendu *pendu, char *t)
{
  xputstr("\n\n## Vous avez perdu... ##\n");
  xputstr("## Le mot était  ");
  xputstr(pendu->secret);
  xputstr("\nDommage... ");
  xputstr("Cependant, vous pouvez toujours retenter votre chance\n\n\n");
  quit_game(pendu, t);
  return (0);
}

int		wingame(t_pendu *pendu, char *t)
{
  xputstr("\nVous avez gagné !!!\n\n\n\n");
  quit_game(pendu, t);
  return (0);
}
