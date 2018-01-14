#include <iostream>
#include <chrono>
#include <fstream>
#include <vector>
#include <algorithm> //sort() için

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
	sort(v.begin(), v.end()); // küçükten büyüðe sýralar
	//sort(v.begin(), v.end() , Descending); // büyükten küçüðe sýralar
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
	
	ofstream writer("temel.txt" , ios_base::app); // dosyanýn üzerine yaz
	//ofstream writer("temel.txt"); // dosyayý temizle ve yaz

	int const boyut = 10000;
	int range = 20000;

	steady_clock::time_point start = steady_clock::now(); // saymaya baþla
	
	for(unsigned int i=0;i<boyut;i++)
	{
		vec.push_back(rand()%range);
	}
	SortVector(vec);
	//FindInVector(vec , 5);

	steady_clock::time_point end = steady_clock::now(); // saymayý bitir
	steady_clock::duration elapsed = end - start; // aradaki zaman farkýný al

	if(elapsed == steady_clock::duration::zero())
	{
		cout<<"No Time Elapsed"<<endl<<endl;
	}
	else
	{
		// Deðerleri konsola yaz
		cout<<"Elapsed Nanooseconds Time : "<<duration_cast<nanoseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Microseconds Time : "<<duration_cast<microseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Milliseconds Time : "<<duration_cast<milliseconds>(elapsed).count()<<endl;
		cout<<"Elapsed Seconds Time : "<<duration_cast<milliseconds>(elapsed).count() / 1000.0 <<endl<<endl;
		
		// Deðerleri dosyaya yaz
		writer << "---------------------------------------"<<endl;
		writer << "Size of Array : "<<boyut<<endl;
		writer << "Range of Array : "<<range<<endl<<endl;
		writer << "Elapsed Nanooseconds Time : "<<duration_cast<nanoseconds>(elapsed).count()<<endl;
		writer << "Elapsed Microseconds Time : "<<duration_cast<microseconds>(elapsed).count()<<endl;
		writer << "Elapsed Milliseconds Time : "<<duration_cast<milliseconds>(elapsed).count()<<endl;
		writer << "Elapsed Seconds Time : "<<duration_cast<milliseconds>(elapsed).count() / 1000.0 <<endl;
		
	}

	writer.close(); // dosyayý kapat
	
	system("pause");
	return 0;
}
