#ifndef MY_MATRIX_HH
#define MY_MATRIX_HH

#include <iostream>

template <typename T>
class my_matrix{
private:
	int rows;
	int columns;
	T **pt;

public: 
	my_matrix(){
		rows = 1;
		columns = 1;
		pt = new T*[columns];
	    for(int i = 0; i < columns; i++){
	    	pt[i] = new T[rows];
	    }  
	}
	my_matrix(int rows, int columns){

		try{
	        if(rows <=0 || columns <= 0){
				throw "The dimension of the matrix is illegal.";
			}
			this->rows = rows;
			this->columns = columns;
			pt = new T*[columns];
		    for(int i = 0; i < columns; i++){
		    	pt[i] = new T[rows];
		    }
		}catch ( const char * e ){
			std :: cout << e << std :: endl ;
		} 
	}
	my_matrix(const my_matrix& copy){
		rows = copy.rows;
		columns = copy.columns;
		pt = new T*[columns];
	    for(int i = 0; i < columns; i++){
	    	pt[i] = new T[rows];
	    	pt[i] = copy.pt[i];
	    }  
	}

	~my_matrix(){
		
	    for(int i = 0; i < columns; i++){
	    	delete[] pt[i];
	    }     
    	delete[] pt;
    			
	}

	my_matrix& operator=(const my_matrix m){
		try{
	        if(rows != m.rows || columns != m.columns){
				throw "The given matrix has different dimensions than the current object.";
	        }	
	        for(int i=0; i<columns; i++){
	        	for(int j=0; j<rows; j++){
	        		this->pt[i][j] = m.pt[i][j];
	        	}
	        }    
	        return *this; 		
		}catch ( const char * e ){
			std :: cout << e << std :: endl ;
		}
	}

	T& operator()(int i, int j){
		return pt[j][i];
	}

	my_matrix operator+(const my_matrix& m){
		try{
	        if(rows != m.rows || columns != m.columns){
				throw "The dimension of the matrix to sum are different.";
	        }
	        my_matrix res(rows, columns);
	        for(int i=0; i<columns; i++){
	        	for(int j=0; j<rows; j++){
	        		res.pt[i][j] = pt[i][j] + m.pt[i][j];	       	
	        	}
	        }

	        return res;
	    }catch (const char * e){
			std :: cout << e << std :: endl ;
		}
	}

	my_matrix& operator+=(const my_matrix& m){

		try{
	        if(rows != m.rows || columns != m.columns){
				throw "The dimension of the matrix to sum are different.";
	        }
	        my_matrix res(rows, columns);
	        for(int i=0; i<columns; i++){
	        	for(int j=0; j<rows; j++){
	        		this->pt[i][j] = pt[i][j] + m.pt[i][j];	       	
	        	}
	        }
	        return *this;
	    }catch (const char * e){
			std :: cout << e << std :: endl ;
		}
	}

	my_matrix operator*(my_matrix<T>& m);

	my_matrix operator|(const my_matrix<T>& m);
};

#endif
