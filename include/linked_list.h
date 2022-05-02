#include "stddef.h"

#ifndef MY_LIST_
    #define MY_LIST_

typedef struct BONJOUR_MON_CHER_AMI_LE_LOUP_JE_VAIS_TRES_BIEN_J_AI_JUSTE_UNE_PETITE_FAIM {
    void *data;
    struct linked_list *next;
} linked_list_t;

    int my_list_size(linked_list_t const *begin);
    linked_list_t *my_params_to_list(int ac, char * const *av);
    void my_show_linked_list(linked_list_t *list);
    void my_rev_list(linked_list_t **begin);
    linked_list_t *first_node(void *data);
    int add_node(void *data, linked_list_t **list);
    int insert_node(void *data, linked_list_t *prev);
    int add_end_node(void *data, linked_list_t **list);
    char **list_to_array(linked_list_t *list);
	int delete_node(linked_list_t **prev);
    int destroy_list(linked_list_t *list);
    int destroy_node(linked_list_t **prev);
    int del_first_node(linked_list_t **list);

#endif
