#ifndef CLASSES_H
#define CLASSES_H
#include <string>
#include <iostream>

using namespace std;

class bakery{
private:
	string name;
	int weight;
	int price;
public:
	bakery();
	~bakery();

	string _name();
	int _weight();
	int _price();

	void setName(string n);
	void setWeight(int w);
	void setPrice(int p);
};

class Menu{
private:
	bakery *array;
public:
	void printAll(int a, bakery* array);
	void push(int * a, bakery* array);
	void del(int * a, bakery* array);
	void find1(int a, bakery* array);
	void find2(int a, bakery* array);
	void find3(int a, bakery* array);
};
#endif // CLASSES_H
