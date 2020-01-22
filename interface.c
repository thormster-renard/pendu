/*
** interface.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Wed Jan  8 21:50:07 2020 thormster
** Last update Wed Jan  8 21:50:33 2020 thormster
*/

#include	"hangout.h"

void		interface_round(int i)
{
  xputstr("##################################################\n");
  xputstr("[ROUND ");
  xputnbr(i);
  xputstr("]  Alors quelle lettre compose ce mot ?  ");
}
