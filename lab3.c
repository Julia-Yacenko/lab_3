#include<stdio.h>
#include<stdlib.h>
#include"struct.h"

int main(int argc, char * argv[]){
	if(argc!=2){
		printf("ОШИБКА \n");
		return 0;
	}
	printf("Вы ввели файл %s \n", argv[1]);
	FILE *fIn;
	if((fIn=fopen(argv[1], "r")) == NULL){
		printf("ОШИБКА \n");
		return 0;
	}
	int n;
	fscanf(fIn, "%d", &n);
	bakery * array = (bakery*)malloc(sizeof(bakery)*n);
	for(int i = 0; i < n; i++){
		fgets(array[i].name, 40, fIn);
		fscanf(fIn, "%d", &array[i].weight);
		fscanf(fIn, "%d", &array[i].price);
	}
	fclose(fIn);

	printf("Пекарня \n 1.Посмотреть меню \n 2.Добавить изделие \n 3.Убрать изделие из меню \n 4.Выбрать изделие по цене \n 5.Выбрать изделие по массе \n 6.Найти изделие по названию \n 7.Выход \n");
	int c;
	scanf("%d", &c);

	while(c != 7){
		if(c == 1){
			printAll(n, array);
		}
		if(c == 2){
			int* k;
			k = &n;
			push(k, array);
			n = *k;
	        }
		if(c == 3){
			int* k;
			k = &n;
			del(k, array);
			n = *k;
	        }
		if(c == 4){
			find1(n, array);
	        }
		if(c == 5){
			find2(n, array);
	        }
		if(c == 6){
			find3(n, array);
	        }
		scanf("%d", &c);
	}

	fIn=fopen(argv[1], "w");
	for(int i = 0; i < n; i++){
		fputs(array[i].name, fIn);
		fprintf(fIn, "%d\n", array[i].weight);
		fprintf(fIn, "%d\n", array[i].price);
	}
	fclose(fIn);
	free(array);
	return 0;
}
