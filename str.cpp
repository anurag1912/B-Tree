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
class Str{


	private:
		char object[20];
	
	public:
		std::string ret_obj(void);		
		
		void operator = (int32_t);

		void read(char [], unsigned int);
		
		Str create_string(void);
		
		bool operator == (Str &);

		bool operator < (Str &);

		bool operator != (Str & );

		bool operator != (int32_t);

		bool operator > (Str &);

		bool operator >= (Str &);
     		
		unsigned long long operator >=(Tree<Str> &);
		
		unsigned long long operator >(Tree<Str> & );

		unsigned long long operator == (Tree<Str> &);

		unsigned long long operator <= (Tree<Str> &);

		unsigned long long operator < (Tree<Str> &);

    
		    
    
};


std::string Str::ret_obj(void)
	{ std::string s(this->object);
return s;
}

void Str::operator = (int32_t val) {
	
	this->object[0] = '\0';
	
}

void Str::read(char arr[], unsigned int length) {

for(unsigned int i=0;i<length;i++) {

	this->object[i] = arr[i];

}


}


Str Str::create_string(void) {

std::default_random_engine eng((std::random_device())());
std::uniform_int_distribution<int8_t> idis(1, 20);

std::uniform_int_distribution<int8_t> sdis(32, 126);
unsigned int length = idis(eng);
char arr[length];

for(unsigned int i=0;i<length;i++)
{
arr[i] = sdis(eng);
} 

Str temp;

temp.read(arr,length);

return temp;



}


bool Str:: operator == (Str &a) {

std::string s(this->object);

return (s== a.ret_obj());

}





bool Str::operator< (Str &a) {
std::string s(this->object);
return (s<a.ret_obj());
}

bool Str::operator != (Str &a) {
std::string s(this->object);

return (s!=a.ret_obj());
}

bool Str::operator != (int32_t a) {

if(this->object[0]!='\0')
	return true;
else
	return false;

}

bool Str::operator >(Str &a) {
std::string s(this->object);

return (s > a.ret_obj());
}

bool Str::operator >=(Str &a) {
std::string s(this->object);

return (s >= a.ret_obj());
}



unsigned long long Str::operator >=(Tree<Str> &t) {

Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.equal + a.count);




}
		
unsigned long long Str::operator >(Tree<Str> &t ) {
Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.count);


}

unsigned long long Str::operator == (Tree<Str> &t) {

return t.equalTo(t.rootnode,*this); 


}

unsigned long long Str::operator <= (Tree<Str> & t) {

Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.equal + a.count);

}

unsigned long long Str::operator < (Tree<Str> & t) {
Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.count);

}








int main() {

std::cout<<"\n\n############### STRINGS ###############\n\n";
Tree<Str> t;

key<Str> knew;

Str obj;

Str obj2;

for(unsigned long long i=1;i<=ONEM;i++) {



knew.value = obj.create_string();
knew.equal=1;
knew.greater=knew.less=0;

t.insertInTree(knew);


if(i==1) {
std::cout<<"Inserting elements...\n";



}

else if(i==TENK) {

std::cout<<"Inserted 10,000 elements. Running queries...\n";

obj2=obj.create_string();

std::cout<<"Number of objects < "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj.create_string();

std::cout<<"Number of objects >= "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj.create_string();

std::cout<<"Number of objects == "<<obj2.ret_obj()<<" = ";

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

obj2=obj.create_string();

std::cout<<"Number of objects <= "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<=t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj.create_string();

std::cout<<"Number of objects > "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj.create_string();

std::cout<<"Number of objects == "<<obj2.ret_obj()<<" = ";

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

obj2=obj.create_string();

std::cout<<"Number of objects < "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj.create_string();

std::cout<<"Number of objects >= "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=obj2.create_string();
obj = obj.create_string();
Str obj3,obj4;
if(obj2>obj) {

obj3 = obj2;
obj4 = obj;
}
else {
obj3 = obj;
obj4 = obj2;
}


std::cout<<"Number of objects > "<<obj4.ret_obj()<<" and <= "<<obj3.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

Ans1 a = t.greaterThanlessThan(t.rootnode, obj4, obj3);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<(a.equal2+a.count)<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";

return 0;
}
