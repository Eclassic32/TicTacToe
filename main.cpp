#include <iostream>
#include <string>
using namespace std;
char p1,p2,p3,p4,p5,p6,p7,p8,p9, w;
void screen() // Состояние ячеек на данный момент
{
  cout << endl;
	cout << p7 << " | " << p8 << " | "<< p9 << endl;
	cout << "--+---+--" << endl;
	cout << p4 << " | " << p5 << " | "<< p6 << endl;
	cout << "--+---+--" << endl;
	cout << p1 << " | " << p2 << " | "<< p3 << endl << endl;
}
void p_X() // Ход Игрока_X
{
  char e, x;
  string s;
  do { //Не дает перезаписать ячейку （Предохранитель)
    x=0;
	  do {
		  cout << "Player_X turn: ";
	  	cin >> s;
      e=s[0];
		  if (e>'9' || e<'1')
		  	cout << "Try Again. ";
	  } while (e>'9' || e<'1');
  	switch (e) // Придает ячейке значение 'Х'
	  {
	    case '1': if (p1=='1') {p1='X'; break;} else x='1';
      case '2': if (p2=='2') {p2='X'; break;} else x='1';
		  case '3': if (p3=='3') {p3='X'; break;} else x='1';
      case '4': if (p4=='4') {p4='X'; break;} else x='1';
  		case '5': if (p5=='5') {p5='X'; break;} else x='1';
      case '6': if (p6=='6') {p6='X'; break;} else x='1';
	  	case '7': if (p7=='7') {p7='X'; break;} else x='1';
      case '8': if (p8=='8') {p8='X'; break;} else x='1';
      case '9': if (p9=='9') {p9='X'; break;} else x='1';
	  }
    if (x=='1')
      cout << "Here is something placed. Please, Try Again. ";
  } while (x=='1');
}
void p_O() // Ход Игрока_О
{
  char e, x;
  string s;
  do { //Не дает перезаписать ячейку (Предохранитель)
    x=0;
	  do {
  	cout << "Player_O turn: ";
	  cin >> s;
    e=s[0];
  	if (e>'9' || e<'1')
		  cout << "Try Again. ";
	  } while (e>'9' || e<'1');
  	switch (e) // Придает ячейке значение 'О'
	  {
	  	case '1': if (p1=='1') {p1='O'; break;} else x='1';
      case '2': if (p2=='2') {p2='O'; break;} else x='1';
		  case '3': if (p3=='3') {p3='O'; break;} else x='1';
      case '4': if (p4=='4') {p4='O'; break;} else x='1';
  		case '5': if (p5=='5') {p5='O'; break;} else x='1';
      case '6': if (p6=='6') {p6='O'; break;} else x='1';
	  	case '7': if (p7=='7') {p7='O'; break;} else x='1';
      case '8': if (p8=='8') {p8='O'; break;} else x='1';
      case '9': if (p9=='9') {p9='O'; break;} else x='1';
	  }
    if (x=='1')
      cout << "Here is somethink placed. Please, Try Again. ";
  } while (x=='1');
}
void check() // Проверка выигрышного состаяния
{
	if ((p1==p2 && p2==p3) || (p1==p4 && p4==p7)) // |_
		w=p1;
	else if ((p3==p6 && p6==p9) || (p7==p8 && p8==p9)) // "|  
  	w=p9;
	else if ((p2==p5 && p5==p8) || (p4==p5 && p5==p6)) // +
	  w=p5;
	else if ((p1==p5 && p5==p9) || (p3==p5 && p5==p7)) // X
	  w=p5;
	else 
		w=0;
}
int main()
{
	p1='1'; p2='2'; p3='3'; // Начальное 
	p4='4'; p5='5'; p6='6'; // значения
	p7='7'; p8='8'; p9='9'; // ячеек
  cout << "█████ █████  ████    █████  ███   ████    █████  ███  ████" << endl; // Красивое
  cout << "  █     █   █          █   █   █ █          █   █   █ █   " << endl; // название
  cout << "  █     █   █     ███  █   █████ █     ███  █   █   █ ████" << endl;  
  cout << "  █     █   █          █   █   █ █          █   █   █ █   " << endl;  
  cout << "  █   █████  ████      █   █   █  ████      █    ███  ████" << endl; 
	cout << endl << endl << "You need to use Num.Pad" << endl; screen();
	p_X(); screen();  //Ход 1
 	p_O(); screen();  //Ход 2
  p_X(); screen();  //Ход 3 
 	p_O(); screen();  //Ход 4
  for (int i=0; i<2; i++)
  {
  	p_X(); screen(); check();  //Ход 5 и 7
	  if (w=='X') 
	    { cout << "Winner is Player_" << w;  return 0; }
  	p_O(); screen(); check();  //Ход 6 и 8
  	if (w=='O') 
  	  { cout << "Winner is Player_" << w;  return 0; }
  }
	p_X(); screen(); check(); //Ход 9
	if (w=='X')
	  cout << "Winner is Player_" << w;
	else
		cout << "We not Winn Winner";
	return 0;
}