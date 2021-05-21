#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
vector<string> lines;
vector<double> words_hin(26);
void hindo(void){
	int moji_all=0;
	vector<int> words(26);
	for(int i=0;i<26;i++)words.at(i)=0;
	
	int linesize=lines.size();
	for(int i=0;i<linesize;i++){
		int mojisuu=lines.at(i).size();
		for(int j=0;j<mojisuu;j++){
			char moji=lines.at(i).at(j);
			if((moji<65||moji>90)&&(moji<97||moji>122))continue;
			moji_all++;
			if(moji>64&&moji<91){
				words.at(moji-65)++;
			}else{
				words.at(moji-97)++;
			}
		}

	}
	for(int i=0;i<26;i++){
		words_hin.at(i)=words.at(i)*1.0/(moji_all*1.0);
		cout<<words_hin.at(i)<<endl;
	}

}


void fileopen(void)
{

	string filename;
	cout<<"Plese inputfile"<<endl;
	//cin>>filename;
	filename="heidi_1.txt";
	cout<<filename<<endl;
	filename="./datafile/"+filename;
    
    string line;

    ifstream input_file(filename);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
             << filename << "'" << endl;
        return ;
    }

    while (getline(input_file, line))lines.push_back(line);
   // cout<<lines.at(0)<<endl;
    input_file.close();
	
	
}
int main(void)
{
	fileopen();
	hindo();
	return 0;
}