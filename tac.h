#ifndef TAC_H
#define TAC_H

#include "hash.h"
#include "AST.h"
typedef struct tac
{
	int instr_code;
	struct hash* add1;
	struct hash* add2;
	struct hash* add3;
	struct tac *prev;
}TAC;






TAC* tac_create(int instr_code, struct hash* add1, struct hash* add2, struct hash* add3);
void tac_print_list(TAC* last);
TAC* tac_unify(TAC* tac_list1,TAC* tac_list2);
TAC* tac_tree_tac(astree_node *node);

#define TAC_MOVE 0
#define TAC_BEGINFUN 1	
#define TAC_ENDFUN 2
#define TAC_PARAM	3

/*
#define TAC_SYMBOL	
	
#define TAC_ADD	
#define TAC_MUL	
#define TAC_LABEL	

#define TAC_IFZ	
#define TAC_JUMP	
#define TAC_CALL	

#define TAC_RET	
#define TAC_PRINT	
#define TAC_READ	
*/



#endif

#ifndef DEF_STRING_
#define DEF_STRING_
static char* DEF_STRING[50] = {
		"TAC_MOVE","TAC_BEGINFUN","TAC_ENDFUN","TAC_PARAM",0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};
#endif

