/*
** quit.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Tue Jan  7 20:02:24 2020 thormster
** Last update Tue Jan  7 20:13:28 2020 thormster
*/

#include	"hangout.h"

int		quit_game(t_pendu *pendu, char *letter)
{
  free(letter);
  free(pendu->secret);
  free(pendu->letters_found);
  free(pendu);
  return (0);
}
