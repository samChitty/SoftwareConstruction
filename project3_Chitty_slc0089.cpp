// Sam Chitty
// slc0089
// project1_Chitty_slc0089.cpp
// compile: g++ project1_Chitty_slc0089.cpp
// run: ./a.out
 
#include <fstream> 
#include <iostream> 
#include <vector> 
using namespace std; 
 
/* declare your user-defined functions */ 
bool check_file(string); 
 
 
 
/* do not forget to describe each function */ 
vector<int> read_file(string); 
 
 
 
 
void write_file(string, vector<int>); 
 
 
 
 
 
vector<int> merge(vector<int>, vector<int>); 
 
 
 
 
/* 
* Display the values of a given vector. 
* 
* Param: file Name of file to display. (string) 
* Param: v Vector containing values to display. (vector<int>) 
*/ 
void to_string(string, vector<int>); 
 
 
 
/* 
* Merge the numbers in two specified files and write all the numbers 
* to a specified third file sorted in ascending order. 
* 
* Return: 1 Program completed successfully. (int) 
*/ 
int main() { 
 /* declare your variables */ 
 string file1;
 string file2;
 string file3; 
 
 /* Get name of file one. */ 
 cout << "*** Welcome Sam's Sorting Program \n";
 do { 
  cout << "Enter file1 name: ";
  cin >> file1;
 } while (cin.fail() || !check_file(file1)); 
 
 /* Get and display numbers from file one. */
 vector<int> numbers1; 
 numbers1 = read_file(file1);
 cout << "The list of "<< numbers1.size() << " numbers in file "<< file1 << " is: \n";
 to_string(file1,numbers1);
 cout << "\n";
 /* Get name of file two. */ 
 do { 
  cout << "Enter file2 name: ";
  cin >> file2; 
 } while (cin.fail() || !check_file(file2)); 
 
 /* Get and display numbers from file two. */
 vector<int> numbers2; 
 numbers2 = read_file(file2); 
 cout << "The list of "<< numbers2.size() << " numbers in file "<< file2 << " is:\n";
 to_string(file2,numbers2);
 cout << "\n";
 /* Combine vectors and display the sorted result. */ 
 vector<int> numbers3;
 numbers3 = merge(numbers1, numbers2); 
 cout << "The sorted list of "<< numbers3.size() << " numbers is ";
 for(int i=0;i<numbers3.size();i++){
   cout << numbers3.at(i) << " ";
 }
 cout << "\n";
 /* Get name of output file. */ 
 do { 
  cout << "Enter output file name: ";
  cin >> file3;
 } while (cin.fail()); 
 /* Write combined vector to output file. */ 
 write_file(file3, numbers3); 
 cout << "*** Please check the new file - "<<file3 <<" ***\n";
 cout << "*** Goodbye. ***";
 cout << "\n";
 
 return 0; 
} 
 
 
 
bool check_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Check whether file exists. */ 
 stream.open(file.c_str()); 
 if (stream.fail()) { 
  cout << "File does not exist.\n";
  //stream.close();
  //throw error or ask again?
  return false; 
 } 
 stream.close(); 
 
 return true; 
} 
 
vector<int> read_file(string file) { 
 /* Input file stream. (ifstream) */ 
 ifstream stream; 
 
 /* Vector containing numbers from file. (vector<int>) */ 
 vector<int> v; 
 
 /* Integer read from file. (int) */ 
 int i; 
 
 /* Add each number in the file to a vector. */ 
 stream.open(file.c_str()); 
 while (stream.good()) { 
  stream >> i;
  v.push_back(i); 
 } 
 v.pop_back();
 stream.close();
 return v; 
} 
 
void write_file(string file, vector<int> v) { 
 /* Output file stream. (ofstream) */ 
 ofstream stream;
 stream.open(file.c_str());
 for(int i=0;i<v.size();i++){
   stream << v.at(i) << "\n";
 } 
 stream.close();
} 
 
vector<int> merge(vector<int> v1, vector<int> v2) { 
 vector<int> output; 
 /* Compare both vectors. */ 
while (v1.size() > 0 && v2.size() > 0) {
  if (v1.at(0) < v2.at(0)) {
    output.push_back(v1.front());
    v1.erase(v1.begin());
}else {
  output.push_back(v2.front());
  v2.erase(v2.begin());
  }
} 
 
 /* Add any remaining numbers from vector one. */ 
 int i;
 if (v1.size()>0) { 
   for(i=0;i<v1.size();i++){
     output.push_back(v1.at(i));
   } 
 } 
 
 /* Add any remaining numbers from vector two. */ 
 if (v2.size()>0) { 
  for(i=0;i<v2.size();i++){
    output.push_back(v2.at(i));
  }
 } 
    
 return output; 
} 



 
void to_string(string file, vector<int> v) { 
 /* Vector interator number. (unsigned short) */ 
 unsigned short i; 
 
 /* Display the numbers contained in a vector. */ 
 for(int i=0;i<v.size();i++){
   cout << v.at(i) << "\n";
 }
} 