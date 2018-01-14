#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm> //sort() i�in

using namespace std;
using namespace std::chrono;

void FindInVector(vector<int> v , int search)
{
	for (unsigned int i = 0; i < v.size(); ++i)
	{
		if (v[i] == search)
		{
			cout << "Found: " << v[i] << " at position: " << i << endl;
		}
	}
	cout<<endl<<endl;
}

bool Descending(int first, int second)
{
	return first > second;
}

void SortVector(vector<int> v)
{
	sort(v.begin(), v.end()); // k���kten b�y��e s�ralar
	//sort(v.begin(), v.end() , Descending); // b�y�kten k����e s�ralar
	/*
	for (auto& value : v)
	{
		cout << value << endl;
	}
	*/
}


int main()
{
	
	srand(unsigned int(time(0)));
	
	vector<int> vec;
	
	ofstream writer("temel.txt" , ios_base::app); // dosyan�n �zerine yaz
	//ofstream writer("temel.txt"); // dosyay� temizle ve yaz

	int const boyut = 10000;
	int range = 20000;

	steady_clock::time_point start = steady_clock::now(); // saymaya ba�la
	
	for(unsigned int i=0;i<boyut;i++)
	{
		vec.push_back(rand()%range);
	}
	SortVector(vec);
	//FindInVector(vec , 5);

	steady_clock::time_point end = steady_clock::now(); // saymay� bitir
	steady_clock::duration elapsed = end - start; // aradaki zaman fark�n� al

	if(elapsed == steady_clock::duration::zero())
	{
		cout<<"No Time Elapsed"<<endl<<endl;
	}
	else
	{
		// De�erleri konsola yaz
		cout<<"Elapsed Nanooseconds Time : "<<duration_cast<nanoseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Microseconds Time : "<<duration_cast<microseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Milliseconds Time : "<<duration_cast<milliseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Seconds Time : "<<duration_cast<milliseconds>(elapsed).count() / 1000.0 <<endl<<endl;
		
		// De�erleri dosyaya yaz
		writer << "---------------------------------------"<<endl;
		writer << "Size of Array : "<<boyut<<endl;
		writer << "Range of Array : "<<range<<endl<<endl;
		writer << "Elapsed Nanooseconds Time : "<<duration_cast<nanoseconds>(elapsed).count()<<endl;
		writer << "Elapsed Microseconds Time : "<<duration_cast<microseconds>(elapsed).count()<<endl;
		writer << "Elapsed Milliseconds Time : "<<duration_cast<milliseconds>(elapsed).count()<<endl;
		writer << "Elapsed Seconds Time : "<<duration_cast<milliseconds>(elapsed).count() / 1000.0 <<endl;
		
	}

	writer.close(); // dosyay� kapat
	
	system("pause");
	return 0;
}
