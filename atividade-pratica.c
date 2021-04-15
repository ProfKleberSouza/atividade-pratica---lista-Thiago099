#include <stdio.h>
#include "list.h"

int main()
{
    list * l=create_list();
    add(l,create_product("teste",0,0));
    add(l,create_product("teste",0,0));
    add(l,create_product("teste",0,0));
    remove_start(l);
    remove_end(l);
    //remove_by_id(l,2);
    print(l);
    return 0;
}
