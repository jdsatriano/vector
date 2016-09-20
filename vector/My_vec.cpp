#include "My_vec.h"

//-------------------------------------------------------------------------------------

My_vec::My_vec() { 
	size = 0;
	capacity = 16;
	ptr = new char[capacity];
}

//-------------------------------------------------------------------------------------

My_vec::~My_vec() {delete[] ptr;} 

//-------------------------------------------------------------------------------------

My_vec::My_vec(const My_vec& vec) {
	size = vec.get_size(); 
	capacity = vec.get_capacity(); 
	ptr = new char[capacity]; 

	for (int i = 0; i < size; i++) {
		ptr[i] = vec[i];
	}
}

//-------------------------------------------------------------------------------------

My_vec& My_vec::operator=(const My_vec& vec) {
	if (capacity <= vec.get_size()) {        //check to see if enough room
		reserve_space(2 * vec.get_size());
	}
	else {
		capacity = vec.get_capacity();
	}

	size = vec.get_size();

	for (int i = 0; i < vec.get_size(); i++) { //copy elements over
		ptr[i] = vec[i];
	}

	return *this;
}

//-------------------------------------------------------------------------------------

char& My_vec::operator[](int i) const {
	return ptr[i];
}

//-------------------------------------------------------------------------------------

int My_vec::get_size() const {return size;}

//-------------------------------------------------------------------------------------

int My_vec::get_capacity() const {return capacity;}

//-------------------------------------------------------------------------------------

bool My_vec::is_empty() const {return size==0;}

//-------------------------------------------------------------------------------------

void My_vec::insert_at_rank(int r, const char& elem) {

	if(size >= capacity) reserve_space(2*size); //check to see if enough room

	if(r < 0 || r >= capacity) throw out_of_range("illegal index"); //check to see if argument is in range

	for(int i = (size - 1); i >= r; i--) {
		ptr[i+1] = ptr[i];
	}

	ptr[r] = elem;
	size++;
}

//-------------------------------------------------------------------------------------

void My_vec::replace_at_rank(int r, const char& elem) {
	if(r < 0 || r >= capacity) throw out_of_range("illegal index"); //check to see if argument is in range

	ptr[r] = elem;
}

//-------------------------------------------------------------------------------------

void My_vec::remove_at_rank(int r) {
	if (r < 0 || r >= capacity) throw out_of_range("illegal index"); //check to see if argument is in range

	for (int i = (r+1); i < size; i++) {
		ptr[i-1] = ptr[i];
	}

	size--;
}

//-------------------------------------------------------------------------------------

void My_vec::reserve_space(int i) {
	capacity = i;
	char *ptr2 = new char[capacity];
	for (int x = 0; x < size; x++) {
		ptr2[x] = ptr[x];
	}

	delete[] ptr;

	ptr = ptr2;
}

//-------------------------------------------------------------------------------------

ostream& operator<<(ostream& out, const My_vec& vec) {
	for (int i = 0; i < vec.get_capacity(); i++) {
		out << (i) << " - " << vec[i] << "\n";
	}
}

//-------------------------------------------------------------------------------------

void sort_max(My_vec& vec) {
	for (int i = 1; i < vec.get_capacity(); i++) { //sort vector using insertion sort (descending order)
		int current = vec[i];
		int x = i-1;
		while (x >= 0 && vec[x] < current) {
			vec[x+1] = vec[x];
			x--;
		}
		vec[x+1] = current;
	} 
}

//-------------------------------------------------------------------------------------

int find_max_index(const My_vec& v, int size) { //find max index
	int index = 0;
	for (int i = 1; i < size; i++) {
		if (v[i] > v[index]) index = i;
	}

	return index;
}


