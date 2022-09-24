#pragma once
#include <iostream>
using namespace std;
template<typename T = int>
class MyArray
{
	T* arr;
	int size;//инициализированные значения
	int capacity;//весь размер
public:
	MyArray();
	MyArray(const T a);
	MyArray(const MyArray& a);
	MyArray& operator=(const MyArray<T>& a);
	int GetSize()const;
	int GetCap()const;
	void SetSize(int _size, int grow = 1);
	int GetUpperBound()const;
	bool IsEmpty()const;
	void FreeExtra();
	void RemoveAll();
	T GetAt(int num)const;
	void SetAt(const T a, int index);
	T& operator[](int index);
	void Add(T a);
	MyArray<T>& Append(const MyArray<T> obj);
	T* GetData();
	void InsertAt(int index, const T& val , int positions=1);//positions - сколько значений проинициализировать новым занчением
	void RemoveAt(int index, int positions = 1);
	~MyArray();
};

template<class T>
MyArray<T>::MyArray() {
	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<class T>
MyArray<T>::MyArray(const T a) {
	size++;
	capacity++;
	arr = new T[1];
	arr[0] = a;
}

template<class T>
MyArray<T>::MyArray(const MyArray& a) {
	size = a.size;
	capacity = a.capacity;
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++) {
		arr[i] = a.arr[i];
	}
}

template<class T>
int MyArray<T>::GetSize()const {
	return size;
}

template<class T>
int MyArray<T>::GetCap() const {
	return capacity;
}

template<class T>
void MyArray<T>::SetSize(int _size, int grow) {
	while (_size < 0) {
		cout << "wrong size\nenter size again\n";
		cin >> _size;
	}
	while (grow < 0) {
		cout << "wrong grow\nenter grow again\n";
		cin >> grow;
	}
	if (_size < capacity) {
		T* buf = new T[_size];
		for (int i = 0; i < _size; i++) {
			buf[i] = arr[i];
		}
		delete[] arr;
		arr = new T[_size+1];
		size = _size;
		capacity = _size+1;
		for (int i = 0; i < _size; i++) {
			arr[i] = buf[i];
		}
		delete[] buf;
	}
	else {
		int n_size = _size + grow;
		T* buf = new T[n_size];
		for (int i = 0; i < size; i++) {
			*(buf+i) = arr[i];
		}
		delete[] arr;
		arr = new T[n_size];
		capacity = n_size;
		size = _size;
		for (int i = 0; i < _size; i++) {
			*(arr+i) = *(buf + i);
		}
		delete[] buf;
	}
}

template<class T>
int MyArray<T>::GetUpperBound() const {
	return size - 1;
}

template<class T>
bool MyArray<T>::IsEmpty()const {
	return size == 0 ? 1 : 0;
}

template<class T>
void MyArray<T>::FreeExtra() {
	if (capacity > size) {
		capacity = size;
		T* buf = new T[size];
		for (int i = 0; i < size; i++) {
			buf[i] = arr[i];
		}
		delete[] arr;
		arr = new T[size];
		for (int i = 0; i < size; i++) {
			arr[i] = buf[i];
		}
		delete[] buf;
	}
	else {
		return;
	}
}

template<class T>
void MyArray<T>::RemoveAll() {
	delete[] arr;
	size = capacity = 0;
}

template<class T>
T MyArray<T>::GetAt(int number) const {
	if (number >= 0 && number <= size) {
		return *(arr+number);
	}
	cout << "wrong index\n";
	return *arr;
}


template<class T>
void MyArray<T>::SetAt(const T a, int index) {
	if (index > size || index <=0) {
		cout << "wrong index\n";
		return;
	}
	arr[index - 1] = a;
}

template<class T>
T& MyArray<T>::operator[](int index) {
	return *(arr+index);
}

template<class T>
ostream& operator<<(ostream& os, MyArray<T>& a) {
	for (int i = 0; i < a.GetSize(); i++) {
		os << a[i] << " ";
	}
	os << "\n";
	return os;
}


template<class T>
void MyArray<T>::Add(T a) {
	SetSize(GetCap());
	arr[GetSize()-1] = a;
}

template<class T>
MyArray<T>& MyArray<T>::Append(const MyArray<T> obj) {
	for (int i = 0; i < size || i <obj.size; i++) {
		arr[i] += obj.GetAt(i);
	}
	return *this;
}

template<class T>
MyArray<T>& MyArray<T>::operator=(const MyArray<T>& obj)
{
	if (this == &obj) // a=a
	{
		return *this;
	}
	if (size != 0)
	{
		this->~MyArray();
	}
	size = obj.size;
	capacity = obj.capacity;
	arr = new T[obj.capacity];
	for (int i = 0; i < size; i++)
	{
		*(arr+i) = obj.arr[i];
	}
	return *this;
}

template <class T>
T* MyArray<T>::GetData() {
	return arr;
}

template<class T>
void MyArray<T>::InsertAt(int index, const T& val, int positions) {
	if (index+positions-1 >= size || index + positions - 1 < 0) {
		cout << "error\n";
		return;
	}
	for (int i = 0; i < positions; i++) {
		arr[index+i] = val;
	}
}

template<class T>
void MyArray<T>::RemoveAt(int index, int positions) {
	if (index + positions - 1 >= size || index + positions - 1 < 0) {
		cout << "error\n";
		return;
	}
	for (int i = 0; i < positions; i++) {
		arr[index + i] = NULL;
	}
}

template<class T>
MyArray<T>::~MyArray() {
	delete[]arr;
}