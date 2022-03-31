//to create a game  world using c program to include more than 1 game in single program

//declaration of header files
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include<ctype.h>
#include <process.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

//delay function

void delay(int second)
{
    int millsec = 1000*second;
    clock_t startTime = clock();
    while
        (clock()<(startTime+millsec));
}
//game 1 tic tac toe

//declaration of functions

char square[10]={'0','1','2','3','4','5','6','7','8','9',};
int checkwin();
void board();
void reset();
ti(){
//to get the input from the user
int player=1,i,choice;
char mark;
do{
    board();

   player = (player % 2)? 1:2;
    printf("player %d,enter a number: ",player);
    scanf("%d",&choice);
mark = (player == 1)? 'X':'O';


    if(choice == 1 && square[1] == '1')
        square[1] = mark;
        else if(choice == 2 && square[2] == '2')
            square[2] = mark;
         else if(choice == 3 && square[3] == '3')
            square[3] = mark;
     else if(choice == 4 && square[4] == '4')
            square[4]= mark;
     else if(choice == 5 && square[5] == '5')
            square[5]= mark;
     else if(choice==6&&square[6]=='6')
            square[6]= mark;
     else if(choice==7&&square[7]=='7')
            square[7]= mark;
     else if(choice==8&&square[8]=='8')
            square[8]= mark;
     else if(choice==9&&square[9]=='9')
            square[9]= mark;
    else{
        printf("invalid move");
        player--;
        getch();
    }

    i = checkwin();
    player++;
}
while(i==-1);


switch(i){
case 1:
    system("cls");
    printf("\n\n\n==>\aplayer %d is win",--player);
    delay(2);
    system("@cls||clear");
    break;
 default :
    system("cls");
    printf("\n\n\n==>\aGame draw\n");
    delay(2);
       system("@cls||clear");
    break;}

printf("\n\n\n\n\n\n\n\n\nTHANKS FOR PLAYING\n\n\n\n\n\n\n");
    delay(2);
    system("cls");
reset();

}

//function to check win or draw

int checkwin(){

if(square[1]==square[2]&&square[2]==square[3])
    return 1;
else if(square[4]==square[5]&&square[5]==square[6])
    return 1;
    else if(square[7]==square[8]&&square[8]==square[9])
    return 1;
    else if(square[1]==square[4]&&square[4]==square[7])
    return 1;
    else if(square[2]==square[5]&&square[5]==square[8])
    return 1;
    else if(square[3]==square[6]&&square[6]==square[9])
    return 1;
    else if(square[1]==square[5]&&square[5]==square[9])
    return 1;
    else if(square[3]==square[5]&&square[5]==square[7])
    return 1;

   else if(square[1]!= '1'&&square[2]!='2'&&
           square[3]!= '3'&&square[4]!= '4'&&
           square[5]!= '5'&&square[6]!= '6'&&
           square[7]!= '7'&&square[8]!= '8'&&
           square[9]!= '9' )
            return 0;
   else
      return -1;

}
//function to display 2D board and to display 'X' and'O'
void board(){

            system("cls");
    printf("player 1 (X) \t player 2 (O)\n");

     printf("   |   |  \n");
    printf(" %c | %c | %c\n",square[1],square[2],square[3]);
     printf("___|___|___\n");
     printf("   |   |   \n");
    printf(" %c | %c | %c\n",square[4],square[5],square[6]);
     printf("___|___|___\n");
     printf("   |   |   \n");
    printf(" %c | %c | %c\n",square[7],square[8],square[9]);
     printf("   |   |   \n");

}
void reset(){

square[1]='1';
square[2]='2';
square[3]='3';
square[4]='4';
square[5]='5';
square[6]='6';
square[7]='7';
square[8]='8';
square[9]='9';


main();

}




//end of game 1

//code for game 2 ninja jump

//declaration of functions

void print_at_xy(int x, int y, char *val);
void display_score();
void init();
int zero_lives();
void set_game_state_over();
char get_input();
void update_player(char);
void update_wall();
void increment_score();
void decrement_lives();
void draw();
void draw_wall();
void draw_ninja();
void clean_up();
void clear_screen();
void display_message(const char *, int yOffset);
void update_ninja(char ch);
int collides_with_spike();
void display_count_down();

//function declare to hide cursor from the output screen

HANDLE _output_handle;

void hidecursor()
{
   _output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(_output_handle, &info);
}

//declaration of variables

const int SCREEN_WIDTH = 12;
const int SCREEN_HEIGHT = 20;
int lives;
int game_state;
int GAME_STATE_OVER;
int GAME_STATE_PLAYING;
int GOAL_POINTS;
int WALL_SPEED;
int score;
char avatar[2];
char game_over_string[30];
char left_wall[60];
char right_wall[60];
char left_spike[3];
char right_spike[3];
char ninja[2];
int wall_y_pos;
int ninja_x;
int ninja_y;
int NINJA_SPEED;
int ninja_delta;
int left_wall_spike;
int right_wall_spike;
int immunity_count_down;

int nj(){

    init();
    printf("\ninit");
    system("@cls||clear");

    //game loop

    while(1){

        if(immunity_count_down > 0){
            immunity_count_down--;
        }

        clear_screen();

        char ch = get_input();

        //clear screen and quit

        if(game_state == GAME_STATE_OVER && ch == 'q'){
            system("@cls||clear");
            break;
        }
//call of functions

        clear_screen();
        update_wall();
        update_ninja(ch);
        draw();

        if(collides_with_spike() && immunity_count_down <= 0){
            decrement_lives();
            immunity_count_down = 30;
        }

        if(zero_lives()){
            set_game_state_over();
            display_message(game_over_string, -2);
            display_message("'q' to quit...", 0);
        }
        Sleep(100);

    }

    clean_up();
}

//function for initialization of the game

void init(){
    score = 0;
    lives = 3;
    GOAL_POINTS = 10;
    GAME_STATE_OVER = 1;
    GAME_STATE_PLAYING = 2;
    WALL_SPEED = 1;

    ninja_x = 1;
    ninja_y = SCREEN_HEIGHT/2;
    NINJA_SPEED = 6;
    ninja_delta = 0;
    left_wall_spike = 0;
    right_wall_spike = 0;
    immunity_count_down = 30;

    game_state = GAME_STATE_PLAYING;
    wall_y_pos = -20;
    strcpy(left_spike, "|>");
    strcpy(right_spike, "<|");
    strcpy(game_over_string, "GAME OVER");
    strcpy(ninja, "X");

    strcpy(left_wall,  "|||>|||||||||||||>>||||||>>||||||>>||||");
    strcpy(right_wall, "|||||||||<||||<||||||||<||||||<<||||||<");
    hidecursor();
}

int zero_lives(){
    if(lives == 0){
        return 1;
    }
    return 0;
}

void set_game_state_over(){
    game_state = GAME_STATE_OVER;
}

char get_input(){
    char ch = 0;

    if(kbhit()){
        ch = getch();
    }

    return ch;
}

void update_player(char ch){

}

void increment_score(){
    score += GOAL_POINTS;
}

void decrement_lives(){
    lives--;
}
// to draw the 2D game

void draw(){
    draw_wall();
    draw_ninja();
    display_score();
    display_count_down();
}

// function to hold screen coordinates x and y

void print_at_xy(int x, int y, char *val)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(_output_handle, coord);//setconsolecursor set cursor to specified place in console
  printf("%s", (const char *)val);
  fflush(stdout);//to clear the output buffer
}

// function to show score

void display_score(){
    char buffer[50] = {0};
    sprintf(buffer, "SCORE: %4d LIVES: %d", score, lives);
    print_at_xy(0, 0, buffer);
}

void clear_screen(){
    char buffer[] = "            ";

    for(int i=0;i<3;i++)
    {
        print_at_xy(0, i, buffer);
    }
}

void display_message(const char *message, int yOffset){
    char buffer[100] = {0};
    strcpy(buffer, message);
    print_at_xy(SCREEN_WIDTH/2 - strlen(message)/2,
                (SCREEN_HEIGHT/2 - 1)+yOffset, buffer);
}

void display_count_down(){
    if(immunity_count_down > 0){
        char buffer[3] = {0};
        char *countdown = itoa(immunity_count_down/10, buffer, 10);
        strcpy(buffer, countdown);
        SetConsoleTextAttribute (_output_handle, FOREGROUND_BLUE);
        display_message("GET READY!", -2);
        display_message(buffer, 0);
        SetConsoleTextAttribute (_output_handle, FOREGROUND_INTENSITY);
    }
}
//to display thanks and clear screen

void clean_up(){
    printf("\n\n\n\n\n\nTHANKS FOR PLAYING");

    delay(2);
    system("cls");
}

void update_wall(){
    wall_y_pos += WALL_SPEED;
    if(wall_y_pos > 0){
        wall_y_pos = -SCREEN_HEIGHT;
    }
}

void update_ninja(char ch){
    ninja_x += ninja_delta;
    if(ninja_x == 1 && ch == ' ' && game_state == GAME_STATE_PLAYING){
        ninja_delta = NINJA_SPEED;
        ninja_x += ninja_delta;
        increment_score();
    }
    else if(ninja_x == SCREEN_WIDTH-1 && ch == ' ' && game_state == GAME_STATE_PLAYING){
        ninja_delta = -NINJA_SPEED;
        ninja_x += ninja_delta;
        increment_score();
    }
    else if(ninja_x <= 1){
        ninja_delta = 0;
        ninja_x = 1;
    }
    else if(ninja_x >= SCREEN_WIDTH-1){
        ninja_delta = 0;
        ninja_x = SCREEN_WIDTH-1;
    }

    if(immunity_count_down > 10 && lives < 3){
        ninja_x = SCREEN_WIDTH/2;
        ninja_y += 1;
        if(ninja_y >= SCREEN_HEIGHT){
            ninja_y = SCREEN_HEIGHT;
        }
    }
    if(immunity_count_down < 10 && immunity_count_down > 1){
        ninja_x = 1;
        ninja_y = SCREEN_HEIGHT / 2;
    }
}

int collides_with_spike(){
    if(game_state == GAME_STATE_OVER){
        return 0;
    }

    if(ninja_x == 1 && left_wall_spike == 1){
        return 1;
    }
    else if(ninja_x == SCREEN_WIDTH-1 && right_wall_spike == 1){
        return 1;
    }

    return 0;
}

void draw_wall(){
    char wall_row[SCREEN_WIDTH+1];
    int wall_index = wall_y_pos * -1;
    left_wall_spike = 0;
    right_wall_spike = 0;
    for(int i=2;i<20;i++,wall_index++){

        for(int j=1;j<SCREEN_WIDTH;j++){
            wall_row[j] = ' ';
        }

        wall_row[SCREEN_WIDTH+1] = '\0';

        wall_row[0] = '|';
        wall_row[SCREEN_WIDTH] = '|';

        if(left_wall[wall_index] == '>'){
            wall_row[1] = '>';
            if(i==SCREEN_HEIGHT/2){
                left_wall_spike = 1;
            }
        }


        if(right_wall[wall_index] == '<'){
            wall_row[SCREEN_WIDTH-1] = '<';
            if(i==SCREEN_HEIGHT/2){
                right_wall_spike = 1;
            }
        }

        print_at_xy(0, i, wall_row);
    }
}

void draw_ninja(){

    if(ninja_y >= SCREEN_HEIGHT) return;

    SetConsoleTextAttribute (_output_handle, FOREGROUND_RED);
    print_at_xy(ninja_x, ninja_y, ninja);
    SetConsoleTextAttribute (_output_handle, FOREGROUND_INTENSITY);
}

int length;
int bend_no;
int len;
char key;
void record();
void load();
int life;
void Delay(long double);
void Move();
void Food();
int Score();
void Print();
void gotoxy(int x, int y);
void GotoXY(int x,int y);
void Bend();
void Boarder();
void Down();
void Left();
void Up();
void Right();
void ExitGame();
int Scoreonly();

struct coordinate
{
    int x;
    int y;
    int direction;
};

typedef struct coordinate coordinate;

coordinate head, bend[500],food,body[30];

snake()
{

    char key;

    Print();

    system("cls");

    load();

    length=5;

    head.x=25;

    head.y=20;

    head.direction=RIGHT;

    Boarder();

    Food(); //to generate food coordinates initially

    life=3; //number of extra lives

    bend[0]=head;

    Move();   //initialing initial bend coordinate

    return 0;

}

void Move()
{
    int a,i;

    do
    {

        Food();
        fflush(stdin);

        len=0;

        for(i=0; i<30; i++)

        {

            body[i].x=0;

            body[i].y=0;

            if(i==length)

                break;

        }

        Delay(length);

        Boarder();

        if(head.direction==RIGHT)

            Right();

        else if(head.direction==LEFT)

            Left();

        else if(head.direction==DOWN)

            Down();

        else if(head.direction==UP)

            Up();

        ExitGame();

    }
    while(!kbhit());

    a=getch();

    if(a==27)

    {

        system("cls");

        exit(0);

    }
    key=getch();

    if((key==RIGHT&&head.direction!=LEFT&&head.direction!=RIGHT)||(key==LEFT&&head.direction!=RIGHT&&head.direction!=LEFT)||(key==UP&&head.direction!=DOWN&&head.direction!=UP)||(key==DOWN&&head.direction!=UP&&head.direction!=DOWN))

    {

        bend_no++;

        bend[bend_no]=head;

        head.direction=key;

        if(key==UP)

            head.y--;

        if(key==DOWN)

            head.y++;

        if(key==RIGHT)

            head.x++;

        if(key==LEFT)

            head.x--;

        Move();

    }

    else if(key==27)

    {

        system("cls");

        exit(0);

    }

    else

    {

        printf("\a");

        Move();

    }
}

void gotoxy(int x, int y)
{

    COORD coord;

    coord.X = x;

    coord.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void GotoXY(int x, int y)
{
    HANDLE a;
    COORD b;
    fflush(stdout);
    b.X = x;
    b.Y = y;
    a = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(a,b);
}
void load()
{
    int row,col,r,c,q;
    gotoxy(36,14);
    printf("loading...");
    gotoxy(30,15);
    for(r=1; r<=20; r++)
    {
        for(q=0; q<=100000000; q++); //to display the character slowly
        printf("%c",177);
    }
    getch();
}
void Down()
{
    int i;
    for(i=0; i<=(head.y-bend[bend_no].y)&&len<length; i++)
    {
        GotoXY(head.x,head.y-i);
        {
            if(len==0)
                printf("v");
            else
                printf("*");
        }
        body[len].x=head.x;
        body[len].y=head.y-i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y++;
}
void Delay(long double k)
{
    Score();
    long double i;
    for(i=0; i<=(10000000); i++);
}
void ExitGame()
{
    int i,check=0;
    for(i=4; i<length; i++) //starts with 4 because it needs minimum 4 element to touch its own body
    {
        if(body[0].x==body[i].x&&body[0].y==body[i].y)
        {
            check++;    //check's value increases as the coordinates of head is equal to any other body coordinate
        }
        if(i==length||check!=0)
            break;
    }
    if(head.x<=10||head.x>=70||head.y<=10||head.y>=30||check!=0)
    {
        life--;
        if(life>=0)
        {
            head.x=25;
            head.y=20;
            bend_no=0;
            head.direction=RIGHT;
            Move();
        }
        else
        {
            system("cls");
            printf("All lives completed\nBetter Luck Next Time!!!\nPress any key to quit the game\n");
            record();
            main();
        }
    }
}
void Food()
{
    if(head.x==food.x&&head.y==food.y)
    {
        length++;
        time_t a;
        a=time(0);
        srand(a);
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)

            food.y+=11;
    }
    else if(food.x==0)/*to create food for the first time coz global variable are initialized with 0*/
    {
        food.x=rand()%70;
        if(food.x<=10)
            food.x+=11;
        food.y=rand()%30;
        if(food.y<=10)
            food.y+=11;
    }
}
void Left()
{
    int i;
    for(i=0; i<=(bend[bend_no].x-head.x)&&len<length; i++)
    {
        GotoXY((head.x+i),head.y);
        {
            if(len==0)
                printf("<");
            else
                printf("*");
        }
        body[len].x=head.x+i;
        body[len].y=head.y;
        len++;
    }
    Bend();
    if(!kbhit())
        head.x--;

}
void Right()
{
    int i;
    for(i=0; i<=(head.x-bend[bend_no].x)&&len<length; i++)
    {
        //GotoXY((head.x-i),head.y);
        body[len].x=head.x-i;
        body[len].y=head.y;
        GotoXY(body[len].x,body[len].y);
        {
            if(len==0)
                printf(">");
            else
                printf("*");
        }
        /*body[len].x=head.x-i;
        body[len].y=head.y;*/
        len++;
    }
    Bend();
    if(!kbhit())
        head.x++;
}
void Bend()
{
    int i,j,diff;
    for(i=bend_no; i>=0&&len<length; i--)
    {
        if(bend[i].x==bend[i-1].x)
        {
            diff=bend[i].y-bend[i-1].y;
            if(diff<0)
                for(j=1; j<=(-diff); j++)
                {
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y+j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff; j++)
                {
                    /*GotoXY(bend[i].x,(bend[i].y-j));
                    printf("*");*/
                    body[len].x=bend[i].x;
                    body[len].y=bend[i].y-j;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
        else if(bend[i].y==bend[i-1].y)
        {
            diff=bend[i].x-bend[i-1].x;
            if(diff<0)
                for(j=1; j<=(-diff)&&len<length; j++)
                {
                    /*GotoXY((bend[i].x+j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x+j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
            else if(diff>0)
                for(j=1; j<=diff&&len<length; j++)
                {
                    /*GotoXY((bend[i].x-j),bend[i].y);
                    printf("*");*/
                    body[len].x=bend[i].x-j;
                    body[len].y=bend[i].y;
                    GotoXY(body[len].x,body[len].y);
                    printf("*");
                    len++;
                    if(len==length)
                        break;
                }
        }
    }
}
void Boarder()
{
    system("cls");
    int i;
    GotoXY(food.x,food.y);   /*displaying food*/
    printf("$");
    for(i=10; i<71; i++)
    {
        GotoXY(i,10);
        printf("*");
        GotoXY(i,30);
        printf("*");
    }
    for(i=10; i<31; i++)
    {
        GotoXY(10,i);
        printf("!");
        GotoXY(70,i);
        printf("!");
    }
}
void Print()
{
    //GotoXY(10,12);
    printf("\tWelcome to the mini Snake game.(press any key to continue)\n");
    getch();
    system("cls");
    printf("\tGame instructions:\n");
    printf("\n-> Use arrow keys to move the snake.\n\n-> You will be provided foods at the several coordinates of the screen which you have to eat. Everytime you eat a food the length of the snake will be increased by 1 element and thus the score.\n\n-> Here you are provided with three lives. Your life will decrease as you hit the wall or snake's body.\n\n-> YOu can pause the game in its middle by pressing any key. To continue the paused game press any other key once again\n\n-> If you want to exit press esc. \n");
    printf("\n\nPress any key to play game...");
    if(getch()==27);

}
void record()
{
    char plname[20],nplname[20],cha,c;
    int i,j,px;
    FILE *info;
    info=fopen("record.txt","a+");
    getch();
    system("cls");
    printf("Enter your name\n");
    scanf("%[^\n]",plname);
    //************************
    for(j=0; plname[j]!='\0'; j++) //to convert the first letter after space to capital
    {
        nplname[0]=toupper(plname[0]);
        if(plname[j-1]==' ')
        {
            nplname[j]=toupper(plname[j]);
            nplname[j-1]=plname[j-1];
        }
        else nplname[j]=plname[j];
    }
    nplname[j]='\0';
    //*****************************
    //sdfprintf(info,"\t\t\tPlayers List\n");
    fprintf(info,"Player Name :%s\n",nplname);
    //for date and time

    time_t mytime;
    mytime = time(NULL);
    fprintf(info,"Played Date:%s",ctime(&mytime));
    //**************************
    fprintf(info,"Score:%d\n",px=Scoreonly());//call score to display score
    //fprintf(info,"\nLevel:%d\n",10);//call level to display level
    for(i=0; i<=50; i++)
        fprintf(info,"%c",'_');
    fprintf(info,"\n");
    fclose(info);
    printf("Wanna see past records press 'y'\n");
    cha=getch();
    system("cls");
    if(cha=='y')
    {
        info=fopen("record.txt","r");
        do
        {
            putchar(c=getc(info));
        }
        while(c!=EOF);
    }
    fclose(info);
}
int Score()
{
    int score;
    GotoXY(20,8);
    score=length-5;
    printf("SCORE : %d",(length-5));
    score=length-5;
    GotoXY(50,8);
    printf("Life : %d",life);
    return score;
}
int Scoreonly()
{
    int score=Score();
    system("cls");
    return score;
}
void Up()
{
    int i;
    for(i=0; i<=(bend[bend_no].y-head.y)&&len<length; i++)
    {
        GotoXY(head.x,head.y+i);
        {
            if(len==0)
                printf("^");
            else
                printf("!");
        }
        body[len].x=head.x;
        body[len].y=head.y+i;
        len++;
    }
    Bend();
    if(!kbhit())
        head.y--;
}



//main function

int main(){
int c;
char k;

printf("\n\n\n\n\n****WELCOME TO THE PLAY GAMES****\n");
printf("\n\nGAME'S LIST\n\n1:TIC TAC TOE.\n2:NINJA JUMP.\n3:SNAKE GAME.");
printf("\n\n\n\npress q to quit.");
printf("\n\n\n\n\nEnter Your Choice:");
scanf("%d",&c);
scanf("%c",&k);

if(c==1){

    printf("\nTIC TAC TOE IS READY TO PLAY");
           delay(1);

system("cls");

   ti();

}
if(c==2){


    printf("NINJA JUMP IS READY TO PLAY");
    delay(1);
    system("cls");
    printf("press 'space' to avoid spikes");
    delay(2);
    system("cls");
    nj();
    system("cls");
    main();
}
if(c==3){

system("cls");
    snake();
main();
}



switch(k){
case 'q':
system("cls");
printf("\n\n\n\n\n\n\nTHANKS FOR YOUR VISIT");
delay(1);
system("cls");
}
}
