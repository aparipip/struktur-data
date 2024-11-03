#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *top = NULL;
int max = 5;
int count = 0;

void pushData(int data) 
{
    node *newNode;

    if (count == max) 
	{
        printf("\nData gagal diinput dikarenakan data full!!!\n");
    } 
	else 
	{
        newNode = (node*)malloc(sizeof(node));
        newNode->data = data;     
        newNode->next = top;
        top = newNode;
        count++;
        printf("\nData berhasil ditambahkan\n");
    }
}

void popData() 
{
    node *temp;

    if (count == 0) 
	{
        printf("\nData kosong!!!\n");
    } 
	else 
	{
        temp = top;
        top = top->next;
        free(temp);
        count--;
        printf("\nData paling atas berhasil dihapus\n");
    }
}

void topData() 
{
    if (count == 0) 
	{
        printf("\nData kosong!!!\n");
    } 
	else 
	{
        printf("\nAngka paling atas: %d\n", top->data);   
    }
}

void displayData() 
{
    node *temp;

    if (count == 0) 
	{
        printf("\nData kosong!!!\n");
    } 
	else 
	{
        temp = top;
        while (temp != NULL) 
		{
            printf("Angka: %d\n", temp->data);   
            temp = temp->next;
        }
    }
}

int countData() 
{
    return count;
}

int main() 
{
    int pilih, data;

    do {
    	system("cls");
        printf("=====================\n");
        printf("    Program Stack    \n");
        printf("=====================\n");
        printf("1. Push data\n");
        printf("2. Pop data\n");
        printf("3. List data\n");
        printf("4. Top data\n");
        printf("5. Count data\n");
        printf("6. Exit program\n");
        printf("\nPilih menu: ");
        scanf("%d", &pilih);
        getchar();  

        switch (pilih) {
            case 1:
                printf("Masukkan data (integer): ");
                scanf("%d", &data);
                getchar();  
                pushData(data);
                break;
            case 2:
                popData();
                break;
            case 3:
                displayData();
                break;
            case 4:
                topData();
                break;
            case 5:
                printf("\nBanyak Data: %d\n", countData());
                break;
            case 6:
                printf("\nTerima kasih telah menggunakan program ini\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();

    } while (pilih != 6);

    return 0;
}


