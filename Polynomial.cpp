/*
KULDEEP NATH
19HCS4029
PROGRAM TO IMPLEMENT ADDITION AND SUBSTRACTION ON POLYNOMIALS
*/
#include<iostream>
using namespace std;

class Polynomial
{
  private:
    // Variables to store information about polynomial
    int *arr;
    int size;
  public:
    Polynomial()
    {
      // Behavior of default constructor
      size = 10;
      arr = new int [size];
    }

    Polynomial(int deg)
    {
      // Behavior of constructor with arguments
      size =deg+1;
      arr = new int[size]; 
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
      
    }
  
    //  Overload copy constructor, +, - and = operators
    Polynomial(const Polynomial &p)
    {
    	size = p.size;
    	for(int i=0;i<size;i++)
    	{
    		arr[i] = p.arr[i];
		}
	}
	Polynomial operator + (const Polynomial&);
	
	Polynomial operator - (const Polynomial&);
	
	// = operator overloading
	Polynomial &operator = (const Polynomial &p1)
	{
		size = p1.size;
		for(int i=0;i<p1.size;i++)
			arr[i] = p1.arr[i];
					
		return *this;
	}
	
    void storePolynomial()
    {
      //  Code to enter and store polynomial
      cout<<"\n\nEnter polynomial ->";
      for(int i=0;i<size;i++)
      {
      		cout<<"\n Co-efficient of x^"<<i<<" : ";
      		cin>>arr[i];
	  }
    }
    void display()
    {
      //  Code to print the polynomial in readable format
      cout<<"\n->Polynomial => ";
      for(int i=size-1;i>=0;i--)
      {
      	char m= ((i)==0)?' ':'+';
      		cout<<"( "<<arr[i]<<"x^"<<i<<" ) "<<m;
	  }
	  
	  cout<<endl;
    }
  
};

// +  operator overloading
Polynomial Polynomial :: operator+ (const Polynomial &p1)
{
	
		int s = (size > p1.size )? size : p1.size;
		int m = (size < p1.size )? size : p1.size;
		int f = (size > p1.size )? 1 : 0;
		Polynomial temp1(s-1);
		
		for(int i=0;i<m;i++)
			temp1.arr[i] = arr[i] + p1.arr[i];
		
		if(f)
			for(int i=m;i<s;i++)
				temp1.arr[i] = arr[i];
		else
			for(int i=m;i<s;i++)
				temp1.arr[i] = p1.arr[i];
				
		return temp1;
}

// -  operator overloading
Polynomial Polynomial :: operator- (const Polynomial &p)
{
		int s = (size > p.size )? size : p.size;
		int m = (size < p.size )? size : p.size;
		int f = (size > p.size )? 1 : 0;
		Polynomial temp(s-1);
		
		for(int i=0;i<m;i++)
			temp.arr[i] = arr[i] - p.arr[i];
		
		if(f)
			for(int i=m;i<s;i++)
				temp.arr[i] = arr[i];
		else
			for(int i=m;i<s;i++)
				temp.arr[i] = -1*p.arr[i];
		
		return temp;
}

int main()
{
  
  // Ask user to input the values of degFirst and degSecond 
  int degFirst, degSecond;
  cout<<"\nEnter degree of 1st polynomial : ";
  cin>>degFirst;
  cout<<"\nEnter degree of 2nd polynomial : ";
  cin>>degSecond;
  

  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  // Entering values into first and second polynomial
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  // + operator overloading
  thirdPolynomial=firstPolynomial+secondPolynomial;
  // - operator overloading
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  //Displaying all the polynomials
  firstPolynomial.display();
  secondPolynomial.display();
  thirdPolynomial.display();
  fourthPolynomial.display();
  
  return 0;
}
