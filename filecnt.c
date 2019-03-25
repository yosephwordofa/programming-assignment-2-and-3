#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
using namespace std;

int main(int argc, char* argv[])
{
	std::cout << argv[1] << std::endl;	
	if  (argc != 2) 
	{
        std::cerr << " no permission to access! " << std::endl;
	exit(1);
	 }

	struct dirent *de;
   	DIR *dir = opendir(argv[1]);
        if(!dir)
	{
	cout << "Incorrect amount of argument! " << endl;
	return 1;
	 }

	unsigned long count=0;
	while(de = readdir(dir))
 	{
		++count;
	 }
	 unsigned long count2=0;
	 struct stat results;

	 while(de != readdir(dir))
	 {// (stat(de, &results) == 0);
	 ++count2;}

//	struct stat results;
	       // if (stat(dir, &results) == 0)
		 //  {     // The size of the file in bytes is in
		// results.st_size
		//	/}             else
		//	{//                     // An error occurred
		//	}
	 //long int res = ftell(dir); 

		closedir(dir);
cout << "The total number of directories in the directory \"" << argv[1] << "\" is: " << count2 << endl;

cout << "The total number of files in directory \"" << argv[1] << "\" is: " << count << endl;

cout << "The total number of bytes occupied by all files in directory \"" << argv[1] << "\"  is: " << endl;

return 0;
}
