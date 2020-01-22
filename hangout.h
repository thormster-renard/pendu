/*
** hangout.h for Medev in /home/thormster/Dev/Melev/inc
** 
** Made by thormster
** Login   <thormster@localhost>
** 
** Started on  Sat Dec 28 23:29:12 2019 thormster
** Last update Thu Jan  9 10:43:37 2020 thormster
*/

#ifndef		__HANGOUT_H__
#define		__HANGOUT_H__

#include	<stdio.h>
#include	<stdlib.h>
#include	<string.h>
#include	<sys/stat.h>
#include	<unistd.h>

#define		ERR		-1
#define		LINE_BUFSIZE	128
#define		ERR_CHAR	"[Vous devez entrer une lettre.]\n"
#define		STAY_TRIALS_ONE	"Il vous reste "
#define		STAY_TRIALS_TWO	" essais pour découvrir le mot caché\n"


typedef	struct	s_pendu
{
  char		*secret;
  int		*letters_found;
  int		trials;
  int		size;
}		t_pendu;

/* clean.c */
void		clean_game(t_pendu*);

/* game.c */
int		verify_letter(t_pendu*, int*, char*);
char		*char_read();
int		start_game(t_pendu*);

/* init.c */
t_pendu		*init_struct();
FILE		*init_file(int, char**);
int		*init_letters_found_tb(t_pendu*);

/* interface.c */
void		interface_round(int);

/* main.c */
char		*get_secret_word(FILE*);

/* message.c */
void		remaining_trials(t_pendu*);
void		bad_answer(t_pendu*);
void		good_answer();

/* progress.c */
int		check_progress(t_pendu*, int*);
void		display_progress(t_pendu*, int*);

/* quit.c */
int		quit_game(t_pendu*, char*);

/* welcome.c */
int		welcome();

/* winloose.c */
int		lostgame(t_pendu*, char*);
int		wingame(t_pendu*, char*);

/* xlibc.c */
void		xputchar(char);
void		xputstr(char*);
void		xputnbr(int);
int		xstrlen(char*);

#endif
