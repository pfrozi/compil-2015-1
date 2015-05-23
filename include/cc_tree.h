#ifndef _TREE_H_
#define _TREE_H_
#include "cc_dict.h"
#include "cc_operations.h"

typedef struct comp_tree_item
{
    int type;
    int iks_type;
    comp_dict_item_t* sentry;
    
    int               num_codes;
    iloc_code_t**     codes;
    iloc_code_t**     bf;
    iloc_code_t**     bv;

    char* result;
    
} comp_tree_item_t;

typedef struct comp_tree
{
    comp_tree_item_t* item;

    int num_children;
    struct comp_tree** children;
} comp_tree_t;

comp_tree_t* cc_tree_create_node(int numChildren, comp_tree_item_t* item);
void cc_tree_destroy_node(comp_tree_t* node);

comp_tree_item_t* cc_tree_item_create(int type,comp_dict_item_t* sentry);
comp_tree_item_t* cc_tree_item_create_type(int type, int iks_type, comp_dict_item_t* sentry);

comp_tree_t* cc_tree_insert_node(comp_tree_t* root,comp_tree_t* node);
void cc_tree_remove_node(comp_tree_t* root,comp_tree_t* node);
int cc_tree_num_children(comp_tree_t* node);
comp_tree_t* cc_tree_get_children(comp_tree_t* node,int child);

#endif
