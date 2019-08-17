#include <iostream>

// Basic Array ADT
class Array{
	private:
		int *A;	
		int length;
		int size;	
	
	public:
		Array(int size_arr);
		int add(int x);
		int insert_el(int index, int x);
		int insertInSorted(int x);
		int delete_el(int index);
		int isPresentLinear(int element);
		int isPresentBinary(int element);
		int isSorted();
		int get_el(int index);
		int set_el(int index, int value);
		int max_el();
		int min_el();
		int mean();
		int sum();
		int reverse();
		int display_el();
};

// Constructor
Array::Array(int size_arr){
	this->size = size_arr;
	A = new int[this->size];
	this->length = 0;
};

// Display function - Old function (New One will be operator overloaded)
int Array::display_el(){
	for (int i=0; i<this->length; i++){
		std::cout<<A[i]<<std::endl;
	}	
};

// Add function - To add an element at the end of the array
int Array::add(int x){
	if (this->length < this->size){
		this->A[this->length++] = x;
	}
};

// Insert function - To insert an element at a certain index with a cetain value
int Array::insert_el(int index, int x){
	if(index >= 0 && index <= this->length){
	
		for (int i=this->length; i>index; i--){
	
			this->A[i] = this->A[i-1];
		};
		this->A[index] = x;
	};	
};

// Delete function - To delete the element having a certain index
int Array::delete_el(int index){
	if (index >= 0 && index<this->length){
		int x = this->A[index];
		for (int i=index; i<this->length; i++){
			this->A[i] = this->A[i+1];
		};
		this->length--;
		return x;
	}
	return -1;
	
};

// Linear Search Function
int Array::isPresentLinear(int element){
	for (int i=0; i<length; i++){
		if (A[i] == element){
			return i;
		}
	}
	return -1;
}

// Binary Search
int Array::isPresentBinary(int element){
	int start_idx = 0;
	int end_idx = this->length-1;
		
	while (start_idx <= end_idx){
		int mid_idx = (start_idx + end_idx) / 2;
		
		if (A[mid_idx] == element){
			return mid_idx;
		}
		else if (A[mid_idx] > element){
			end_idx = mid_idx - 1;
		}
		else{
			start_idx = mid_idx + 1;
		}
	}
	return -1;
}

// Other Basic functions
int Array::get_el(int index){
	if (index >= 0 && index < this->length){
		return this->A[index];
	}
}

int Array::set_el(int index, int value){
	if (index >= 0 && index < this->length){
		this->A[index] = value;
	}
}

int Array::max_el(){
	int el = this->A[0];
	for (int i=0; i<this->length; i++){
		if (this->A[i] > el){
			el = this->A[i];
		}
	}
	return el;
}

int Array::min_el(){
	int el = this->A[0];
	for (int i=0; i<this->length; i++){
		if (this->A[i] < el){
			el = this->A[i];
		}
	}
	return el;
}

int Array::mean(){
	int summ;
	float mean;
	
	for(int i=0; i<this->length; i++){
		summ += this->A[i];
	}
	mean = summ / this->length;
	
	return mean;
}

int Array::sum(){
	int sum;
	for (int i=0; i<this->length; i++){
		sum += this->A[i];
	}
	return sum;
}

// Reverse function
int Array::reverse(){
	for (int i=0, j=this->length-1; i<j; i++, j--){
		int temp = this->A[i];
		this->A[i] = this->A[j];
		this->A[j] = temp;	
	};
};

// Inserting Operation in a Sorted Array
int Array::insertInSorted(int x){
	int i=this->length-1;
	while (this->A[i] > x){
		this->A[i+1] = this->A[i];
		i--;
	}
	A[i+1] = x;
	this->length++;
}

// Checking if an array is sorted
int Array::isSorted(){
	for (int i=0; i<this->length-1; i++){
		if (this->A[i] > this->A[i+1]){
			return 0;
		}
	}
	return 1;
}

int main(){
	Array a1(5);
	a1.add(1);
	a1.add(2);
	a1.add(4);
	a1.add(3);
	a1.display_el();
	std::cout<<"______________________"<<std::endl;
	std::cout<<a1.isSorted()<<std::endl;
};