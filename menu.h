#ifndef __MENU_H__
#define __MENU_H__

#include <string.h>
#include <stdio.h>
#include "list.h"

#define LOG_LIGHT 1
#define FONT_COLOR_GREEN 32
#define LOG_NONE 0
#define CC_NONE CC(LOG_NONE)
#define _CC_(arg...) "\033["#arg"m"
#define __CC__(arg...) _CC_(arg)
#define CC(arg...) __CC__(arg)

#define MLOG(fmt,arg...) printf(CC(LOG_NONE;FONT_COLOR_GREEN;LOG_LIGHT)fmt""CC_NONE,##arg);
#define MLOGI(fmt,arg...) printf(CC(LOG_NONE;FONT_COLOR_RED)fmt""CC_NONE,##arg);

#define MAX_LEVEL 10
#define LEVEL(level_val,name_val,action_val) { .level = level_val, .name = name_val , .action = action_val },
#define ADD_MENU(a) add_menu(a,sizeof(a)/sizeof(a[0]))

typedef int (*menu_func)(void *);
typedef struct menu_node_item{
    menu_func action;
    int level;
    int index;
    char *name;
    struct list_head list; 
} menu_node_item_t;

void init_menu();
void add_menu(menu_node_item_t items[],int length);
void run_menu();

int default_action(void *e);
void print_menu();

extern int current_level; 
extern menu_node_item_t header; 

#endif
