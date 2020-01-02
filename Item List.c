/*
    author Ariya Rasekh <ariya.rasekh@gmail.com>
    ItemInsertion
    this program as for user to enter items and make list of them using Linked list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node for each Item
typedef struct ProductDescription{
    
    char productName [25];
    float productPrice;
    float  productWeight;
    struct ProductDescription *next;   //pointer to next node
    
}ProductNode;


//Check if the node is Empty
void CreateEmptyProductList(ProductNode **head)
{
    *head = NULL;
}

//Set product into node
ProductNode * SetProductInfo()
{
    ProductNode *product;
    
    product = (ProductNode *) malloc(sizeof(ProductNode));
    
    //getting Name
    printf("\nPlease Enter the ProductNode Name: ");
    scanf(" %[^\n]s", product->productName);
    
    //getting price
    printf("\nPlease Enter the ProductNode Price: ");
    scanf(" %f", &product->productPrice);
    
    //getting Weight
    printf("\nPlease Enter the ProductNode Weight: ");
    scanf(" %f", &product->productWeight);
    
    //Last node points to NULL
    product->next = NULL;
    return product;
}


//Inserting Product at the Head
void InsertProductAtHead(ProductNode **head){
    
    ProductNode * productInfo = SetProductInfo();
    if(*head==NULL)
        *head=productInfo;
    else
    {
        productInfo->next = *head;
        *head=productInfo;
    }
}


//Inserting Product at the End
void InsertProductAtEnd(ProductNode **head)
{
    if (*head==NULL) {
        InsertProductAtHead(head);
        return;
    }
    
    else{
        ProductNode * productInfo = SetProductInfo();
        ProductNode * Current;
        Current=*head;
        
    while (Current != NULL)
    {
        Current = Current->next;
    }
        
        Current=productInfo;
    }
    
}

//Printing all products Using While loop
void PrintProductList(ProductNode *head)
{
    
    ProductNode *current_node = head;
    while ( current_node != NULL)
    {
        printf("%s \n", current_node->productName);
        printf("%f \n", current_node->productPrice);
        printf("%f \n", current_node->productWeight);
        printf("--------------------------------------\n");
        current_node = current_node->next;
    }
    
}

//Printing Nodes recursively
void PrintProductListRec(ProductNode *head)
{
    ProductNode *current_node = head;
    if ( current_node != NULL)
    {
        printf("%s \n", current_node->productName);
        printf("%f \n", current_node->productPrice);
        printf("%f \n", current_node->productWeight);
        printf("--------------------------------------\n");
        current_node = current_node->next;
    }
    
    if ( current_node == NULL)          // base Case
        return;
    
    PrintProductListRec(head->next);    // printing next node
}

//removing Items and releasing the memory used for them
void ClearProductList(ProductNode **head)
{
    ProductNode * product=*head;
    *head=(*head)->next;
    free(product);
    while ( product != NULL)
    {
        free(product);
        product = product->next;
    }
    
}

int main() {
    
    printf("\n");
    int choice;     //used for user's option
    
    ProductNode *head;
    CreateEmptyProductList(&head);

    do{
        
        //printing out the options
        printf("Please choose from following options or any other keys to exit\n");
        printf("1 to add Item at begining of the list\n");
        printf("2 to add Item at end of the list\n");
        printf("3 to print Item List\n");
        printf("4 to clear Item List\n");
        scanf("%d",&choice);
        
        switch (choice) {
            case 1:
                InsertProductAtHead(&head);
                break;
            
            case 2:
                InsertProductAtEnd(&head);
                break;
                
            case 3:
                PrintProductList(head);
                break;
                
            case 4:
                CreateEmptyProductList(&head);
                printf("List had been cleared\n");
                break;
                
            default:
                exit(0);
                break;
        }
    }
    
    while(1);
    
    return 0;
}
