#include <iostream>
#include "Stackt.h"
using namespace std;



void Move(int disk, char from, char to)
{
	cout << "Moved disk #" << disk +1 << " from " << from << " to " << to << endl;
}

void TowerOfHanoi(Stackt <int> &source, Stackt <int> &destination, char s, char d)
{

	int temp1 = source.GetTop();
	int temp2 = destination.GetTop();

	
	
	

	if (temp1 == -1)
	{
		source.push(temp2);
		Move(temp2, d, s);
		
	}
	else if (temp2 == -1)

	{
		destination.push(temp1);
		Move(temp1, s, d);
		
	}
	else if (temp1 > temp2)
	{
		source.push(temp1);
		source.push(temp2);
		Move(temp2, d, s);
	}
	else
	{
		destination.push(temp2);
		destination.push(temp2);
		Move(temp1, s, d);

	}


}


void Disk_movement(int n, Stackt <int> source, Stackt <int> auxiliary, Stackt <int> destination )
{
	int moves = pow(2, n) - 1;
	char s = 'S', d = 'D', a = 'A';
	if (n % 2 == 0)
	{
		char temp;
		temp = d;
		d = a;
		a = temp;
	}
	for (int i = n; i >= 1; i--)
	{
		source.push(i);
		
	}
	for (int i = 1; i <= moves; i++)
	{
		if (i % 3 == 0) TowerOfHanoi(auxiliary, destination, a, d);
		else if (i % 3 == 2) TowerOfHanoi(source, auxiliary, s, a);
		else  if (i % 3 == 1) TowerOfHanoi(source, destination, s, d);
	}
}



int main()
{



	int n;

	cout << "please enter the number of disks: ";
	cin >> n;
	cout << endl;
	Stackt <int> source(n);
	Stackt <int> destination(n );
	Stackt <int> auxiliary(n);

	

	Disk_movement(n, source, auxiliary, destination );


	

	return 0;

}