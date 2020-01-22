/*
** init.c for pendu in /home/thormster/Dev/pendu
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Fri Jan  3 00:59:05 2020 thormster
** Last update Tue Jan  7 20:16:21 2020 thormster
*/

#include	"hangout.h"

t_pendu		*init_struct()
{
  t_pendu	*pendu;

  if ((pendu = malloc(4 * sizeof(t_pendu*))) == NULL)
    return (NULL);
  pendu->trials = 9;
  pendu->secret = NULL;
  pendu->letters_found = 0;
  return (pendu);
}

int		check_file_exist(char *file)
{
  struct stat	s;

  if (stat(file, &s) != 0)
  {
    xputstr("[ERROR] Le fichier getword n'est pas dans le repertoire du jeu.\n");
    return (ERR);
  }
  return (0);
}

FILE		*init_file(int ac, char **av)
{
  FILE		*pipe;
  FILE		*file;
  char		line[LINE_BUFSIZE];
  char		*filename;
  int		linenr;

  ac = ac;
  file = NULL;
  filename = "./getword";
  if ((check_file_exist(filename)) == 0)
  {
    if ((pipe = popen(filename, "r")) == NULL)
    {
      perror(av[0]);
      return (NULL);
    }
    linenr = 1;
    while (fgets(line, LINE_BUFSIZE, pipe) != NULL)
    {
      printf("Script output line %d: %s", linenr, line);
      ++linenr;
    }
    pclose(pipe);
    if ((file = fopen("/tmp/secret", "r")) == NULL)
      return (NULL);
    return (file);
  }
  return (NULL);
}

int		*init_letters_found_tb(t_pendu *pendu)
{
  int		*letters_found;
  int		i;

  i = 0;
  if ((letters_found = malloc(pendu->size * sizeof(int))) == NULL)
    return (NULL);
  while (i != pendu->size)
  {
    letters_found[i] = 0;
    i += 1;
  }
  return (letters_found);
}
