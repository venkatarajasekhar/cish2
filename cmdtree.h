#ifndef _CMDTREE_H
#define _CMDTREE_H

#include "args.h"

typedef struct cmdnode
{
	char	*word;
	int		 level;
	char	*trigger;
	char	*help;
	
	struct cmdnode *parent;
	struct cmdnode *prev;
	struct cmdnode *next;
	struct cmdnode *first;
	struct cmdnode *last;
} cmdnode;

extern cmdnode *CMD_ROOT;

void			 destroy_cmdnode (cmdnode *);
cmdnode			*new_cmdnode (cmdnode *);
char			*reload_treedata (const char *);
char 			*read_treedata (const char *);
char 			*expand_cmdtree (const char *, int);
term_arglist	*expand_cmdtree_full (const char *);
char			*explain_cmdtree (const char *, int);
char			*substr (const char *, int, int);
int				 cmd_match (const char *, const char *);
char			*cmd_expandterm (const char *, const char *);

#endif
