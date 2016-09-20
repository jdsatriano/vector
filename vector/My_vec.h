/*My_vec.h
Joshua Satriano
Header file for a vector data structure.
*/

#include <iostream>

using namespace std;

class My_vec {
	
	//member variables
	int size, capacity;
	char *ptr;
	
public:	
	//member functions

	My_vec(); //Constructor
	~My_vec(); //Destructor
	My_vec(const My_vec& vec); //Copy Constructor

	My_vec& operator=(const My_vec& vec); //overloading "=" operator
	char& operator[](int i) const; //overloading "[]" operator

	int get_size() const; //returns size of vector
	int get_capacity() const; //returns vector capacity
	bool is_empty() const; //returns true if vector is empty

	void insert_at_rank(int r, const char& elem); //inserts element at given rank
	void replace_at_rank(int r, const char& elem); //replaces element at given rank
	void remove_at_rank(int r); //deletes element at given rank

	void reserve_space(int r); //reserves capacity
	
};
	
	ostream& operator<<(ostream& out, const My_vec& vec); //overloading the output operator
	void sort_max(My_vec& vec); //sort vector from highest to lowest
	int find_max_index(const My_vec& v,int size); //return the index with highest value