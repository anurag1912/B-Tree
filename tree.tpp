

#include<iostream>
#include<queue>

template<typename T>
Tree<T>::Tree() {

rootnode=freenode=0;
fp=fopen("data.dat","wb+");

ORDER=SIZE/QUOT;

Node<T> root;
	
	//std::cout<<sizeof(Node);

if(ORDER%2==0)
ORDER-=1;

	
	for(unsigned int i=0;i<ORDER;i++) {
		root.k[i].value=-1;
		
		root.k[i].equal=0;
		
		root.k[i].greater=0;
		
		root.k[i].less=0;
		
		root.ptr[i]=NONE;
		
		
		
	}
	root.count=0;
		
	root.leaf=1;
	
	root.ptr[ORDER]=NONE;

	disk_write(rootnode,&root);
	freenode+=sizeof(Node<T>);



}

template<typename T>
Tree<T>::~Tree(){

fclose(fp);

}


template<typename T>
void Tree<T>::insertInTree(key<T> k) {


insert_root(k,rootnode);


}


template<typename T>
void Tree<T>::insert_root(key<T> k, int32_t rt) {
	Node<T> root;
	Node<T> temp;
	disk_read(rt,&root);
	htable.insert(std::pair<Node<T> *,int32_t> (&root,rt));
	if(root.count==ORDER) {
		/* As root is full we do a preemptive split, allocate and initialize a new root */
		uint32_t c=0;		
		while(c<root.count)
		{
		if(root.k[c].value==k.value) break;	
		c++;
		
		}
		
		if(c<root.count) {
			root.k[c].equal++;
			htable.erase(&root);
			disk_write(rt,&root);
			return;
		}
		
		/* Initializing */
		for(unsigned int i=0;i<ORDER;i++) {
		
		temp.k[i].value=-1;
		
		temp.k[i].equal=0;
		
		temp.k[i].greater=0;
		
		temp.k[i].less=0;
		
		temp.ptr[i]=NONE;
		
	}	
		temp.ptr[ORDER]=NONE;
	
		temp.count=0;
		
		temp.leaf=0;
		/* End of initialization */
		
		split(&temp,&root,true); //split root
		
		htable[&root] = htable[&temp];
		rootnode = htable[&root];	
	}
	
	
	
	insert(k,htable[&root]); 		//insert key in new root
		
	
	htable.erase(&root);
	htable.erase(&temp);
	
	
}
template<typename T>
void Tree<T>::split(Node<T> * parent, Node<T> *child, bool flag) {
		
		/* 
		
		Initializing a new node as we are splitting child node in two separate children nodes 
		root >--->>> child1
		temp >--->>> child2
	
		*/
		//Initializize
		Node<T> *temp = new Node<T>;
		
		temp->count=0;
		
		temp->leaf=child->leaf;
			
		for(unsigned int i=0;i<ORDER;i++) {
		
		temp->k[i].value=-1;
		
		temp->k[i].equal=0;
		
		temp->k[i].greater=0;
		
		temp->k[i].less=0;
		
		temp->ptr[i]=NONE;
		
	}	
		temp->ptr[ORDER]=NONE;
		
		//End initialize
		
		long i = 0;
		temp->ptr[ORDER/2] = child->ptr[ORDER];
		child->ptr[ORDER] = NONE;			//replaced by 0
		while(i<(ORDER/2)) {
			  
			//Shifting keys and..
			temp->ptr[i] = child->ptr[ORDER/2+1+i];
			
			child->ptr[ORDER/2+1+i] = NONE;			//replaced by 0
			temp->k[i] = child->k[ORDER/2+1+i];
			//...pointers
			
			
			//Clearing shifted value from original child node
			child->k[ORDER/2+1+i].value=-1;			
			child->k[ORDER/2+1+i].less=0;
			child->k[ORDER/2+1+i].greater=0;
			child->k[ORDER/2+1+i].equal=0;
			//Finish clearing
			
			i++;	
		}
		
		temp->count = i;
		
		child->count=i;
		
		unsigned long long less=0;
		for(unsigned int i=0;i<ORDER/2;i++) 
		{
			less += child->k[i].less;
			less += child->k[i].equal;
			
			
		}
		
	
		
		unsigned long long greater =0;
		for(unsigned int i=0;i<ORDER/2;i++) 
		{
			greater += temp->k[i].greater;
			greater += temp->k[i].equal;
			
			
		}

	
	//std::cout<<"\n";
			
	if(flag==true) {
		//Write new root node to disk
	
			
		parent->k[0] = child->k[ORDER/2];
		
		parent->count++;
		
		parent->ptr[0] = htable[child];
		
		
		parent->k[0].less = parent->k[0].less + less;
		
		parent->k[0].greater = parent->k[0].greater + greater;
		
		child->k[ORDER/2].value =-1;
		
		child->k[ORDER/2].equal =0;
		
		child->k[ORDER/2].less =0;
		
		child->k[ORDER/2].greater =0;
		disk_write(htable[child],child);
		parent->ptr[1] = freenode;
		disk_write(freenode,temp);
		
		freenode+=sizeof(Node<T>);
		
		htable.insert(std::pair<Node<T> *,int32_t>(parent,freenode));
		disk_write(htable[parent],parent);
		freenode+=sizeof(Node<T>);
		
		
	}
	
	else {
		long j=parent->count;
		j--;
		while(j>=0 && child->k[ORDER/2].value < parent->k[j].value){
			
			parent->k[j+1] = parent->k[j];
			j--;
		}	
		
		j++;
		
		parent->k[j] = child->k[ORDER/2];
		
		parent->k[j].less = parent->k[j].less + less;
		
		parent->k[j].greater = parent->k[j].greater + greater;
		
		if(j==0) {
			
			if(parent->k[j+1].value!=-1) {
				
			parent->k[j+1].less = parent->k[j].greater;	
				
			}
		}
		
		else if(j==(parent->count)) {
			
			
			parent->k[j-1].greater = parent->k[j].less;	
				
			
			
		}
		
		else {
			
			
				parent->k[j+1].less = parent->k[j].greater;	
				parent->k[j-1].greater = parent->k[j].less;	
		}
		
		long k = parent->count;
		
		while(k>=(j+1)) {
			
			parent->ptr[k+1] = parent->ptr[k];
			k--;
			
		}
		parent->ptr[j+1] = freenode;	//temp;
		//std::cout<<temp->k[0].key<<" "<<temp->k[1].key<<" "<<temp->k[2].key<<"\n";
		disk_write(freenode,temp);
		freenode +=sizeof(Node<T>);
		parent->count++;
		
		child->k[ORDER/2].equal=0;
		
		child->k[ORDER/2].greater=0;
		
		child->k[ORDER/2].value=-1;
		
		child->k[ORDER/2].less=0;
		//std::cout<<child->k[0].key<<" "<<child->k[1].key<<" "<<child->k[2].key<<"\n";
		//std::cout<<parent->k[0].key<<" "<<parent->k[1].key<<" "<<parent->k[2].key<<"\n";
		disk_write(htable[child],child);
		disk_write(htable[parent],parent);
	
		
	}
	
	
		delete temp;
}

template<typename T>
void Tree<T>::insert(key<T> k, int32_t block) {
	
	
	
	Node<T> *temp =new Node<T>; 
	disk_read(block,temp);
	
	if(temp->leaf==1) {
		//if(k.key==6)
		// std::cout<<"In insert "<<temp->k[0].key<<" "<<temp->k[1].key<<" "<<temp->k[2].key<<"\n";
		long j=0;
		while(j<temp->count && k.value!=temp->k[j].value) {
		//	std::cout<<"Temp = "<<temp->k[j].key<<" ";
			j++;
			
		}
		//std::cout<<"\n";
		if(j<temp->count) {
			temp->k[j].equal++;
			disk_write(block,temp);
			delete temp;
			return;
		
		}
		
		long i=temp->count;
		i--;
		
		
		
		while(i>=0 && k.value<temp->k[i].value) {
			
			temp->k[i+1] = temp->k[i];
			i--;
		}
		
		
		i++;
		
		temp->k[i] = k;
		//std::cout<<k.key<<" "<<temp->k[0].key<<" "<<temp->k[1].key<<" "<<temp->k[2].key<<"\n";
		temp->count++;
		
		disk_write(block,temp);
		
		
	}
	
	else {
		
		long j=0;
		
		while(j<temp->count && k.value!=temp->k[j].value) {
			j++;
			
		}
		if(j<temp->count) {
			temp->k[j].equal++;
			disk_write(block,temp);
			delete temp;
			return;
			
		}
		
		long n = temp->count-1;
		

		while(n>=0 && k.value<temp->k[n].value) 
			n--;
			
		
		n++;
		
		if(n==0) {
			//if(k.key==6) std::cout<<"in n==0 if\n";
			temp->k[n].less++;
		}
		
		else if(n==(temp->count)) {
			//if(k.key==6) std::cout<<"in n==temp->count else if\n";
			//std::cout<<temp->k[n-1].key;
			temp->k[n-1].greater++;
		}
		
		else {
			//if(k.key==6) std::cout<<"in else\n";
			temp->k[n].less++;
			temp->k[n-1].greater++;		
			
		}
		
		disk_write(block,temp);
		Node<T> *temp1 = new Node<T>;
		disk_read(temp->ptr[n],temp1);
		
	
	
	
	
		//Disk-read(temp->ptr[n]);
		
		long updated = n; 
		if(temp1->count==ORDER) {
			
			if(k.value==temp1->k[ORDER/2].value) {
			temp1->k[ORDER/2].equal++;
			disk_write(temp->ptr[n],temp1);
			delete temp;
			delete temp1;
			return;
			
		}
		
		
		
			if(k.value > temp1->k[ORDER/2].value) {
				n++;
				temp1->k[ORDER/2].greater++;
			}
			else 
			temp1->k[ORDER/2].less++;
						htable.insert(std::pair<Node<T> *,int32_t>(temp,block));
					//	std::cout<<"Size of "<<temp->ptr[n-1]<<"\n";
			htable.insert(std::pair<Node<T> *,int32_t>(temp1,temp->ptr[updated]));
			split(temp,temp1);
			
			
		}
			/*
			if(updated==n) 
			{
				//fetch old block
				Disk-read(old-block);
			}
			else {
				//fetch latest block
				Disk-read(latest block);
				}
			*/
			//std::cout<<temp1->k[0].key<<" "<<temp1->k[1].key<<" "<<temp1->k[2].key<<"\n";

			insert(k,temp->ptr[n]);
			htable.erase(temp1);
			htable.erase(temp);
			delete temp1;
	}
	
	
	delete temp;
	
}


template<typename T>
void Tree<T>::disk_read(int32_t ptr, Node<T> *n) {
	
	
	fseek(fp,ptr,SEEK_SET);
	fread(n,sizeof(Node<T>),1,fp);
	
	
}
template<typename T>
void Tree<T>::disk_write(int32_t ptr, Node<T> *n) {
	fseek(fp,ptr,SEEK_SET);
	fwrite(n,sizeof(Node<T>),1,fp);
}








template<typename T>
Ans Tree<T>::greaterThanOrEqual(int32_t root, T &less) {


Ans a;
	Node<T> * temp = new Node<T>;
	disk_read(root,temp);
	
	unsigned int i=0;
	
	long j=-1;
	
	unsigned long long equals=0;
	
	unsigned long long g=0;
	
	bool flag = false;
	

	
	while(temp!=0) {
	j=-1;
	i=0;
	flag = false;
	while(i<temp->count) {
	
	if(temp->k[i].value==less) {
		equals = temp->k[i].equal;
		g += temp->k[i].greater;
		i++;
		while(i<temp->count) {
			
			g+= temp->k[i].greater;
			g+= temp->k[i].equal;
 			
			i++;
		}
		flag = true;
		break;
	}	
	else if(temp->k[i].value>less) {
		j=i;
		while(i<temp->count) {
			
			g+= temp->k[i].greater;
			g+= temp->k[i].equal;
 			
			i++;
		}
		break;	
		
	}
	
	
		
	i++;
	
	}	
	
	if(flag==true) break;
	
	if(j>=0) {
		if(temp->ptr[j]==NONE)
		temp=0;
		else
		disk_read(temp->ptr[j],temp);
		}
	else {
				if(temp->ptr[i]==NONE)
		temp=0;
		else
		disk_read(temp->ptr[i],temp);
	} 
		
	

}
a.equal = equals;
a.count = g;
delete temp;
return a;



}
template<typename T>
Ans Tree<T>::lessThanOrEqual(int32_t root, T &greater) {
	
		Ans a;
	
	Node<T> * temp = new Node<T>;
	disk_read(root,temp);
	
	unsigned int i=0;
	
	unsigned long long equals=0;
	
	unsigned long long l=0;
	
	bool flag = false;
	

	
	while(temp!=0) {
	i=0;
	flag = false;
	while(i<temp->count) {
	
	if(temp->k[i].value==greater) {
		
		equals = temp->k[i].equal;
		l+= temp->k[i].less;
		flag=true;
		break;
		
	}	
	else if(temp->k[i].value>greater) {
		
		break;
	}
	
	l += temp->k[i].equal;
	l += temp->k[i].less;
		
	i++;
	
	}	
	
	if(flag==true) break;
	
		if(temp->ptr[i]==NONE)
		temp=0;
		else
		disk_read(temp->ptr[i],temp);
	
	

}
a.equal = equals;

a.count = l;
delete temp;
return a;

} 

template<typename T>
Ans1 Tree<T>::greaterThanlessThan(int32_t temp1, T &l, T &g) {
	
	Ans1 ans;
	ans.equal1=0;
	ans.equal2=0;
	ans.count=0;
	Node<T> *root=new Node<T>;
	disk_read(temp1,root);
	Node<T> *root1 = root;
	int32_t temp=0;
	if(l==g)
		{
			ans.equal1 = equalTo(temp1, l); 
			ans.equal2 = ans.equal1;
			ans.count =0;
			delete root;
			return ans;
		}
			
		unsigned int i=0;
		
		unsigned long long count =0;
		
		bool flag = false;
		
		while (root!=0) {
			
			i=0;
			while(i<root->count) {
				
				if(root->k[i].value>=l)
				{	//std::cout<<root->k[i].key<<"\n";
					flag=true;
					break;
				}
				
				i++;
				
			}
			
			if(flag==true)
				break;
			if(root->ptr[i]==NONE)
			root = 0;
			else
			disk_read(root->ptr[i],root);
			//Disk-read(root->ptr[i]);
		}
		if(root==0) {
		delete root1;
		return ans;
		}
		if(root->k[i].value==l) {
			//std::cout<<"in root->k[i].key == l \n";
			ans.equal1=root->k[i].equal;
			count += root->k[i].greater;
			
			i++;
			while(i<root->count) {
				
				if(root->k[i].value>=g)
					break;
				
				count += root->k[i].greater;
				count += root->k[i].equal;
				
				i++;
			}
			
			if(i==root->count || root->k[i].value > g) 
			{
				count -= root->k[i-1].greater;
				temp = root->ptr[i];
				
				Ans a =	lessThanOrEqual(temp,g);
				//std::cout<<"COUNTCOUNT = "<<a.count<<"\n";
				ans.count = a.count + count;
				
				ans.equal2 = a.equal;
				delete root1;
				return ans;
			}
			
				
			else {
				
				ans.equal2=root->k[i].equal;
				ans.count = count;
				delete root1;
				return ans;
			}
			
			
		}
	
		else {
			
			// greater than l
			
			if(root->k[i].value==g) {
					Ans a1 = greaterThanOrEqual(root->ptr[i],l);
					
					ans.equal1 = a1.equal;
					ans.count = a1.count;
					ans.equal2=root->k[i].equal;
					delete root1;
					return ans;
			}/*
			else if(root->k[i].key>g) {
					ans.equal2=0;
					ans.count = count;
					return ans;
			}
			*/

			else { //greater than l (< or > g)
				unsigned int j=i;
		
				
				while(i<root->count) {
					
					if(root->k[i].value>=g)
					break;
				
					count += root->k[i].greater;
					count += root->k[i].equal;
				
					i++;
					
					
				}
					
				
				if(i==root->count || root->k[i].value>g) 
					{ if(i!=0)
					count -= root->k[i-1].greater;
					if(root->ptr[i]==NONE)
					temp=0;
					else
					temp = root->ptr[i];
					
					if(i==j) 
					{
					if(root->ptr[j]==NONE)
						
						return greaterThanlessThan(0,l,g);	//new root
						else
							return  greaterThanlessThan(root->ptr[j],l,g);	//new root
					}
					int32_t newroot=0;
					if(root->ptr[j]==NONE)
					root=0;
					else{
					newroot = root->ptr[j];
					disk_read(root->ptr[j],root);		//new root
					}
					//std::cout<<"in here \n";
					Ans a  =  lessThanOrEqual(temp, g);
					
					ans.count = count + a.count;
					ans.equal2 = a.equal;
					a = greaterThanOrEqual(newroot,l);
					//std::cout<<a.count<<"\n";
					ans.equal1=a.equal;
					ans.count += a.count;
					delete root1;
					return ans;
					}
				else  {
					Ans a1 = greaterThanOrEqual(root->ptr[j],l);
					ans.equal1 = a1.equal;
					ans.equal2=root->k[i].equal;
					ans.count = count + a1.count;
					delete root1;
					return ans;
				}
				
			}
		}





	/*
Ans a1 = lessThanOrEqual(root, l);
Ans a2 = lessThanOrEqual(root,g);

ans.count= abs(a1.count-a2.count);
ans.equal1 = a1.equal;
ans.equal2 = a2.equal;
ans.count -= a1.equal;

*/	
	
}



template<typename T>
unsigned long long Tree<T>::equalTo(int32_t temp, T &equal) {
	
	unsigned int i=0;
	Node<T> *root = new Node<T>;
	Node<T> *root1 = root;
	disk_read(temp,root);
	while(root!=0) {
		i=0;
		while(i<root->count) {
		
		if(root->k[i].value==equal) 
			{	unsigned long long x =root->k[i].equal; 
				delete root1;
				return x;
			}
		
		else if(root->k[i].value>equal) 
			break;
		i++;
	}
		if(root->ptr[i]==NONE)
		root=0;
		else
		disk_read(root->ptr[i],root);
		
	}
	
	delete root1;
	return 0;
}
