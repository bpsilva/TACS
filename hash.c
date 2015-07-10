// Bruno Pinto Silva Cartão: 217446 bpsilva


#include "hash.h"


void initMe()
{
	temp_var_counter = 65;
	int i;
		for(i = 0 ; i < TAM ; i++)
		{
			table[i] = 0;
		}
}

void print()
{
struct hash* pointer;
int i = 0;
	for(i = 0 ; i < TAM ; i++)
	{
		
		for(pointer = table[i]; pointer !=0 ; pointer = (struct hash*)pointer->prox)
		{
			printf("%s ", pointer->word);
		}
		printf("\n");
	}



}

struct hash* insert(char* text, int type, int line){
	int address = genAddress(text);
	struct hash *pointer = table[address], *aux = table[address];


	
	for(;pointer!=0; aux = pointer,	pointer= (struct hash*)pointer->prox)
	{
		if(!strcmp(text, pointer->word))
		{
		pointer->linenumber = line;	
			
			return pointer;
		}
	}
	
	struct hash *node = (struct hash*)malloc(sizeof(struct hash));
	node->word = (char *)calloc(1,strlen(text)+1);
	strcpy(node->word, text);
		
	
	node->natureza = 0;
	node->defcounter = 0;
	node->prox = 0;
	node->type = type;
	
	if(aux!=0)
	{
		aux->prox = node;			
	}
	else{
		table[address] = node;
		}
	
return node;
}




int genAddress(char* word)
{
int i = 0;
int position = 0;
	for(i = 0; i< strlen(word);i++)
	{
	position += word[i];
	}
	position = position % TAM;

return position;
}

struct hash* hash_create_tempvar()
{

	char* text = (char*)malloc(sizeof(char)*6);
	text[0] = '_';
	text[1] = 't';
	text[2] = 'e';
	text[3] = 'm';
	text[4] = 'p';
	text[5] = temp_var_counter;
	temp_var_counter++;

	return insert(text, 0, 0);
}

struct hash* hash_create_label()
{
	return 0;
}







