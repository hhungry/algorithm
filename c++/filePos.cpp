#include <iostream>
#include<fstream>
#include<cassert>
#include<string>
using namespace std;

int main()
{
    char filename[]="test.txt";
    ifstream ifile(ifilename,ios::ate);
    cout<<ifile.tellg()<<endl;

    ifile.seekg(0,ios::end);
    //sp:file size
    streampos sp1=ifile.tellg();
    cout<<sp1<<endl;

    ifile.seekg(2*sp1/3,ios::beg);
    //sp2:2/3 file size
    streampos sp2=ifile.tellg();
    cout<<sp2<<endl;

    //read all file content
    ifile.seekg(0,ios::beg);
    cout<<ifile.rdbuf()<<endl;

    ifile.seekg(sp2,ios::beg);

    //function rdbuf() read file content from cur pointer
    cout<<ifile.rdbuf()<<endl;

    //after reading operation the current pointer arrive the file end
    cout<<ifile.tellg()<<endl;

//    ofstream ofile(filename,ios::out);
//    ofile.seekp(0,ios::beg);
//    ofile<<"hello";
//    cout<<ofile.tellp()<<endl;
//
//    ofile.seekp(-4,ios::end);
//    ofile<<"nihao";


    return 0;
}
