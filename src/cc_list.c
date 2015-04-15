#include "cc_list.h"
#include <stdlib.h>

comp_list_t* cc_list_create(comp_tree_item_t* item)
{
    comp_list_t* list = (comp_list_t*) malloc(sizeof(comp_list_t*));
    list->item = item;
    list->next = NULL;
    return list;
}

void cc_list_append(comp_list_t* list, comp_list_t* item)
{
    comp_list_t *l = list;
    do
    {
        l=l->next;

    }while(l->next!=NULL);
    l->next = item;
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
