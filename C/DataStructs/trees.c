#include <stdio.h>
#include <stdlib.h>

// nodes for a general tree. Can handle an *unlimited* amount of children relationships
typedef struct TreeNode {
    int data; 
    struct TreeNode *child; 
    struct TreeNode *sibling; 
}TreeNode; 

// node of a queue, which consists of a treenode
typedef struct QueueNode {
    TreeNode *node; 
    struct QueueNode *next; 
}QueueNode; 

// the actual queue, keeps track of the front and rear queue nodes
typedef struct {
    QueueNode *front; 
    QueueNode *rear; 
}Queue;

// node of a stack consists of a tree node
typedef struct StackNode {
    TreeNode *node; 
    struct StackNode *next; 
}StackNode; 

// the actual stack, only keeps track of the top of the stack 
typedef struct {
    StackNode *top; 
}Stack; 

/// ---------- Stack functions --------------
Stack *createStack() {
    Stack *s = (Stack *)malloc(sizeof(Stack)); 
    if(!s) return NULL; 
    s->top = NULL; 
    return s; 
}

int isEmpty_s(Stack *s){
    return s->top == NULL; 
}

void addStack(Stack *s, TreeNode *node){
    if(!s && !node){
        printf("No valid stack or node to add\n"); 
        return;
    }
    StackNode *new_node = (StackNode *)malloc(sizeof(StackNode)); 
    if(!new_node) return; 
    new_node->node = node; 
    new_node->next = NULL;
    if(!isEmpty_s(s)){
        StackNode *temp = s->top; 
        s->top = new_node;
        new_node->next = temp; 
        return; 
    }
    s->top = new_node; 
}

TreeNode *popStack(Stack *s){
    if(!s) return NULL; 
    if(!isEmpty_s(s)) {
        StackNode *temp = s->top; 
        TreeNode *temp_node = temp->node;
        s->top = s->top->next; 
        free(temp); 
        return temp_node;  
    }
    printf("Stack is empty.\n"); 
    return NULL; 
}


// -------------- Queue Functions ----------------
Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue)); 
    if(!q) return NULL; 
    q->front = q->rear = NULL; 
    return q; 
}

int isEmpty(Queue *q) {
    return q->rear == NULL; 
}

void enqueue(Queue *q, TreeNode *node) {
    if (!q && !node) return; 
    QueueNode * new_node = (QueueNode *)malloc(sizeof(QueueNode)); 
    new_node->node = node; 
    new_node->next = NULL; 
    if(isEmpty(q)){
        q->front = q->rear = new_node; 
    }
    else {
        q->rear->next = new_node; 
        q->rear = new_node; 
    }
    
}

TreeNode *dequeue(Queue *q) {
    if(!q) return NULL; 
    QueueNode *temp = q->front; 
    TreeNode *node = temp->node; 
    q->front = q->front->next; 
    if(!q->front) q->rear = NULL; 
    free(temp); 
    return node; 

}

// -------------- Tree Functions ------------------
TreeNode *createNode(int value) {
    TreeNode *new_node = (TreeNode *)malloc(sizeof(TreeNode)); 
    if (!new_node) return NULL; 
    new_node->data = value; 
    new_node->child = NULL; 
    new_node->sibling = NULL; 

    return new_node; 
}

void addChild(TreeNode *root, TreeNode *child) {
    if (!root && !child){
        printf("No valid root or child.\n");
        return; 
    }
    printf("Adding child: %d to root: %d\n", child->data, root->data); 
    if(!root->child) {
        root->child = child; 
    }
    else{
        // treversing root's child siblings to place new child at the end
        TreeNode *temp = root->child; 
        while(temp->sibling) {
            temp = temp->sibling; 
        }
        temp->sibling = child; 
    }
}
// ------------ Breadth First Search -----------------
// Looks for a key value, which returns once found. 
void bfs(TreeNode *root, int value) {
    if(!root) return;
    Queue *path = createQueue(); 
    enqueue(path, root); 

    while(!isEmpty(path)){
        TreeNode *current = dequeue(path); 
        printf("%d, ", current->data); 
        if(current->data == value){
            printf("Found value: %d\n", current->data); 
            free(path); 
            return; 
        }

        TreeNode *child = current->child; 
        while(child) {
            enqueue(path, child); 
            child = child->sibling;  
        }
    }
    free(path); 
}

// ---------------- Depth First Search -------------------
// Looks for a given value, then returns 
void dfs(TreeNode *root, int value){
    if (!root){ return; }
    Stack *s = createStack();
    addStack(s, root);

    while(!isEmpty_s(s)){
        TreeNode *current = popStack(s); 
        printf("%d ,", current->data); 
        if(current->data == value){
            printf("Found value: %d\n", current->data); 
            free(s); 
            return; 
        }
        TreeNode *child = current->child;
        while(child){
            addStack(s, child);
            child = child->sibling; 
        }

    }
    free(s); 
}


// Tree to simulate: 
//               10
//            /  |  \
//           15  20  25
//          / \   |   \
//         30  35 40  45

int main(void) {
    TreeNode *root = createNode(10); 

    TreeNode *b = createNode(15); 
    TreeNode *c = createNode(20); 
    TreeNode *d = createNode(25); 

    addChild(root, b); 
    addChild(root, c); 
    addChild(root, d);

    addChild(b, createNode(30)); 
    addChild(b, createNode(35)); 
    addChild(c, createNode(40)); 
    addChild(d, createNode(45)); 

    printf("BFS Traversal: \n"); 
    bfs(root, 40); 
    printf("DFS Traversal: \n"); 
    dfs(root, 40); 
    return 0; 

}
