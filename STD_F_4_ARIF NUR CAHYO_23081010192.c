/*
Nama	: Arif Nur Cahyo
Kelas	: Struktur Data (F)
NPM	: 23081010192
*/

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

bool isFull() 
{
    if (count == max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isEmpty() 
{
    if (count == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

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

void destroyData() 
{
	char confirm;
	
	if (isEmpty()) 
	{
        printf("\nData kosong!!!\n");
    }
    else
    {
    	printf("\nApakah Anda yakin ingin menghapus keseluruhan data? (y/n): ");
    	scanf("%c", &confirm);
    	getchar();
    	
        if (confirm == 'y' || confirm == 'Y') 
		{
			while (!isEmpty()) 
			{
    		    popData();
    		}
    		printf("\nKeseluruhan data berhasil dihapus.\n");
        }
        else
        {
        	printf("\nData batal dihapus.\n");
		}
	}
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
        printf("6. Data is Empty?\n");
        printf("7. Data is Full?\n");
        printf("8. Destroy data\n");
        printf("9. Exit program\n");
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
                printf("\nApakah data kosong? %s\n", isEmpty() ? "Ya" : "Tidak");
                break;
            case 7:
                printf("\nApakah data penuh? %s\n", isFull() ? "Ya" : "Tidak");
                break;
            case 8:
                destroyData();
                break;
            case 9:
                printf("\nTerima kasih telah menggunakan program ini\n");
                break;
            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
        }

        printf("\nPress Enter to continue...");
        getchar();

    } while (pilih != 9);

    return 0;
}


