struct node {
    int data;
    struct node* next;
};

typedef struct node* NODE;

NODE createNode(int x) {
    //write your code here..
	NODE temp = (NODE)malloc(sizeof(struct node));
    if (temp == NULL) {
        return NULL;
    }
    temp->data = x;
    temp->next = NULL;
    return temp;
}

NODE addNode(NODE first, int x) {
    //write your code here..
     NODE temp = createNode(x);
    if (temp == NULL) {
        return first;
    }

    if (first == NULL) {
        return temp;
    }

    NODE curr = first;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = temp;

    return first;
 
}

NODE concatenate(NODE t1, NODE t2) {
    //write your code here..
    if (t1 == NULL) {
        return t2;
    }

    NODE curr = t1;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = t2;

    return t1;
    
    
    
}

void displayList(NODE first) {
    NODE curr = first;
    while (curr != NULL) {
        printf("%d --> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
    
    
    
}
