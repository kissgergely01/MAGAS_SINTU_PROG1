include <iostream>
include <string>
include <vector>

template <typename T>
struct S {
	S(T vv = 0): val{vv}{}
	T& get();
	
	const T& get() const;
	void operator=(const T& s);
	void set(T new_t) {val=new_t;}
	private:
	T val;
	
};

template <typename T>
T& S<T>::get(){
	return val;
}
template <typename T>
const T& S<T>::get() const{
	return val;
}
template <typename T>
void S<T>::operator=(const T& s){
	val = s;
}

template <typename T>
void read_val(T& v){
	cin >> v;
	
}
template<typename T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}
template<typename T> ostream& operator<<(ostream& os, const vector<T>& d)
{
    os << "{ ";
    for (int i = 0; i<d.size(); ++i) {
        os << d[i];
        if (i<d.size()-1) os << ',';
        os << ' ';
    }
    os << "}";
    return os;
}


template<class T> void read_val(T& v)
{
    cin >> v;
}


int main(){
	S<int> s;
	S<int> si {37};
	S<char> sc {'c'};
	S<double> sd {3.2};
	S<std::string> ss {"Hello"};
	S<std::vector<int>> svi {std::vector<int>{1, 1, 2, 3, 5, 8}};
	
	cout << "S<int>: " << s.get() <<endl;
	cout << "S<int>: " << si.get() <<endl;
	cout << "S<char>: " << sc.get() <<endl;
	cout << "S<double>: " << sd.get() <<endl;
	cout << "S<string>: " << ss.get() <<endl;
	
	cout << "S<vector>: ";
	for(auto& a: svi.get()){
		cout << a << ' ';
	}
	cout << endl;
	sc.set('s');
	cout << "S<char>: " << sc.get() <<endl;
	
	sd = 42.1;
	cout << "S<double>: " << sd.get() <<endl;
	
	int ii;
	read_val(ii);
	S<int> si2 {ii};
	
	double dd;
	read_val(dd);
	S<double> sd2 {dd};
	string ss2;
	read_val(ss2);
	S<string> str {ss2};
	
	cout << "S<int>: " << si2.get() <<endl;
	cout << "S<double>: " << sd2.get() <<endl;
	cout << "S<string>: " << str.get() <<endl;
	
	vector<int> vint;
	read_val(vint);
	
	
}
