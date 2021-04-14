#include "struct.h"

void printAll(int a, bakery* array){
	for(int i = 0; i < a; i++){
		printf("\n Изделие: %s Масса: %d\n Цена: %d\n", array[i].name, array[i].weight, array[i].price);
	}
}

void push(int * a, bakery* array){
	bakery* new_array = (bakery*)malloc(sizeof(bakery)*(*a+1));
	for(int j = 0; j < *a; j++){
		new_array[j] = array[j];
	}
	printf("Введите название изделия");
	char z[40];
	scanf("%s", z);
	strcpy(new_array[*a].name, z);
	printf("Введите массу изделия в граммах");
	int m;
	scanf("%d", &m);
	new_array[*a].weight = m;
	printf("Введите цену изделия в рублях");
	int t;
	scanf("%d", &t);
	new_array[*a].price = t;
	*a = *a+1;
	free(array);
	array = new_array;
}

void del(int *a, bakery* array){
	printf("Введите номер изделия, которое нужно удалить");
	int index;
	scanf("%d", &index);
	for(int i = index-1; i < (*a-1); i++){
		array[i] = array[i+1];
	}
	*a = *a-1;
}

bakery * find1(int a, bakery* array){
	char z[40];
	printf("Введите название для поиска");
	scanf("%s", z);
	for(int j = 0; j < a; j++){
		if(strcmp(z, array[j].name) == 0){
			printf("\n Изделие: %s Масса: %d\n Цена: %d\n", array[j].name, array[j].weight, array[j].price);
			break;
		}
	}
}

bakery * find2(int a, bakery* array){
        int m;
        printf("Введите массу для поиска");
        scanf("%d", &m);
        for(int j = 0; j < a; j++){
                if(m == array[j].weight){
                        printf("\n Изделие: %s Масса: %d\n Цена: %d\n", array[j].name, array[j].weight, array[j].price);
                }
        }
}

bakery * find3(int a, bakery* array){
        int t;
        printf("Введите цену для поиска");
        scanf("%d", &t);
        for(int j = 0; j < a; j++){
                if(t == array[j].price){
                        printf("\n Изделие: %s Масса: %d\n Цена: %d\n", array[j].name, array[j].weight, array[j].price);
                }
        }
}


