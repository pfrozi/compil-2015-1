#ifndef __LIST_H_
#define __LIST_H_

typedef struct comp_list
{
    int type;
    struct comp_list* next;
} comp_list_t;

comp_list_t* cc_list_create(int type);
comp_list_t* cc_list_append(comp_list_t* list, comp_list_t* item);
void cc_list_remove(comp_list_t* list, comp_list_t* item);
comp_list_t* cc_list_get(comp_list_t* list,int n);
int cc_list_length(comp_list_t* list);

#endif
