#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cmath>
#include <ctime>

using namespace std;

int absolute(int x)
{
	if(x < 0)
		return -x;
	return x;	
}

int main(int argc, char** argv) {
	
	time_t timestamp;
	
	string filename1, filename2;
	fstream file1, file2;
	fstream log;
	log.open("log.txt", ios::out|ios::app);
	
	string var1, var2;
	//XOR var to compare XOR between elements (difference)
	char XOR;
	//Counter - how many bits differ
	int counter = 0;
	//Amount - how many bits are compared
	long amount = 0;
	
	struct timeval begin, end;
	//If there is a file1
	do
	{
		cin >> filename1;
		file1.open( filename1, ios::in | ios::out );
		if( file1.good() )
    		break;
		cout << "There is no file with that name! Repeat the name\n";
	}while(true);
	//If there is a file2
	do
	{
		cin >> filename2;
		file2.open( filename2, ios::in | ios::out );
		if( file2.good() )
    		break;
		cout << "There is no file with that name! Repeat the name\n";
	}while(true);
	//Setting the timer
	gettimeofday(&begin, 0);
	//Loop to count every line before one ends
	while( !file1.eof() && !file2.eof() )
	{
		getline( file1, var1);
		getline( file2, var2);
		//Loop to count 
		for(int i=0; i<min(var1.length(),var2.length()); i++)
		{
			//Using XOR loop to count how many bits differ
			XOR = var1[i] ^ var2[i];
			while( XOR )
			{
				XOR = XOR & (XOR - 1);
				counter++;
			}
			amount += 8;
		}
		//Adding 8 bits per every extra element
		counter += absolute(var1.length()-var2.length())*8;
	
	}
	//If file1 is shorter than file2
	if( file1.eof() )
	{
		while( !file2.eof() )
		{
			getline( file2, var2);
			counter += var2.length()*8;
		}
	}
	//If file2 is shorter than file1
	if( file2.eof() )
	{
		while( !file1.eof() )
		{
			getline( file1, var1);
			counter += var1.length()*8;
		}
	}
	
	file1.seekg(0, ios::end);
	file2.seekg(0, ios::end);
	
	timestamp = time(nullptr);
	cout << asctime(localtime(&timestamp)) << endl;
	log << asctime(localtime(&timestamp)) << endl;
	
	cout << amount << endl;
	log << amount << endl;
	cout << counter << endl;
	log << counter << endl;
	cout << (double)counter/((file1.tellg()+file2.tellg())*8) << endl;
	log << (double)counter/((file1.tellg()+file2.tellg())*8) << endl;
	
	file1.close();
	file2.close();
	gettimeofday(&end, 0);
	
	double elapsed = end.tv_sec - begin.tv_sec + (end.tv_usec - begin.tv_usec)*1e-6;
	cout << elapsed << endl;
	log << elapsed << endl << endl;
	
	log.close();
	return 0;
}
