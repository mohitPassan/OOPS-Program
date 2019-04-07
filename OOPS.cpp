#include <iostream>
using namespace std;

class Complex			//class having data and functions for complex numbers
{
	int real,imag;			//variables to store real and imaginary part of the complex number
	public:
		void getData(int a,int b)		//initialising the variables
		{
			real = a;
			imag = b;
		}
		Complex operator+(Complex &ob)		//overloading the '+' operator
		{
			Complex result;
			result.real = this->real + ob.real;
			result.imag = this->imag + ob.imag;
			return result;
		}
		Complex operator-(Complex &ob)			//overloading the '-' operator
		{
			Complex result;
			result.real = this->real - ob.real;
			result.imag = this->imag - ob.imag;
			return result;
		}
		Complex operator*(Complex &ob)			//overloading the '*' operator
		{
			Complex result;
			result.real = (this->real*ob.real) - (this->imag*ob.imag);
			result.imag = (this->real*ob.imag) + (this->imag*ob.real);
			return result;
		}
		friend ostream& operator<<(ostream &ss,Complex ob);			//declaring this function as friend so that it can access private members
};

class Matrix 			//class storing data and functions of a 3x3 matrix
{
	int arr[3][3];			//a 3x3 array for storing elements
	public:
		void getData()			//function to get data from  user
		{
			cout << "enter 9 elements:" << endl;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					cin >> arr[i][j];
				}
			}
		}
		Matrix operator+(Matrix &ob)			//overloading the '+' operator
		{
			Matrix result;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					result.arr[i][j] = this->arr[i][j] + ob.arr[i][j];
				}
			}
			return result;
		}
		Matrix operator-(Matrix &ob)			//overloading the '-' operator
		{
			Matrix result;
			for(int i=0;i<3;i++)
			{
				for(int j=0;j<3;j++)
				{
					result.arr[i][j] = this->arr[i][j] - ob.arr[i][j];
				}
			}
			return result;
		}
		Matrix operator*(Matrix &ob)			//overloading the '*' operator
		{
			Matrix result;
			for (int i=0;i<3;i++) 
		    { 
		        for (int j=0;j<3;j++) 
		        { 
		            result.arr[i][j] = 0; 
		            for (int k=0;k<3;k++) 
		            {
		                result.arr[i][j] += this->arr[i][k] *  ob.arr[k][j]; 
		            }
		        } 
		    }
			return result;
		}
		friend ostream& operator<<(ostream &ss,Matrix ob);			//declaring this function as friend so that it can access private members
};

ostream& operator<<(ostream &ss,Complex ob)			//overloading stream insertion operator from complex class
{
	ss << ob.real << " + " << ob.imag << "i" << endl;
	return ss;
}

ostream& operator<<(ostream &ss,Matrix ob)			//overloading stream insertion operator from matrix class
{
	for(int i=0;i<3;i++)
	{
        for(int j=0;j<3;j++)
        {
           	ss << ob.arr[i][j] << " ";
        }
        ss << endl;
	}
	return ss;
}

int main()
{
	int ch;			//variable to choose from complex or matrix arithmetic
	char cont='y',op;			//cont wil decide when to end the loop and op stores the operation to be performed
	do
	{
		cout << "Chooose one of the following:\n1.) Complex Arithmetic\n2.) Matrix Arithmetic" << endl;
		cin >> ch;
		switch(ch)
		{
			case 1:			//for complex arithmetic
				Complex Cob1,Cob2;		//declaring two objects of Complex class
				int r,i;
				cout << "Enter the real and imaginary part of first Complex number:" << endl;
				cin >> r >> i;
				Cob1.getData(r,i);		//taking data for first object
				cout << "Enter the real and imaginary part of second Complex number:" << endl;
				cin >> r >> i;
				Cob2.getData(r,i);		//taking data for second object
				cout << "Choose the operation (+,-,*):" << endl;
				cin >> op;
				switch(op)
				{
					case '+':
						cout << "Answer = " << Cob1+Cob2 << endl;
						break;
					case '-':
						cout << "Answer = " << Cob1-Cob2 << endl;
						break;
					case '*':
						cout << "Answer = " << Cob1*Cob2 << endl;
						break;
				}
				cout << "Do you want to continue? (y/n)" << endl;
				cin >> cont;
				break;
			case 2:			//for matrix arithmetic
				Matrix Mob1,Mob2;		//declaring two objects of Matrix class
				cout << "For first matrix ";
				Mob1.getData();		//taking data for first matrix
				cout << "For second matrix ";
				Mob2.getData();		//taking data for second matrix
				cout << "Choose the operation (+,-,*):" << endl;
				cin >> op;
				switch(op)
				{
					case '+':
						cout << "Answer:" << endl << Mob1+Mob2 << endl;
						break;
					case '-':
						cout << "Answer:" << endl << Mob1-Mob2 << endl;
						break;
					case '*':
						cout << "Answer:" << endl << Mob1*Mob2 << endl;
						break;
				}
				cout << "Do you want to continue? (y/n)" << endl;
				cin >> cont;
				break;
		}

	}while(cont == 'y');
}