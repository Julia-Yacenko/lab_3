#include <fstream>
#include"class.h"

using namespace std;

int main(int argc, char * argv[]){
	if(argc!=2){
		cout << "ОШИБКА" << endl;
		return 0;
	}
	cout << "Вы ввели файл " << argv[1] << endl;
	fstream f1(argv[1], ios::in);
	if(!f1){
		cout << "ОШИБКА" << endl;
		return 0;
	}
	int n;
	f1 >> n;
	int tmp1, tmp2;
	string str;
	bakery * array = new bakery[n];
	for(int i = 0; i < n; i++){
		getline(f1, str);
		array[i].setName(str);
		f1 >> tmp1;
		array[i].setWeight(tmp1);
		f1 >> tmp2;
		array[i].setPrice(tmp2);
/*			f1 >> array[i].setName();
			f1 >> array[i]._weight();
			f1 >> array[i]._price();*/
	}
	f1.close();

	cout << "Пекарня" << endl << "1.Посмотреть меню" << endl << "2.Добавить изделие" << endl << "3.Убрать изделие из меню" << endl << "4.Выбрать изделие по цене" << endl << "5.Выбрать изделие по массе" << endl << "6.Найти изделие по названию" << endl << "7.Выход" << endl;
	int c;
	cin >> c;

	Menu m;
	while(c != 7){
		switch(c){
		case 1:
			m.printAll(n, array);
			break;
		case 2:
			int* k;
			k = &n;
			m.push(k, array);
			n = *k;
	        	break;
		case 3:
			int* w;
			w = &n;
			m.del(k, array);
			n = *w;
	        	break;
		case 4:
			m.find1(n, array);
	        	break;
		case 5:
			m.find2(n, array);
	        	break;
		case 6:
			m.find3(n, array);
	        	break;
		cin >> c;
		}
	}

	fstream f(argv[1], ios::out);
	for(int i = 0; i < n; i++){
		f << array[i]._name();
		f << array[i]._weight();
		f << array[i]._price();
	}
	f.close();
	delete [] array;
	return 0;
}
