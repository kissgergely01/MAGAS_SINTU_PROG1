#include "../GUI/std_lib_facilities.h"

class B1
{
	public:
			virtual void vf() {cout << "B1::vf" << endl;}
			void f() {cout << "B1::f" << endl;}
			virtual void pvf() {cout << "B1::pvf" << endl;} //5.feladat: error, alosztályban lehetne definiálni.
};

class D1 : public B1
{
	public:
		void vf() override {cout << "D1::vf" << endl;}
		void f() {cout << "D1::f" << endl;}  // 4. feladat: ebben a formában is felülíródik a B1 és D1:f-et ad vissza 
		void pvf() {cout << "D1::pvf" << endl;} 
};

class D2 : public D1
{
	public: 
		void pvf() override {cout << "D2::pvf" << endl;}
};

class B2
{
	public:
		virtual void pvf() = 0;
};

class D21 : public B2
{
	public:
		string text; 
		void pvf() override {cout << text << endl;}
};

class D22 : public B2 
{
	public: 
		int num; 
		void pvf() override {cout << num << endl;}
		void f(B2& b) {b.pvf();}  	
};

int main()
{
	
	B1 elso;
	elso.vf();
	elso.f();
	
	D1 masodik;
	masodik.vf(); 		// 2. feladat: felülírja a B1 outputját D1:vf -re 
	masodik.f(); 
	masodik.pvf();

	B1& harmadik {masodik};
	harmadik.vf(); 		// 3. feladat: a D1 objektumának a felülírása erre is érvényes, B1 referencia opjektumot inicializáltunk a D1-re 
	harmadik.f();

	D2 negyedik;
	negyedik.vf();
	negyedik.f();   //a D2-nek nincs f és vf függvénye ezért D1-et ad vissza 
	negyedik.pvf();

	D21 otodik;
	otodik.text = "Nobody expects the Spanish Inquisiton";

	D22 hatodik;
	hatodik.num = 420;

	hatodik.f(otodik); hatodik.f(hatodik);

	return 0;
}
