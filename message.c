/*
** message.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Jan  4 02:31:06 2020 thormster
** Last update Thu Jan  9 10:44:11 2020 thormster
*/

#include	"hangout.h"

void		remaining_trials(t_pendu *pendu)
{
  xputstr(STAY_TRIALS_ONE);
  xputnbr(pendu->trials);
  xputstr(STAY_TRIALS_TWO);
  xputstr("----------------------------------------------------------------------------------------\n\n");
}

void		bad_answer(t_pendu *pendu)
{
  xputstr("----------------------------------------------------------------------------------------\n");  
  xputstr("Dommage, cette lettre n'est pas présente dans le mot que vous devez trouver...\n");
  remaining_trials(pendu);
}

void		good_answer()
{
  xputstr("---------------------------------------------------------------------------------------\n");
  xputstr("Bien joué, vous avez trouvez une des ");
  xputstr("lettres composants le mot.. à mon grand regret\n");
  xputstr("---------------------------------------------------------------------------------------\n\n");
}
