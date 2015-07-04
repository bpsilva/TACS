#include "tac.h"
#include "hash.h"
#include "AST.h"
#include "semantics.h"
#include <stdlib.h>
#include <stdio.h>




TAC* tac_unify(TAC* tac_list1,TAC* tac_list2)
{

	if(tac_list2 == 0)
		return tac_list1;

	TAC* tac_aux = tac_list2;

	while(tac_aux->prev != 0)
		tac_aux = tac_aux->prev;

	tac_aux->prev =  tac_list1;

	return tac_list2;
}

void tac_print_list(TAC* last)
{
	if(last == 0)
		return;

	tac_print_list(last->prev);

	printf("%s", DEF_STRING[last->instr_code]);

	if(last->add1 != 0)
	{
		printf(" %s", last->add1->word);
	}
	if(last->add2 != 0)
	{
		printf(" %s", last->add2->word);
	}

	if(last->add3 != 0)
	{
		printf(" %s", last->add3->word);
	}
	printf("\n");

}
TAC* tac_create(int instr_code, struct hash* add1, struct hash* add2, struct hash* add3)
{
		
	TAC *tac = (TAC*)malloc(sizeof(TAC));

	tac->instr_code = instr_code;
	tac->add1 = add1;	
	tac->add2 = add2;
	tac->add3 = add3;
	
	return tac;
}

TAC* tac_tree_tac(astree_node *node)
{

if(node==0)
	return 0;

switch(node->type)
	{
		case FUNC_DEF:	
			return
		
			tac_unify( 
				tac_unify
				(
					tac_create(TAC_BEGINFUN, 0,0,node->sons[1]->symbol),
					tac_tree_tac(node->sons[2])
			
				),
				tac_tree_tac(node->sons[3])
			);

		case FUNC_BODY:	

			return tac_unify
				(
					tac_tree_tac(node->sons[0]),
					tac_create(TAC_ENDFUN, 0,0, 0)
				);

		case GLOBAL_VAR_DEF_INIT: 
		return tac_unify
			(	
			tac_create(TAC_MOVE, 0, node->sons[2]->symbol , node->sons[1]->symbol),
			tac_tree_tac(node->sons[3])
			);
			break;
		case GLOBAL_VAR_DEF_PTR:
			break;
		case GLOBAL_VAR_DEF_VEC : 
			
			break;
		case GLOBAL_VAR_DEF_VEC_INIT: 
			
			break;
		case INDEX_INIT:
			break;	
		case EXP_ARRAY_ACCESS: 
			break;
		case EXP_FUNC_CALL: 

			break;
		case ARG_SEQ : 

			break;
		case KW_RETURN: 
			break;
		case KW_OUTPUT: 

			break;
		case KW_INPUT: 

			break;
		case OUT_REST: 

			break;
		case SYMBOL_LIT_SEQ : 

		break;
		case PARAM : 
			return tac_unify(
					tac_create(TAC_PARAM, 0, 0, node->sons[1]->symbol),
					tac_tree_tac(node->sons[2])
					);

		case PARAM_SEQ : 
			return tac_unify(
					tac_create(TAC_PARAM, 0, 0, node->sons[1]->symbol),
					tac_tree_tac(node->sons[2])
					);

		break;
		case LOCAL_VAR_DEF : 

		break;
		case LOCAL_VAR_DEF_LIST : 
		

		break;
		case LOCAL_VAR_DEF_PTR: 

			break;
		case CMD_LIST : 

			break;
		case CMDS :

			break;
		case PRE_INC : 

			break;
		case POST_INC: 

			break;
		case SIMPLE_ATRIB : 

			break;
		case INDEX_ATRIB : 
	
			break;
		case OPERATOR_EQ : 

			break;
		case OPERATOR_LE : 

			break;
		case OPERATOR_GE : 

			break;
		case OPERATOR_OR : 

			break;
		case OPERATOR_AND : 

			break;
		case OPERATOR_NE : 

			break;
		case EXP_ADDR : 

			break;
		case EXP_PTR: 

			break;
		case SYMBOL_LIT_INTEGER:
		
			break;
		case SYMBOL_LIT_FALSE:			
	
			break;
		case SYMBOL_LIT_TRUE:
	
			break;
		case SYMBOL_LIT_CHAR:
		
			break;
		case SYMBOL_LIT_STRING:
		
			break;
		case SYMBOL_IDENTIFIER: 

		
			break;
		case KW_IF: 

			break;
		case KW_THEN: 

			break;
		case KW_ELSE: 

			break;
		case KW_LOOP:

			break; 
	}

return 0;

}

