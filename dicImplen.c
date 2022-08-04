#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure of the Dictionary
struct dict
{
    struct dict *left, *right;
    char word[128], meaning[256];
};

struct dict *root = NULL; // root node is NULL because initially the BST is empty

// functions used in the Dictionary
void Insert(char *word, char *meaning);
void Search(char *str);
void Traversal(struct dict *node);
struct dict *createNode(char *word, char *meaning);

// Main function / Driver program
int main()
{
    printf("\nWelcome to Ayushman's dictionary!\n");
    printf("*************************************");
    printf("\n");
    int choice;
    char str[128], meaning[256];
    while (1)
    {
        printf("Please enter your choice\n");
        printf(" 1.Insert\n 2.Search\n 3.View \n 4.Exit\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            printf("Word to insert: ");
            fgets(str, 100, stdin);
            printf("Meaning : ");
            fgets(meaning, 256, stdin);
            Insert(str, meaning);
            break;
        case 2:
            printf("Word to Search: ");
            fgets(str, 100, stdin);
            Search(str);
            break;
        case 3:
            Traversal(root);
            break;
        case 4:
            exit(0);
        }
    }

    return 0;
}

// creating node for every word
struct dict *createNode(char *word, char *meaning)
{
    struct dict *NewNode;
    NewNode = (struct dict *)malloc(sizeof(struct dict));
    strcpy(NewNode->word, word);
    strcpy(NewNode->meaning, meaning);
    NewNode->left = NewNode->right = NULL;
    return NewNode;
}

// inserting a word with a meaning
void Insert(char *word, char *meaning)
{
    int resVar = 0;                                               // a temporary variabe to store the comparision result
    struct dict *parent = NULL, *current = NULL, *newNode = NULL; // initialising 3 dict type structures
    if (!root)
    {
        root = createNode(word, meaning); // if no root exists, create a new node & make that node root;
        return;
    }
    // if root exists
    for (current = root; current != NULL; current = (resVar > 0) ? current->right : current->left)
    {
        resVar = strcasecmp(word, current->word);
        if (resVar == 0)
        {
            printf("\nWord already exists!\n");
            return;
        }
        parent = current;
    }
    newNode = createNode(word, meaning);
    resVar > 0 ? (parent->right = newNode) : (parent->left = newNode); /*init the current with root node, depending upon the resVar(comparision result) , take the word to be added to left or right, if the word will be same resVar will be zero*/
    return;
}

// search function
void Search(char *str)
{
    int flag = 0, res = 0;
    struct dict *node = NULL;
    if (root == NULL)
    {
        printf("\nThe dictionary is empty!\n");
        return;
    }
    node = root;
    while (node)
    {
        if ((res = strcasecmp(node->word, str)) == 0)
        {
            printf("\nWord : %s\n", str);
            printf("Meaning : %s", node->meaning);
            flag = 1;
            break;
        }
        node = (res > 0) ? node->left : node->right;
    }
    if (!flag)
        printf("\nSearch element not found!\n");
    return;
}

// traversing the tree (dictionary) using inorder traversal
void Traversal(struct dict *node)
{
    if (node != NULL)
    {
        Traversal(node->left);
        printf("Word : %s\n", node->word);
        printf("Meaning : %s\n", node->meaning);
        Traversal(node->right);
    }
    return;
}




