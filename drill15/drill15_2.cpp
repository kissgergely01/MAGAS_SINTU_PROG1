#include "../GUI/std_lib_facilities.h"

struct  Person
{
	private:
		string first_name;
		string last_name;
		int age;
	public:
		Person(){};
		Person(string fname, string lname, int a)
		{
			const vector<char> invchar = {';','?',':','[',']','*','&','^','%','$','#','@','!','.','"','\''};
			if (a<=0 or a> 150)
				error("age is not in range");

			if (fname=="" || lname=="")
				error("name must not be empty");
			
			for(int i=0; i < invchar.size(); i++)
				if (fname.find(invchar[i]) != string::npos or lname.find(invchar[i]) != string::npos)
						error("invalid character in name");
			constructinit(fname, lname, a);

		};

		void constructinit(string fname, string lname, int a)
		{

			first_name = fname;
			last_name = lname;
			age = a;
		
		}
			string get_first() 	const{return first_name;}
			string get_last() 	const{return last_name;}
			int get_age() 		const{return age;}
};
ostream& operator<< (ostream& os, Person& p)
{
	return os << p.get_first() << ' ' << p.get_last() << ' ' << p.get_age() << endl; 
}

istream& operator>> (istream& is, Person& p)
{
	string fname, lname; int age;
	cout << "Enter First name: ";
	is >> fname;
	cout << "Enter Last name: ";
	is >> lname;
	cout << "Enter age: ";
	is >> age;
	p = Person(fname,lname,age);
	return is;


	
} 
	


int main()
{
	try
	{

		Person Goofy{"Goofy", "Person", 63};
		cout << Goofy;
		Person p1; 
		cin >> p1;
		cout << p1;

		cout << "Enter names and ages, terminate with \"stop\" - \"stop\" - 1." << endl;
			vector<Person> persons;
			for (Person p2; cin >> p2;)
			{
				if (p2.get_first()=="stop") break;
				persons.push_back(p2);
			}
			for (Person p:persons)
				cout << p << endl;

		return 0;
		}	

	catch(exception& e){
		cerr << "error: "<< e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch(...){
		cerr << "unexpected error" << endl;
		keep_window_open();
		return 2;
	}
}
