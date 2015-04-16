#include "cc_tree.h"
#include "cc_gv.h"
#include <stdlib.h>
#include <stdio.h>

comp_tree_t* cc_tree_create_node(int numChildren, comp_tree_item_t* item)
{
    comp_tree_t* node = (comp_tree_t*)malloc(sizeof(comp_tree_t));
    node->children = (comp_tree_t**)malloc(sizeof(comp_tree_t*)*numChildren);
    node->num_children = numChildren;
    node->item = item;

    //gv stuff
    if(item->sentry!=NULL)
    {
        gv_declare(item->type,node,item->sentry->key.lexem);
    }
    else
    {
        gv_declare(item->type,node,NULL);
    }
    return node;
}

void cc_tree_destroy_node(comp_tree_t* node)
{
}

comp_tree_item_t* cc_tree_item_create(int type,comp_dict_item_t* sentry)
{
    comp_tree_item_t* item = (comp_tree_item_t*)malloc(sizeof(comp_tree_item_t));
    item->type = type;
    item->sentry = sentry;

    return item;
}

comp_tree_t* cc_tree_insert_node(comp_tree_t* root,comp_tree_t* node)
{
    if(node!=NULL)
    {
        int i=0;
        for(i=0;i<root->num_children;i++)
        {
            if(root->children[i]==NULL)
            {
                root->children[i]=node;
            }
        }
        gv_connect(root,node);
    }
    return root;
}

void cc_tree_remove_node(comp_tree_t* root,comp_tree_t* node)
{
}

int cc_tree_num_children(comp_tree_t* node)
{
    return node->num_children;
}

comp_tree_t* cc_tree_get_children(comp_tree_t* node,int child)
{
}

