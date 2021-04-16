#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "list.h"
int auto_increment=1;
//Método para criar uma lista
list * create_list()
{
	list* ret = (list*)malloc(sizeof(list));
	ret->first=ret->last=create_node();
	ret->length=0;
	return ret;
}
node * create_node()
{
	node* ret = (node*)malloc(sizeof(node));
	ret->next=NULL;
	return ret;
}
product create_product(char *description,float value,int quanitity)
{
	product p;
	strcpy(p.description,description);
	p.id=auto_increment++;
	p.value=value;
	p.quanitity=quanitity;
	return p;
}
//Método para inserir um produto no fim da lista
void add(list *l,product p)
{
	l->length++;
	node *n = create_node();
	n->value=p;
	l->last->next=n;
	n->previous=l->last;
	l->last=n;
}
//Método para inserir um produto no inicio da lista
void add_start(list * l,product p)
{
	l->length++;
	node * n = create_node();
	n->value=p;
	
	n->next=l->first->next;
	l->first->next->previous=n;
	l->first->next=n;
}
//Método para pesquisar um elemento da lista por codigo
product get_by_id(list * l,int id)
{
	for(node * i=l->first;;i=i->next)
	{
		if(i->value.id==id)return i->value;
		if(i==l->last)break;
	}
	return (product){0,"",0,0};
}
//Método para remover um produto no inicio da lista
product remove_start(list * l)
{
	l->length--;
	product ret=l->first->next->value;
	l->first->next=l->first->next->next;
	return ret;
}
//Método para remover um produto no final da lista
product remove_end(list * l)
{
	l->length--;
	product ret=l->last->value;
	l->last->previous->next=NULL;
	l->last=l->last->previous;
	return ret;
}
void print_product(product p)
{
	printf("{\"id\":%d,\"description\":\"%s\",\"value\":%.2f,\"quanitiy\":%d}\n",p.id,p.description,p.value,p.quanitity);
}
//Método para exibir toda a lista
void print(list * l)
{
	for(node * i=l->first->next;;i=i->next)
	{
		print_product(i->value);
		if(i->next==NULL)break;
	}
}
//Método para retornar o tamanho da lista
int count(list * l)
{
	return l->length;
}
//Método para remover um produto especifico, que recebe o código do produto a ser removido
product remove_by_id(list * l,int id)
{
	node * prev=l->first;
	for(node * i=l->first;;)
	{
		if(i->value.id==id)
		{
			prev->next=i->next;
			if(i==l->last)l->last=prev;
			product ret=i->value;
			free(i);
			return ret;
		}
		if(i->next==NULL)break;
		prev=i;
		i=i->next;
	}
	return (product){0,"",0,0};
}
//Método para alterar os dados de um produto especifico, que recebe o código do produto a ser alterado
void edit(list * l,int id,product p)
{
	for(node * i=l->first;;i=i->next)
	{
		if(i->value.id==id)
		{
			i->value=p;
			return;
		}
		if(i->next==NULL)break;
		i=i->next;
	}
}
void clear(list * l)
{
	node * prev=l->first;
	for(node * i=l->first;;)
	{

		if(i->next==NULL)break;
		prev=i;
		free(prev);
		i=i->next;
	}
	free(l);
}