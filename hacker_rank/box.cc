#include<bits/stdc++.h>

using namespace std;
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box

// The class should have the following functions : 
class Box {
    int length;
    int breadth;
    int height;
public:
    // Constructors: 
    Box(): length(0), breadth(0), height(0) {
    }
    Box(int l, int b, int h) : length(l), breadth(b), height(h) {
    }
    Box(const Box& other)
        : length(other.length)
        , breadth(other.breadth)
        , height(other.height) {     
    }
    Box& operator=(const Box& other) {
        this->length = other.length;
        this->breadth = other.breadth;
        this->height = other.height;
        return *this;
    }
    int getLength() const { return length; } // Return box's length
    int getBreadth () const { return breadth; } // Return box's breadth
    int getHeight () const { return height; }  //Return box's height
    long long CalculateVolume() const {
        // Return the volume of the box
        return (long long)length * breadth * height;
    }

    //Overload operator < as specified
    bool operator<(Box& b) const {
        return (this->length < b.length
            || (this->breadth < b.breadth && this->length == b.length)
            || (this->height < b.height && this->breadth == b.breadth && this->length == b.length)
            );
    }
};

//Overload operator << as specified
ostream& operator<<(ostream& out, Box& B) {
    out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
    return out;
}


void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
	check2();
}
