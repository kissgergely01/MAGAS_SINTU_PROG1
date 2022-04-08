#include <iostream>
#include <stdexcept>
#include <array>
#include <algorithm>
#include <string>
#include <vector>
#include <list>

template <typename C>
void print(const C& c){
	for(auto& elem : c)
		std::cout << elem << ", ";
	std::cout << endl;
}
template <typename C>
void ereknoveles(C& c, int n){
	for(auto& elem : c)
		elem+=n;
}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p!=e1;++p){
		*f2=*f1;
		f2++;
	}
	return f2;
}
int main(){
	constexpr int size = 10;
	int arr[size];
	for(int i=0;i<size;i++) arr[i]=i;
	
	std::array<int,size> ai;
	std::copy(arr,arr+size,ai.begin());
	std::cout << "std array: ";
	print(ai);

	std::vector<int> vi(size);
	std::copy(arr,arr+size,vi.begin());
	std::cout << "std vector: ";
	print(vi);
	
	std::list<int> li(size);
	std::copy(arr,arr+size,li.begin());
	std::cout << "std list: ";
	print(li);
	
	std::array<int,size> ai2=ai;
	std::vector<int> vi2=vi;
	std::list<int> li2=li;
	
	print(ai2);
	print(vi2);
	print(li2);
	
	inc(ai2, 2);
	inc(vi2, 3);
	inc(li2, 5);
	
	print(ai2);
	print(vi2);
	print(li2);
	
	my_copy(ai2.begin(), ai2.end(), vi2.begin());
	my_copy(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(vi2);
	print(li2);

	std::vector<int>::iterator vit;
	vit = std::find(vi2.begin(), vi2.end(), 3);
	if( vit != vi2.end()){
		std::cout << "Found at: " << std::distance(vi2.begin(), vit) << std::endl;
	}else{
		std::cout << "Not found" << std::endl;
	}	
	
	std::list<int>::iterator lit;
	lit = std::find(li2.begin(),li2.end(), 27);
	if (lit != li2.end()){
		std::cout << "Found at: " << std::distance(li2.begin(), lit) << std::endl;
	}else{
		std::cout << "Not found" << std::endl;
	}
	
	
}
