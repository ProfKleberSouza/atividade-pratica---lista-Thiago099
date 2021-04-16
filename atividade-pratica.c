
#include <windows.h>
#include "list.h"
#include "io.h"
product request_product()
{
    return create_product(request("Descrição:"),request_float("Valor:"),request_int("Quantidade:"));
}
int main()
{
    
    list * l=create_list();
    
    while (1)
    {
        system("cls");
        switch (request_int("Menu\n1 Cadastrar produto\n2 Atualizar produto\n3 Deletar produto\n4 Exibir lista\n5 Exibir produto\n6 Limpar\n>"))
        {
            case 1:
                add(l,request_product());               
            break;
            case 2:
                edit(l,request_int("id do produto:"),request_product());
                break;
            case 3:
                remove_by_id(l,request_int("id do produto a ser removido:"));
                break;
            case 4:
                print(l);
                break;
            case 5:
                print_product(get_by_id(l,request_int("id do produto a ser exibido:")));
                break;
            case 6:
                clear(l);
                l=create_list();
                break;
        }
    }
    
    

    return 0;
}
