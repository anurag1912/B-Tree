# B-Tree--Pagesize = 4096 bytes
To compile and run all the test cases type "make" on the command prompt and this will compile and start executing the test cases.

Tree files (Data Structure):

-tree.tpp, tree.h, key.h

Object files:

-int.cpp, float.cpp, str.cpp, adt.cpp

Tree files: These files contain a templated container that can store arbitrary types. I have optimized this data structure for reads. The container along with its methods is in tree.tpp. Tree.h and key.h store additional data structures that are not only used by the tree but are also used by the objects themselves.

Object files: These files contain the data-types that go in the container. The templated container abstraction is very powerful as any type user-defined or abstract can be stored in the container. 

-int.cpp: This file defines the Int data type. It is basically an integer type abstraction and stores integral values. A main() function is defined which generates random integers and stores it in the container.

-float.cpp: This file defines an abstract decimal type. It contains overloaded operators for comparison and for range queries. The node that stores data of type float is aligned along the 4096 page size boundary for faster execution.

-str.cpp: This file stores string representations and is also aligned along the 4096 boundary. The string is randomly generated by using a random generator. Initially a random length is chosen for the string and then random ASCII characters of that length are inserted into the container.

-adt.cpp: This abstract data type specifies the fields for a person who has an age, name and salary. The key contains the data of a single person and the Node contains the information about several people.


Running time: The running time complexity for insertions & range queries is logarithmic. As the size of the data is in millions, I have used an on-disk data structure. Running the above files for each data type will yield a ".dat" file which is nothing but the file where the keys and nodes of the tree are stored. The major bottle-neck in my program is the slow disk access and I have made efforts to align the nodes of the tree according to the page-size of the underlying system so as to speed up the execution of my program.   

 
Output: The output is self-explanatory but as and when the size of the input increases the running time to finish inserting into the container also increases. This is due in part to the disk access time and hence I would urge the user to not exit the program abruptly and let it run to completion. The container and the types that it stores have been thoroughly tested and thus the above request.




