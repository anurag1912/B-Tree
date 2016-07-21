#include<math.h>
#include<iostream>
#include<chrono>
#include <limits>
#include <random>
#define TENK 10000
#define HUNDREDK 100000
#define ONEM   1000000
#define TENM  10000000
#define HUNDREDM 100000000
#include<string>
#include"tree.h"
class Person{


	private:
		
		int8_t age;
		float salary;
		char name[20];
	
	public:
		std::string ret_name(void);
		
		int8_t ret_age(void);
		
		float ret_salary(void);		
		
		void operator = (int32_t);
		
		void create(void);
		
		bool operator == (Person &);

		bool operator < (Person &);

		bool operator != (Person & );

		bool operator != (int32_t);

		bool operator > (Person &);

		bool operator >= (Person &);
     		
		unsigned long long operator >=(Tree<Person> &);
		
		unsigned long long operator >(Tree<Person> & );

		unsigned long long operator == (Tree<Person> &);

		unsigned long long operator <= (Tree<Person> &);

		unsigned long long operator < (Tree<Person> &);

    
		    
    
};


std::string Person::ret_name(void) {
	 std::string s(this->name);
return s;
}

int8_t Person::ret_age(void) {
return (this->age);

}
float Person::ret_salary(void) {
return (this->salary);
}
void Person::operator = (int32_t val) {
	this->age=val;
	this->salary = val;
	this->name[0] = '\0';
	
}


bool Person::operator != (int32_t a) {

if(this->name[0]!='\0' && this->age!=a && this->salary!=a)
	return true;
else
	return false;

}


void Person::create(void) {

std::default_random_engine eng((std::random_device())());
std::uniform_int_distribution<int8_t> idis(1, 20);

std::uniform_int_distribution<int8_t> sdis(32, 126);

std::uniform_real_distribution<float> fdis(0, 10000000.0);

std::uniform_int_distribution<int8_t> idist(1, 120);
unsigned int length = idis(eng);
char arr[length];

for(unsigned int i=0;i<length;i++)
{
this->name[i] = sdis(eng);
} 

this->age = idist(eng);
this->salary = fdis(eng);

}


bool Person:: operator == (Person &a) {

std::string s(this->name);


if(s==a.ret_name() && this->age==a.ret_age() && this->salary==a.ret_salary())
return true;
else
return false;

}





bool Person::operator< (Person &a) {
std::string s(this->name);
if(s<a.ret_name() && this->age<a.ret_age() && this->salary<a.ret_salary())
return true;
else

return false;
}

bool Person::operator != (Person &a) {
std::string s(this->name);


if(s!=a.ret_name() && this->age!=a.ret_age() && this->salary!=a.ret_salary())
return true;
else
return false;

}


bool Person::operator >(Person &a) {
std::string s(this->name);

if(s>a.ret_name() && this->age>a.ret_age() && this->salary>a.ret_salary())
return true;
else

return false;
}

bool Person::operator >=(Person &a) {
std::string s(this->name);

if(s>=a.ret_name() && this->age>=a.ret_age() && this->salary>=a.ret_salary())
return true;
else

return false;
}



unsigned long long Person::operator >=(Tree<Person> &t) {

Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.equal + a.count);




}
		
unsigned long long Person::operator >(Tree<Person> &t ) {
Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.count);


}

unsigned long long Person::operator == (Tree<Person> &t) {

return t.equalTo(t.rootnode,*this); 


}

unsigned long long Person::operator <= (Tree<Person> & t) {

Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.equal + a.count);

}

unsigned long long Person::operator < (Tree<Person> & t) {
Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.count);

}








int main() {

std::cout<<"\n\n############### ADT ###############\n\n";
Tree<Person> t;

key<Person> knew;

Person obj;

Person obj2;

for(unsigned long long i=1;i<=ONEM;i++) {

obj.create();

knew.value = obj;
knew.equal=1;
knew.greater=knew.less=0;

t.insertInTree(knew);


if(i==1) {
std::cout<<"Inserting elements...\n";



}



else if(i==TENK) {

std::cout<<"Inserted 10,000 elements. Running queries...\n";

obj2.create();

std::cout<<"Number of objects < Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();

std::cout<<"Number of objects >= Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();

std::cout<<"Number of objects == Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2==t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";

std::cout<<"Inserting elements...\n";

}

else if(i==HUNDREDK) { 

std::cout<<"Inserted 100,000 elements. Running queries...\n";

obj2.create();

std::cout<<"Number of objects <= Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<=t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();

std::cout<<"Number of objects > Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();

std::cout<<"Number of objects == Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2==t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";

std::cout<<"Inserting elements...please don't quit program...\n";

}




}

std::cout<<"Inserted 1,000,000 elements. Running queries...\n";

obj2.create();

std::cout<<"Number of objects < Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();

std::cout<<"Number of objects >= "<<"Name: "<<obj2.ret_name()<<" Salary: "<<obj2.ret_salary()<<" Age: "<<(unsigned int)obj2.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2.create();
obj.create();
Person obj3,obj4;
if(obj2>obj) {

obj3 = obj2;
obj4 = obj;
}
else {
obj3 = obj;
obj4 = obj2;
}


std::cout<<"Number of objects > Name: "<<obj4.ret_name()<<" Salary: "<<obj4.ret_salary()<<" Age: "<<(unsigned int)obj4.ret_age()<<" && "<<" <= Name: "<<obj3.ret_name()<<" Salary: "<<obj3.ret_salary()<<" Age: "<<(unsigned int)obj3.ret_age()<<" = ";

start = std::chrono::high_resolution_clock::now();

Ans1 a = t.greaterThanlessThan(t.rootnode, obj4, obj3);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<(a.equal2+a.count)<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";

return 0;
}
