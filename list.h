
typedef struct product {
    int id;
    char description[255];
    float value;
    int quanitity;
}product;

typedef struct node {
    product value;
    struct node * next;
    struct node * previous;
}node;

typedef struct list {
    node * first;
    node * last;
    int length;
}list;


list * create_list();

node * create_node();

product create_product(char * description,float value,int quanitity);

void add(list * l,product p);

void add_start(list * l,product p);

product get_by_id(list * l,int id);



void print_product(product p);

void print(list * l);

product remove_start(list * l);

product remove_end(list * l);

int count(list * l);

product remove_by_id(list * l,int id);

void edit(list * l,int id,product p);

void clear(list * l);