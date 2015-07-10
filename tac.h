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
#define TAC_VAR_DEF 4
#define TAC_VAR_DEF_PTR 5
#define TAC_VAR_DEF_VEC 6
#define TAC_RET	7
#define TAC_ADD 8
#define TAC_MUL 9
#define TAC_SUB 10
#define TAC_DIV 11
#define TAC_EQ 12
#define TAC_ARRAY_AC 13
#define TAC_INPUT 14
/*
#define TAC_SYMBOL	
#define TAC_LABEL	
#define TAC_IFZ	
#define TAC_JUMP	
#define TAC_CALL	
#define TAC_PRINT	
#define TAC_READ	
*/



#endif

#ifndef DEF_STRING_
#define DEF_STRING_
static char* DEF_STRING[50] = {
		"TAC_MOVE","TAC_BEGINFUN","TAC_ENDFUN","TAC_PARAM","TAC_VAR_DEF","TAC_VAR_DEF_PTR","TAC_VAR_DEF_VEC","TAC_RET","TAC_ADD","TAC_MUL",
		"TAC_SUB","TAC_DIV","TAC_EQ","TAC_ARRAY_AC","TAC_INPUT" ,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0,
	};
#endif

