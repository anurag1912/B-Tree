#include<cstdint>
#pragma pack(push, 1) 
struct Ans{
	
	uint64_t equal;
	uint64_t count;
	
};
#pragma pack(pop) 
#pragma pack(push, 1) 
struct Ans1{
	
	uint64_t equal1;
	uint64_t equal2;
	uint64_t count;
	
};
#pragma pack(pop) 





#pragma pack(push, 1) 
template <typename T>
struct key{
	
	T value;			//key to be indexed
	uint64_t less;	
	uint64_t equal;
	uint64_t greater;
	
};
#pragma pack(pop) 

