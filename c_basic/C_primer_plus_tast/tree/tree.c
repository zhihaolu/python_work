/* tree.h --二叉查找数          */
/*          树种不允许有重复的项 */
#ifndef _TREE_H_
#define _TERR_H_
#include<stdbool.h>

/* 根据具体情况重新定义 Item */
#define SLEN 20
typedef struct item{
    char petname[SLEN];
    char petkind[SLEN];
} Item;

typedef struct