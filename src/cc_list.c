#include "cc_list.h"
#include <stdlib.h>

comp_list_t* cc_list_create(int type)
{
    comp_list_t* list = (comp_list_t*) malloc(sizeof(comp_list_t*));
    list->type = type;
    list->next = NULL;
    return list;
}

comp_list_t* cc_list_append(comp_list_t* list, comp_list_t* item)
{
    if(item!=NULL && list!=NULL)
    {
    	comp_list_t *l = list;
    	while(l->next!=NULL)
    	{
    	    l=l->next;
    	};
    	l->next = item;
    }
    return list;
}

void cc_list_remove(comp_list_t* list, comp_list_t* item)
{
}

comp_list_t* cc_list_get(comp_list_t* list,int n)
{
    int i=0;
    comp_list_t *l = list;
    do
    {
        l=l->next;
        i++;
    }while(i!=n && l!=NULL);
    return l;
}

int cc_list_length(comp_list_t* list)
{
    int i=0;
    comp_list_t *l = list;
    do
    {
        l=l->next;
        i++;
    }while(l!=NULL);
    return i;
}
