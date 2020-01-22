/*
** xlibc.c for Medev in /home/thormster/Dev/Melev/lib
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Dec 28 23:30:00 2019 thormster
** Last update Sat Jan  4 02:17:13 2020 thormster
*/

#include	"hangout.h"

void		xputchar(char c)
{
  write(1, &c, 1);
}

void		xputstr(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    {
      xputchar(s[i]);
      i += 1;
    }
}

void		xputnbr(int nb)
{
  if (nb < 0)
   {
     xputchar('-');
     nb = nb * -1;
   }
  if (nb >= 10)
   {
     xputnbr(nb / 10);
   }
  xputchar((nb % 10) + '0');
}

int		xstrlen(char *s)
{
  int		i;

  i = 0;
  while (s[i] != '\0')
    i += 1;
  return (i);
}
