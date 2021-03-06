
#include <iostream>
using namespace std;


void  getmovie(int*, int);
void  Selectionsort(int[], int);
int * CreateArr(int);
int mode(int*, int);
double Median(int*, int);
double Average(int*, int);


int main() {


		int *Arr,
		 	Students;

		cout << "What are the number of students surveyed?\n";
		cin >> Students;
		while (Students < 0)
		{
			cout << "Invalid input.\n What are the number of students surveyed?\n";
			cin >> Students;
		}
		Arr = CreateArr(Students);
		getmovie(Arr, Students);
		cout << "The survey results are: \n";
		cout << "-----------------------\n";
		for (int i = 0; i < Students; i++)
		{
			cout << "Student " << (i + 1) << " watched " << *(Arr + i) << " movies.\n";
		}
		Selectionsort(Arr, Students);
		cout <<"\nMovie Data collected from survey\n";
		cout <<"--------------------------------\n";
		cout << "Average number of movies seen: " << Average(Arr, Students) << endl;
		cout << "Median number of movies: " << Median(Arr, Students) << endl;
		cout << "Mode number of movies: " << mode(Arr, Students) << endl;

		delete [] Arr;

	return 0;
}
//get movie info function
void  getmovie(int array[], int number)
{ int n;
	for (n = 0; n < number; n++)
	{
		cout << "What is the number of movies the student " << (n + 1) << " saw? \n";
		cin >> *(array + n);
		while(*(array + n) < 0)
		{
			cout << "Invalid input.\n What is the number of movies the student " << (n + 1) << " saw?\n";
			cin >> *(array + n);
		}
	}
}
// selection sort function
void Selectionsort(int arr[], int size)
{
	int record,
		minind,
		minval;
	for (record = 0; record < (size - 1); record++)
	{
		minind = record;
		minval = *(arr + record);
		for(int index = record + 1; index < size; index++)
		{
			if (*(arr+ index) < minval)
			{
				minval = *(arr + index);
				minind = index;
			}
		}
		*(arr + minind) = *(arr + record);
		*(arr + record) = minval;
	}
}
//create an array function
int * CreateArr(int i)
{
	int *Arr;
	Arr = new int[i];
	return Arr;
}
// mode function
int mode(int * array, int number)
{

	int *times,
		greatest,
		selection,
		firstcount,
		secondcount,
		x;

	times = CreateArr(number);
	for (x = 0; x < number; x++)
	{
		*(times + x) = 0;
	}
	for (firstcount = 0; firstcount < number; firstcount++)
	{
		for (secondcount = 0; secondcount < number; secondcount++)
		{
			if (*(array + secondcount) == *(array + firstcount))
				(*(times + firstcount))++;
		}
	}
	greatest = * times;
	selection = 0;
	for (x = 1; x < number; x++)
	{
		if (*(times + x) > greatest)
		{
			greatest = *(times + x);
			selection = x;
		}
	}
	if (greatest == 1)
	{
		return -1;
	}
	else
	{
		return *(array + selection);
	}
}
//median function
double Median(int * array, int number)
{
	double Median = 0;
	if (number % 2 == 0)
	{
		Median = (*(array+ (number/2)) + *(array + ((number/2) + 1))) / 2.0;
	}
	else
	{
		Median = *(array+(number/2));
	}
	return Median;
}
//average function
double Average(int array[], int number)
{
	double allmovies = 0;
	double ave;
	for (int i = 0; i < number; i++)
	{
		allmovies = allmovies + *(array + i);
	}
		ave = allmovies / number;
		return ave;

}





