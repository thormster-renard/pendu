/*
** game.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Fri Jan  3 01:04:24 2020 thormster
** Last update Wed Jan  8 21:53:00 2020 thormster
*/

#include	"hangout.h"

int		verify_letter(t_pendu *pendu, int *letters_found, char *letter)
{
  int		wt;
  int		i;

  i = 0;
  wt = 0;
  while (pendu->secret[i] != '\0')
  {
    if (letter[0] == pendu->secret[i])
    {
      letters_found[i] = 1;
      wt += 1;
    }
    else if (letter[0] < 97|| letter[0] > 122)
      return (-2);
    i += 1;
  }
  if (wt == 0)
    return (ERR);
  return (i);
}

char		*char_read()
{
  char		*letter;
  int		rd;

  if ((letter = malloc(2 * sizeof(char))) == NULL)
    return (NULL);
  if ((rd = read(1, letter, 2)) == ERR)
    return (NULL);
  letter[rd - 1] = '\0';
  return (letter);
}

int		start_game(t_pendu *pendu)
{
  char		*letter;
  int		ret;
  int		i;

  i = 0;
  while (pendu->trials > 0)
  {
    i += 1;
    display_progress(pendu, pendu->letters_found);
    interface_round(i);
    if ((letter = char_read()) == NULL)
      return (ERR);
    xputstr("##################################################\n\n");
    if ((ret = verify_letter(pendu, pendu->letters_found, letter)) == ERR)
    {
      bad_answer(pendu);
      pendu->trials -= 1;
    }
    else if (ret == -2)
      xputstr(ERR_CHAR);
    else
      good_answer(pendu);
    ret = check_progress(pendu, pendu->letters_found);
    if (pendu->trials == 0 && ret == 0)
      return (lostgame(pendu, letter));    
    else if (ret == 1)
      return (wingame(pendu, letter));
  }
  return (0);
}
