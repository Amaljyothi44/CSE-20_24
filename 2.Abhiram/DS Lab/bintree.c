#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *right_child;
	struct node *left_child;
};

struct node* search(struct node *root,int x){
	if(root==NULL||root->data==x){
		return root;
	}else if(x>root->data){
		return search(root->right_child,x);
	}else{
		return search(root->right_child,x);	
	}
}

struct node* find_minimum(struct node* root){
	if(root == NULL){
        	return NULL;
	}
    	else if(root->left_child != NULL){
        	return find_minimum(root->left_child);
	}
    	return root;
}

struct node* new_node(int x)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

struct node* insert(struct node *root, int x)
{
    if(root==NULL)
        return new_node(x);
    else if(x>root->data) 
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child,x);
    return root;
}

struct node* delete(struct node *root, int x)
{

    if(root==NULL)
        return NULL;
    if (x>root->data)
        root->right_child = delete(root->right_child, x);
    else if(x<root->data)
        root->left_child = delete(root->left_child, x);
    else
    {
        if(root->left_child==NULL && root->right_child==NULL)
        {
            free(root);
            return NULL;
        }

        else if(root->left_child==NULL || root->right_child==NULL)
        {
            struct node *temp;
            if(root->left_child==NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            free(root);
            return temp;
        }

        else
        {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data);
        }
    }
    return root;
}

void inorder(struct node *root)
{
    if(root!=NULL)
    {
        inorder(root->left_child); 
        printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

int main()
{
	struct node *root=NULL;
	int choice=0,x;
	while(choice!=4){
		printf("\nSelect operation\n1.Insert\n2.Delete\n3.Inorder\n4.Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1 : printf("\nEnter data: ");
				 scanf("%d",&x);
				 root = insert(root,x);
				 break;
			case 2 : printf("\nEnter data to delete: ");
				 scanf("%d",&x);
				 root = delete(root,x);
				 break;
			case 3 : inorder(root);
				 break;
			case 4 : return 0;
			default : printf("Enter valid option!");
		}
		printf("\n");
	}
	return 0;
}

