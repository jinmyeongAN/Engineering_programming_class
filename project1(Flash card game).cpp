//20161158 An Jin Myeong
#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>


using namespace std;


int main()
{
 
srand(time(NULL));
string input_num;
string word[2][10];
string input_filename;
string input_word;
string output_filename;
int wow[10];
int count;


cout <<"Welcome to JM's Flash Card Program!"<<endl;
cout<<endl;

while(1)
{
cout<<"Menu Options:"<<endl;
cout<<"1) Make flash card set"<<endl;
cout<<"2) Load flash card set"<<endl;
cout<<"3) Show current flash card list"<<endl;
cout<<"4) Practice flash cards (show front side)"<<endl;
cout<<"5) Practice flash cards (show back side)"<<endl;
cout<<"6) Save current flash card set"<<endl;
cout<<"7) Exit program"<<endl;
cout<<"What would you like to do? [input number]: "<<endl;
cin>> input_num; 
while(input_num!="1"&&input_num!="2"&&input_num!="3"
		&&input_num!="4"&&input_num!="5"&&input_num!="6"&&input_num!="7")
	{
		cout<<"Input not recognized..."<<endl;
		cout<<endl;
		cout<<"Menu Options:"<<endl;
		cout<<"1) Make flash card set"<<endl;
		cout<<"2) Load flash card set"<<endl;
		cout<<"3) Show current flash card list"<<endl;
		cout<<"4) Practice flash cards (show front side)"<<endl;
		cout<<"5) Practice flash cards (show back side)"<<endl;
		cout<<"6) Save current flash card set"<<endl;
		cout<<"7) Exit program"<<endl;
		cout<<"What would you like to do? [input number]: "<<endl;
		cin>> input_num; 
	}



//첫번 째 
if(input_num=="1")
	
	{
		Menu1();
	}




//두번째 
else if(input_num=="2")

	{
	cout<<"Enter card set file name (without '.txt'): "<<endl;
	Menu2();
	cout<<"Card set loaded from: "<<input_filename<<".txt"<<endl;
	}





//세 번 째
else if(input_num=="3")
{
	Menu3();
}







//네번째
else if(input_num=="4")
{
	Menu4();
	
	cout<<"Set practice complete."<<endl;
}
	
	
	
	

	
		


//다섯번째
else if(input_num=="5")
{
	Menu5();
	
	cout<<"Set practice complete."<<endl;

}









//여섯번째
else if(input_num=="6")
{
	Menu6();
	
	cout<<"Enter a filename for your card set (without '.txt'): ";

}



//일곱번째
else if(input_num=="7")
{
	cout<<"Program complete.";
	return 0;
} 

}








}

void Menu1()
{
	for(int j=0;j<=9;j++)
	{
		for(int i=0;i<=1;i++)
		{	
			if(i==0)
			{
				cout<<"Enter the front of card "<<j+1<<endl;
				cin.ignore();
				getline(cin,word[i][j]);
			}
			else if(i==1)
			{
				cout<<"Enter the back of card"<<j+1<<endl;
				
				getline(cin,word[i][j]);
			}
		}	
	}
}


void Menu2()
{
	cin.ignore();
	getline(cin,input_filename);
	ifstream file;

	input_filename += ".txt";


	file.open(input_filename.c_str());
		for(int j=0;j<=9;j++)
		{
			for(int i=0;i<=1;i++)
			{
				getline(file,word[i][j]);
		
			}
		}
	file.close();
}


void Menu3()
{
	for(int j=0;j<=9;j++)
	{
		for(int i=0;i<=1;i++)
		{	
			cout<<word[i][j]<<endl;
		
		}
	}
}

void Menu4()
{
	for(int i=0;i<=9;i++)
		{	
		
		
		
			while(1)
			{
				wow[i]=rand()%10;
				for(int j=0;j<i;j++)
				{
					if(word[i]==word[j])
					{
						count++;
						break;
					}
					else
					count=0;
					
				}
				
				if(count==0)
				break;
					
			}
	
		}	
	cin.ignore();
	for(int i=0;i<=9;i++)
		{
			int counter=0;
		
			cout<<word[0][wow[i]]<<": ";
			getline(cin,input_word);
		
			while(word[1][wow[i]]!=input_word)
				 {	
				 	counter++;
					cout<<"Nope, try again."<<endl;
					cin.ignore();
					getline(cin,input_word);
				
				//if(word[1][j]!=input_word)
					
				/*else*/ if(counter==3)
					{
					
					cout<<"Answer: "<<word[1][wow[i]]<<endl;
					//word[1][j]==input_word;
					break;
					}
				}
		
			if(input_word==word[1][wow[i]])
				cout<<"Corret!"<<endl;
	
		}
}

void Menu5()
{
	for(int i=0;i<=9;i++)
	{	
		
		
		
			while(1)
			{
				wow[i]=rand()%10;
				for(int j=0;j<i;j++)
				{
					if(word[i]==word[j])
					{
						count++;
						break;
					}
					else
					count=0;
					
				}
				
				if(count==0)
				break;
					
			}
	
	}
	cin.ignore();
	for(int i=0;i<=9;i++)
		{
			int counter=0;
		
			cout<<word[1][wow[i]]<<": ";
			getline(cin,input_word);
		
			while(word[0][wow[i]]!=input_word)
				 {	
				 	counter++;
					cout<<"Nope, try again."<<endl;
					cin.ignore();
					getline(cin,input_word);
				
				//if(word[1][j]!=input_word)
					
				/*else*/ if(counter==3)
					{
					
					cout<<"Answer: "<<word[0][wow[i]]<<endl;
					//word[1][j]==input_word;
					break;
					}
				}
		
			if(input_word==word[0][wow[i]])
				cout<<"Corret!"<<endl;
	
		}
}

void Menu6()
{
	cin.ignore();
	getline(cin,output_filename);
	ofstream file1;
	output_filename += ".txt";
	file1.open("output_filename");
	for(int j=0;j<=9;j++)
		{
			for(int i=0;i<=1;i++)
			{
				file1<<word[i][j];
		
			}
		}
	file1.close();
}





	
