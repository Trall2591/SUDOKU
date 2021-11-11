#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include<windows.h>
#define n 9
#define m 9

	void transpon(char mas[n][m], char copy_mas[n][m]);
	void mashing(char mas[n][m], char copy_mas[n][m], int number);
	void keyboard_input(char mas[n][m], char copy_mas[n][m], int number);
	int valid(char mas[][9], int i, int j, char valid_number);
	int source(char mas[][9]);
	void number_check(char mas[n][m], char copy_mas[n][m], char valid_number_2, int x, int y, int x1, int y1, int *temp);
int main(){
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
		int i, j, s, y,number,block=0;
		char vivod_file[1000];
	    char mas[n][m];
	    char copy_mas[n][m];
	    FILE *f;
		srand(time(0));
	while(1){
//____________________________________________________________________________Вивід головного меню
			SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
			printf("\nEnter level of difficult:    [1] [2] [3]: \n");
			printf("\nFor finisch enter:           [4]: \n");
			printf("\nFor find out the RULES enter:[9]: \n");
			printf("\nYour number: ");
			SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
			
			number=getch();
		switch(number){
			case '1': number=1;break;
			case '2': number=2;break;
			case '3': number=3;break;
			case '4': number=4;return 0;
			case '9': number =9;break;
			default: system("cls");continue;
		}
		system("cls");
//_________________________________________________________________________	
//-----------------------------------------------------Вивід правил з файлу
		if(number==9){
			f = fopen("Rules.txt", "r");
			if(f==NULL){
					printf("\nEror!"); return;
				}
			while(fgets(vivod_file, 1000, f)!=NULL){
					SetConsoleTextAttribute(console, FOREGROUND_GREEN);
					puts(vivod_file);
					SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
				}
				fclose(f);
				getch();
				system("cls");
			continue;
		}
//----------------------------------------------------Заповнення матриці
			for(i=0; i<n; i++){
				for(j=0; j<m; j++){
					mas[i][j] = ((i*3+i/3+j)%(3*3)+1)+'0';//Алгоритм заповнення матриці числами так, щоб вони не перетиналися
				}
			}
			keyboard_input(mas, copy_mas, number);
		}
	}

//***************************************************************************
void transpon(char mas[n][m], char copy_mas[n][m]){
	char mas2[n][m];
	int i, j, count=0, count2=0, block=0, r, s;
	char temp[n];
//-----------------------------------------------------Транспонування матриці
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			mas2[j][i]=mas[i][j];
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			mas[i][j]=mas2[i][j];
		}
	}
//--------------------------------------------------------------Тасовка рядків
		r=0+rand()%3;
		do
		{
			s=1+rand()%9;
		}while(s%3!=0);
		for(i=0; i<n; i++){
			if((i%s)==0){
				for(j=0; j<m; j++){
						temp[i]=mas[i][j];
						mas[i][j]=mas[i+r][j];
						mas[i+r][j]=temp[i];
					}
				}
			}
//----------------------------------------------------------Тасовка стовпців
		r=0+rand()%3;
		do
		{
			s=1+rand()%9;
		}while(s%3!=0);
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			if((j%s)==0){
				temp[i]=mas[i][j];
				mas[i][j]=mas[i][j+r];
				mas[i][j+r]=temp[i];
			}
		}
	}
	for(i=0; i<n; i++){
		for(j=0; j<m; j++){
			copy_mas[i][j]=mas[i][j];
		}
	}
}

//----------------------------------------------Рандомне затерання чисел
void mashing(char mas[n][m], char copy_mas[n][m], int number){
	transpon(mas, copy_mas);
		int i,j, s=0, r=0, k=0;
	//__________________________________________Перша складність
			if(number==1){
				for(i=0; i<n; i++){
					for(j=0; j<m; j++){
						if(mas[i][j]=='1'||mas[i][j]=='2'||mas[i][j]=='3'||
						mas[i][j]=='4'||mas[i][j]=='5'||mas[i][j]=='6'||
						mas[i][j]=='7'||mas[i][j]=='8'||mas[i][j]=='9'){
							s=rand()%2;
							r=rand()%2;
							mas[i+s][j+r]='-';
						}
					}
				}
				
			}
	//__________________________________________Друга складність
			if(number==2){
				for(i=0; i<n; i++){
					for(j=0; j<m; j++){
						if(mas[i][j]=='1'||mas[i][j]=='2'||mas[i][j]=='3'||
						mas[i][j]=='4'||mas[i][j]=='5'||mas[i][j]=='6'||
						mas[i][j]=='7'||mas[i][j]=='8'||mas[i][j]=='9'){
							s=rand()%4;
							r=rand()%4;
							mas[i+s][j+r]='-';
						}
					}
				}
			}
	//__________________________________________Третя складність
			if(number==3){
					for(i=0; i<n; i++){
						for(j=0; j<m; j++){
						if(mas[i][j]=='1'||mas[i][j]=='2'||mas[i][j]=='3'||
							mas[i][j]=='4'||mas[i][j]=='5'||mas[i][j]=='6'||
							mas[i][j]=='7'||mas[i][j]=='8'||mas[i][j]=='9'){
								s=rand()%10;
								r=rand()%10;
								mas[i+s][j+r]='-';
							}
						}
					}
			}
	
}
//---------------------------------------ввід з клавіатури чисел в поле матриці
void keyboard_input(char mas[n][m], char copy_mas[n][m], int number){
		mashing(mas, copy_mas, number);
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 
	int i,j,count=0, count2=0, move, s=0, temp=0, x=0,y=0, flag=0,x1, y1, i1, j1, kol_chisel;
	int ch=1+rand()%80;// Число яке знахотиться в переменній вказує на номер комірки, на якій зупинеться курсор (Коли "ch" відповідатиме "s")
	char mas3[n][m]={' '}, valid_number_2=0;
	//________________Копіюємо матрицю для подальшої вставки в Алгоритм, який сам може вирішити правильно поле судоку
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			mas3[i][j]=mas[i][j];
		}
	}
	//________________
	while(flag!=2)
		{if(ch<0){ch+=9;}
		else if(ch>80){ch-=9;}// встановлюємо межі поля, щоб курсор не вийшов за них
		kol_chisel=0;
//_________________________________Вивід на екран
		for(i=0,i1=0; i<n,i1<n; i++, i1++){
				for(j=0,j1=0; j<m, j1<m; j++, j1++){
					count++;
					if(s==ch&&temp==0){	
							SetConsoleTextAttribute(console, FOREGROUND_GREEN);
							printf("[%c]", mas[i][j]);//Якщо ми ввели правильну цифру
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							x=i; y=j;
							x1=i1; y1=j1;
						}
					else if(s==ch&&temp<3){
							SetConsoleTextAttribute(console, FOREGROUND_RED);
							printf("[%c]", mas[i][j]);//Якщо ми ввели не правильну цифру
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
							x=i; y=j;
							x1=i1; y1=j1;
						}
					else if(mas[i][j]!='-'&&mas[i][j]!=copy_mas[i1][j1]&&temp!=3){
							SetConsoleTextAttribute(console, FOREGROUND_RED);
							printf("[%c]", mas[i][j]);//Якщо ми ввели не правильну цифру і пішли курсором далі не змінюючи її
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
					else if(temp==3){	
							SetConsoleTextAttribute(console, FOREGROUND_GREEN);
							printf("[%c]", mas[i][j]);//Якщо ми попросили програму самій вирішити нашу гру
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
					else{	
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN);
							printf(" %c ", mas[i][j]);//Не зміння числа в матриці які програма згенерувала сама
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
					
					if(mas[i][j]=='-'){
							kol_chisel++;//Підрахунок кількості невідомих чисел
						}
					//_______________________Малюємо поле гри
					if(count%3==0){
							SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
								printf("|");
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
						s++;//переменна являється щотчиком, коли вона зустрічається із переменною "ch"б в той момент ми висвітлюємо на екран наш курсор на полю "[ ]"
				}
						printf("\n");
						count2++;
					if(count2%3==0){
							SetConsoleTextAttribute(console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE);
								printf("+--------+---------+---------+\n");
							SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						}
					//_________________________
			}
				printf("\nKol-[%i]", kol_chisel);
				printf("\nReturn to the main menu  [N]!\n");
				printf("\nFor HELP enter [H]!\n");
				printf("\nPress [Y] to solve!\n");			
			if(kol_chisel==0&&mas[x][y]==copy_mas[x1][y1]){
					printf("\nYOU WIN\n");
				}
//________________________________________________
			if(temp<3&&temp>0){//перевірка на правильність введеного числа в комірку матриці
					SetConsoleTextAttribute(console, FOREGROUND_RED);
						printf("\nYou entered incorrect number! Try again!");
					SetConsoleTextAttribute(console, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
						temp=0;
				}
			move=getch();
			switch(move){
			//_________________________________________Управління з клавіатури
					case'W':
					case'w':{ch-=9;s=0;};break;
					case'S':
					case's':{ch+=9;s=0;};break;
					case'A':
					case'a':{ch-=1;	s=0;};break;
					case'D':
					case'd':{ch+=1;s=0;};break;
			//__________________________________________
					case'N':
					case'n': {flag=2;s=0;}break;//Якщо користувач хоче вийти в головне меню
					case'H':
					case'h': {mas[x][y]=copy_mas[x1][y1];s=0;}break;//Якщо користувач скористався підказкою
					case 'Y':
					case 'y':  {for(i=0; i<n; i++){
									for(j=0; j<n; j++){
										mas[i][j]=mas3[i][j];
									}
								}
								source(mas);s=0;temp=3;}break;//Викликаємо функцію source(mas), з алгоритмом вирішення поля судоку, якщо користувач забажав щоб програма вирішила нашу матрицю сама
							
					case'1': if(mas[x][y]=='-' || copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='1';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'2': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='2';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'3': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='3';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'4': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='4';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'5': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='5';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'6': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='6';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'7': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='7';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'8': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='8';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
					case'9': if(mas[x][y]=='-'|| copy_mas[x1][y1]!=mas[x][y]){
									valid_number_2='9';
									number_check(mas,copy_mas,valid_number_2,x,y,x1,y1,&temp);//перевірка правильності введеного числа!
									s=0;break;
								}
				}
				s=0;system("cls");
	}
}
//*************************************************************************Алгоритм рішення поля судоку
int valid(char mas[][9], int i, int j, char valid_number){//Перевірка, чи число, яке ми хочемо поставити в комірку матриці, є валідним
	int count, row1=0, kol1=0, block=0;
		//__________________________________Перевірка рядків
		for(count=0; count<9; count++){
			if(mas[i][count]==valid_number){
				row1++;
			}
		}
		//__________________________________Перевірка стовпців
		for(count=0; count<9; count++){
			if(mas[count][j]==valid_number){
				kol1++;
			}
		}
		//__________________________________Перевірка блоків
		for(count=0; count<9; count++){
			if(mas[3*(i/3)+count/3][3*(j/3)+count%3]==valid_number){
				block++;
			}
		}
		if(row1==0&&kol1==0&&block==0){
			return 1;
		}else return 0;
}

int source(char mas[][9]){//Рекурсивний алгоритм підстановки числа в комірку матриці
	int i, valid_number, j;
	for(i=0; i<9; i++){
		for(j=0; j<9; j++){
			if(mas[i][j]=='-'){
				for(valid_number='1'; valid_number<='9'; valid_number++){
					if(valid(mas,i,j, valid_number)){
						mas[i][j]=valid_number;
						if(source(mas)){
							return 1;//Якщо число валідне
						}
						mas[i][j]='-';//Якщо число не валідне
					}	
				}
				return 0;
			}
		}		
	}
	return 1;	
}
//*****************************************************************************

void number_check(char mas[n][m], char copy_mas[n][m], char valid_number_2, int x, int y, int x1, int y1, int *temp){//Перевірка правильності введеного числа!
		mas[x][y]=valid_number_2;
	if(mas[x][y]!=copy_mas[x1][y1]){
			*temp+=1;
		}
	else{
			*temp=0;
		}
}
