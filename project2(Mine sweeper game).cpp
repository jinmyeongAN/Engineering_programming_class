//20161158 An Jin Myeong
#include<iostream>
#include<ctime>
#include<fstream>
#include<cstdlib>

using namespace std;

/*���� ����
	1. ���ڸ� �������� �ֱ�
	2. ���ڰ����� �����ִ� ���� �����
	3. 10x10 ����� ����ã�� �����ֱ�
	4. ���� �Է�--> 1)�����Է�
					2)����-->���ӿ���
					3)'.'ǥ��
					4)invaild
					5)'Q'�� */ 

int main()
{ 
	srand(time(NULL));
	
	string mine_cell[9][9];
	string show_cell[9][9];
	int mine_num=20;
	int room1[mine_num];
	int room2[mine_num];
	int number;//�ֺ��� ���� �� 
	int counter;
	int count;
	int input_num1,input_num2;
	
	 
	//���ڳֱ�. 
	for(int i=1;i<=mine_num;i++)
	{
		while(1)
		{
			room1[i]=rand()%10;
			for(int j=0;j<i;j++)
			{
				if(room1[i]==room1[j])
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
	
	
	
	for(int i=1;i<=mine_num;i++)
	{
		while(1)
			room2[i]=rand()%10;
			for(int j=0;j<i;j++)
			{
				if(room2[i]==room2[j])
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
	
		
		
	for(int i=1;i<=mine_num;i++)
	{
		for(int j=1;j<=mine_num;j++)
		{
			mine_cell[room1[i]][room2[j]]="B";
		}
	}
	
	
	//���� ǥ���ϱ� -->�𸣰ھ�� �̤�
	

	 
	//���ں����ֱ�
	 
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			show_cell[i][j]="#";
			cout<<show_cell[i][j];
		}
		cout<<endl;
	}
	cout<<"Choose one of "<<100-mine_num  <<"mine-free cells: ";
	do
	{
		
		//�����Է�
	cin>>input_num1>>input_num2;
	show_cell[input_num1][input_num2]=mine_cell[input_num1][input_num2];
	for(int i=0;i<=9;i++)
	{
		for(int j=0;j<=9;j++)
		{
			cout<<show_cell[i][j];
		}
		cout<<endl;
	}
		
		
	if(show_cell[input_num1][input_num2]=="."||"1"||"2"||"3"||"4"||"5"||"6"||"7"||"8"||"9")
  		{
  			counter++;
			cout<<"Choose one of "<<100-mine_num-counter  <<"mine-free cells: ";
		  
		}
		
	
	else if(show_cell[input_num1][input_num2]=="B")
		cout<<"BOOM! Game Over.";

	else if(show_cell[input_num1][input_num2]=="Q")
		return 0;
		
	else
		cout<<"Choose again (Enter Q if you want to quit.)";
	
	}while(counter==100-mine_num);
	
	cout<<"Congratulations! You cleared the game.";

	
}
		
		
		
		
		
		
		
		
		
		
		
		
		
	






