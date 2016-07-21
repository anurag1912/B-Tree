#include"key.h"
#include<unordered_map>
#include<cstdio>
#include<string>
#define NONE -1
#define SIZE (4096-sizeof(uint32_t)-sizeof(uint8_t)-sizeof(int32_t))
#define QUOT (sizeof(key<T>)+sizeof(int32_t))


#pragma pack(push, 1) 
template <typename T>
struct Node {
	
	key<T> k[(SIZE/QUOT)];
	int32_t ptr[(SIZE/QUOT)+1];
	uint32_t count;
	uint8_t leaf;
	char pad[4096 - (sizeof(key<T>) * (SIZE/QUOT)) - (sizeof(int32_t) * (SIZE/QUOT)) - sizeof(int32_t) - sizeof(uint32_t) - sizeof(uint8_t)];
};
#pragma pack(pop) 


template <class T>
class Tree{
private:



int32_t freenode;


std::unordered_map<Node<T> *,int32_t> htable;

FILE *fp;





public:
int32_t rootnode;
uint32_t ORDER;
Tree<T>();

~Tree<T>();

void insertInTree(key<T>);

void insert_root(key<T> , int32_t);


void split(Node<T> * parent, Node<T> *child, bool flag=false);


void insert(key<T> k, int32_t);


void disk_read(int32_t, Node<T> *);


void disk_write(int32_t, Node<T> *);


Ans greaterThanOrEqual(int32_t, T &);

Ans lessThanOrEqual(int32_t, T &);

unsigned long long equalTo(int32_t, T &) ;

Ans1 greaterThanlessThan(int32_t, T & , T & );




};


#include"tree.tpp"

