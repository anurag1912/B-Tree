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

#include"tree.h"
class Int{


	private:
		int32_t object;
	
	public:
		int32_t ret_obj(void);		

		void operator = (int32_t);
		
		bool operator == (Int &);

		bool operator < (Int &);

		bool operator != (Int & );

		bool operator != (int32_t);

		bool operator > (Int &);

		bool operator >= (Int &);
     		
		unsigned long long operator >=(Tree<Int> &);
		
		unsigned long long operator >(Tree<Int> & );

		unsigned long long operator == (Tree<Int> &);

		unsigned long long operator <= (Tree<Int> &);

		unsigned long long operator < (Tree<Int> &);

    
		    
    
};


int32_t Int::ret_obj(void)
	{ return (this->object);
}

void Int::operator = (int32_t val) {
	
	this->object = val;
	
}


bool Int:: operator == (Int &a) {
return (this->object == a.object);

}

bool Int::operator< (Int &a) {

return (this->object<a.object);
}

bool Int::operator != (Int &a) {

return (this->object!=a.object);
}

bool Int::operator != (int32_t a) {

return (this->object != a);

}

bool Int::operator >(Int &a) {


return (this->object > a.object);
}

bool Int::operator >=(Int &a) {


return (this->object >= a.object);
}



unsigned long long Int::operator >=(Tree<Int> &t) {

Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.equal + a.count);




}
		
unsigned long long Int::operator >(Tree<Int> &t ) {
Ans a = t.greaterThanOrEqual(t.rootnode,*this);

return (a.count);


}

unsigned long long Int::operator == (Tree<Int> &t) {

return t.equalTo(t.rootnode,*this); 


}

unsigned long long Int::operator <= (Tree<Int> & t) {

Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.equal + a.count);

}

unsigned long long Int::operator < (Tree<Int> & t) {
Ans a = t.lessThanOrEqual(t.rootnode,*this);
return (a.count);

}




int main() {

std::cout<<"\n\n############### INTS ###############\n\n";

Tree<Int> t;

key<Int> knew;

Int obj;


   std::default_random_engine eng((std::random_device())());
    std::uniform_int_distribution<int32_t> idis(0, std::numeric_limits<int32_t>::max());

Int obj2;

for(unsigned long long i=1;i<=ONEM;i++) {


obj = abs(idis(eng));
knew.value = obj;
knew.equal=1;
knew.greater=knew.less=0;

t.insertInTree(knew);


if(i==1) {
std::cout<<"Inserting elements...\n";



}

else if(i==TENK) {

std::cout<<"Inserted 10,000 elements. Running queries...\n";

obj2=abs(idis(eng));

std::cout<<"Number of objects < "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));

std::cout<<"Number of objects >= "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));

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

obj2=abs(idis(eng));

std::cout<<"Number of objects <= "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<=t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));

std::cout<<"Number of objects > "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));

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

obj2=abs(idis(eng));

std::cout<<"Number of objects < "<<obj2.ret_obj()<<" = ";

auto start = std::chrono::high_resolution_clock::now();

unsigned long long temp = (obj2<t);

auto elapsed = std::chrono::high_resolution_clock::now() - start;

long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));

std::cout<<"Number of objects >= "<<obj2.ret_obj()<<" = ";

start = std::chrono::high_resolution_clock::now();

temp = (obj2>=t);

elapsed = std::chrono::high_resolution_clock::now() - start;

microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

std::cout<<temp<<"\n";

std::cout<<"Time taken by query: "<<microseconds<<" us\n";


obj2=abs(idis(eng));
Int obj3,obj4;
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
