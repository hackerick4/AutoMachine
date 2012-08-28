#include <stdio.h> 
#include <stdlib.h> 
#include <conio.h> 
#include <Windows.h>

int hulu_x=0,hulu_y=0;
int button_x=0, button_y=0;
int onepress_x=0,onepress_y=0;
int commit_x=0,commit_y=0;
int pick_x = 0,pick_y=0;
int sold_x = 0 , sold_y=0;
int cancel_x = 0, cancel_y=0;

char ch;
 POINT ms;
 MSG msg;

void Clr(){
 COORD coordScreen = { 0, 0 }; 
 DWORD cCharsWritten; 
 CONSOLE_SCREEN_BUFFER_INFO csbi; 
 DWORD dwConSize; 
 HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 GetConsoleScreenBufferInfo(hConsole, &csbi); 
 dwConSize = csbi.dwSize.X * csbi.dwSize.Y; 
 FillConsoleOutputCharacter(hConsole, TEXT(' '),
  dwConSize, 
  coordScreen,
  &cCharsWritten); 
 GetConsoleScreenBufferInfo(hConsole, &csbi); 
 FillConsoleOutputAttribute(hConsole,
  csbi.wAttributes,
  dwConSize,
  coordScreen,
  &cCharsWritten); 
 SetConsoleCursorPosition(hConsole, coordScreen); 
}

void fetchCusorPosition(int *x,int*y){
 
 char ch;
 while (!kbhit()){
   GetCursorPos(&ms);
   printf("Mouse Cursor Coordinate at (%d, %d)\n按任意鍵依序取得座標\n========hackerick4製作(暗殺者聯盟)===================\n\n", ms.x, ms.y); 
   printf("白葫蘆中心點座標為(%d,%d)\n", hulu_x,hulu_y);
   printf("一鍵拾取中心點座標為(%d,%d)\n",pick_x ,pick_y);
   printf("一鍵賣出中心點座標(%d,%d)\n",sold_x , sold_y);
   printf("裝備入魂中心點座標為(%d,%d)\n",button_x,button_y);
   printf("一鍵吸收中心點座標為(%d,%d)\n",onepress_x,onepress_y);
   printf(" '確定' 中心點座標為(%d,%d)\n",commit_x,commit_y);
   printf("關閉一鍵入魂的X中心點座標(%d,%d)\n",cancel_x,cancel_y);
  Sleep(100); //降低CPU使用率
  system("cls"); //用了CPU使用率會升高 
 }
 ch=getch();
 *x = ms.x;
 *y=ms.y;
 
}
void click(int x ,int y){
	 Sleep(900);
 SetCursorPos(x,y);
 mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
}

int main(){
 POINT ms;
 MSG msg;
fetchCusorPosition(& hulu_x,&hulu_y);
fetchCusorPosition(&pick_x,&pick_y);
fetchCusorPosition(&sold_x,&sold_y);
fetchCusorPosition(&button_x,&button_y);
 fetchCusorPosition(&onepress_x,&onepress_y);
  fetchCusorPosition(&commit_x,&commit_y);
  fetchCusorPosition(&cancel_x,&cancel_y);
  printf("----------------result--------------\n");
printf("白葫蘆中心點座標為(%d,%d)\n", hulu_x,hulu_y);
   printf("一鍵拾取中心點座標為(%d,%d)\n",pick_x ,pick_y);
   printf("一鍵賣出中心點座標(%d,%d)\n",sold_x , sold_y);
   printf("裝備入魂中心點座標為(%d,%d)\n",button_x,button_y);
   printf("一鍵吸收中心點座標為(%d,%d)\n",onepress_x,onepress_y);
   printf(" '確定' 中心點座標為(%d,%d)\n",commit_x,commit_y);
   printf("關閉一鍵入魂的X中心點座標(%d,%d)\n",cancel_x,cancel_y);
   printf("=======================================================");
   long int time = 0;
   printf("請輸入養魂多少次 輸入1000則自動養魂1000次 : ");
   scanf("%d",&time);

  printf("-------------按任意鍵後繼續  5秒鐘後開始啟動程式  --------------\n");
 ch=getch();
 Sleep(3000);
 for (int i = 0 ; i < time ; ++i){
	 SetCursorPos(hulu_x,hulu_y);
	 for (int i = 0; i <16 ; ++i){
	 mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
	 Sleep(700);
	 }
	 click(pick_x ,pick_y);
	 click(sold_x , sold_y);
	 click(button_x,button_y);
	 click(onepress_x,onepress_y);
	  click(commit_x,commit_y);
	   click(cancel_x,cancel_y);
 
 }

 system("pause");
 return 0;
}
