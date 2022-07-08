#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

typedef struct node{
    int data;
    struct node* next;
} node;

typedef struct args{
    int data;
    node* head;   
} Lista;


void print_list(node* head){
    node* cursor = head;
    while (cursor != NULL)
    {
        printf("%d ", cursor->data);
        cursor = cursor->next;
    }
}

node* create(int data, node* next){
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL){
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->data = data;
    new_node->next = next;

    return new_node;
}


node* append(Lista* args){
    /* go to the last node */
    node* cursor = args->head;
    while (cursor->next != NULL)
        cursor = cursor->next;

    /* create a new node */
    node* new_node = create(args->data, NULL);
    cursor->next = new_node;

    return args->head;
}

node* remove_front(node* head){
    if (head == NULL)
        return NULL;
    node* front = head;
    head = head->next;
    front->next = NULL;
    /* is this the last node in the list */
    if (front == head)
        head = NULL;
    free(front);
    return head;
}

node* remove_back(node* head){
    if (head == NULL)
        return NULL;

    node* cursor = head;
    node* back = NULL;
    while (cursor->next != NULL){
        back = cursor;
        cursor = cursor->next;
    }
    if (back != NULL)
        back->next = NULL;

    /* if this is the last node in the list*/
    if (cursor == head)
        head = NULL;

    free(cursor);

    return head;
}

int main(void) {
    // inserte código para agregar 100 nodos
    node* head = create(100, NULL);
    
    // primero secuencialmente (usando un ciclo)
    Lista* args=(Lista*)malloc(sizeof(Lista));
    for(int i=0;  i< 100; i++){
       args->head=head;
       args->data=i;
       append(args);
    }
    printf("Secuencialmente: \n");
    print_list(head);

    //Vaciando la lista
    for(int i=0;i<100;i++){
        if(head==NULL){
           break;
        }
        head=remove_front(head);
    }
    // luego en paralelo
    // Creando el arreglo threads y aplicando semaforos
    pthread_t threads[100];
    sem_t mutex;
    sem_init(&mutex,0,1);
    for (int i = 0; i < 100; i++) {
        sem_wait(&mutex);
        args->head=head;
        args->data=i;
        pthread_create(&threads[i], NULL, (void*)append, (void*)args);
        pthread_join(threads[i],NULL);
        sem_post(&mutex);
    }
    printf("\nParalelo: \n");
    print_list(head);
    return 0;
}