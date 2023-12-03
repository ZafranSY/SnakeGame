#include <graphics.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
  
  int gd,gm,rx =200,ry =200,x[200],y[200],d,rx1 =200,ry1 =200;
  int random;
  int length = 1;
  int dir = 0;
  int sx = 200,sy = 200;
enum class FoodType {
    APPLE=1, 
    BROCCOLI,
    CUPCAKE
    
};
class homepage
{
    public:
     void drawButton( char* label)
     {
        readimagefile("ular4.jpg",0,0,640,500);
        setbkcolor(GREEN);
        setcolor(WHITE);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
        outtextxy(450,400,label);
        int x = textwidth(label);
        int y = textheight(label);
    //    std::cout << x<<"  "<<y<<std::endl;
     }
     bool isButtonPressed(char* label)
     {
        int mousex1 = mousex();
        int mousey1 = mousey();
        if(mousex1 >= 450 && mousey1 >= 400 && mousex1 <= (450 +textwidth(label)) && mousey1 <= (400 +textheight(label)) )
        {
            if (ismouseclick(WM_LBUTTONDOWN)) {
            clearmouseclick(WM_LBUTTONDOWN);
            return true;
        }
        }
        return false;

     }
};
class position
{
    public:
    position()
    {
        for(int i = 0;i <200 ; i++)
        {
            x[i] = 0;
            y[i] = 0;
        }
    }
    void SnakePosition()
    {
        do {
        x[0] = rand()% 550;
        y[0]  = rand() % 410;
        }while(getpixel(x[0],y[0]) != 0 && x[0] <= 45 && y[0] <=  35 );

        x[0] = x[0]/10;
        x[0] = x[0]*10;

        y[0] = y[0]/10;
        y[0] = y[0]*10;
        setfillstyle(1,2);
        }


    
};
class direction
{
    public:
    void checkDirection()
    {
        if(GetAsyncKeyState(VK_RIGHT)) { d = 1;}
        else if(GetAsyncKeyState(VK_LEFT)) { d = 2;}
        else if(GetAsyncKeyState(VK_UP)) { d = 3;}
        else if(GetAsyncKeyState(VK_DOWN)) { d = 4;}
        else { d = 0;}

        switch(d)
        {
            case 0:
             if(dir == 1){ x[0] +=10;}
             else if(dir == 2){ x[0] -=10;}
             else if(dir == 3){ y[0] -=10;}
             else if(dir == 4){ y[0] +=10;}
             else{ d = 0; }
             break;
            
            case 1:
           
            dir = 1;
             x[0] = x[0]+10;
            break;

             case 2:
            
            dir = 2;
            x[0] = x[0]-10;
            break;

             case 3:
            
            dir = 3;
            y[0] = y[0]-10;
            break;

             case 4:
            
            dir = 4;
            y[0] = y[0]+10;
            break;


        }
    }
};

position p1;

class Lives {
private:
    int count;

public:
    Lives() : count(3) {}

    int getCount() const {
        return count;
    }

    void decrease() {

        p1.SnakePosition();
        count--;
    }
    void KO()
    {
        p1.SnakePosition();
        count = count - 3;

    }

    bool isGameOver() const {
        return count <= 0;
    }
};
class obstacle
{
public:
  void wall(Lives &n)
  {
    if(x[0] <= 35 || x[0] >= 590 || y[0] <= 45 || y[0] >= 436)
    n.decrease();
    for(int i = 2;i<length ;i++)
        {
            if(x[0]==x[i] && y[0] ==y[i]){
                n.KO();
                break;
            }
        }

  }
};
class GameOver
{
    public:
    void endfunc(int e)
    {
         setfillstyle(1,5);
    //e = e-2;
    rectangle(0,0,640,480);
    floodfill(0,100,RED);
    system("cls");
    
    printf("your score is :  %d\n",e);
    

    }
};
class food
{
    public:
    FoodType type;
    food(){ random = rand()%3;}
    virtual void image() {}
    void foodlocation()
    {
        do{
            rx = (40+rand()%500);
            ry = (40 + rand()%400);

            rx1 = (60+rand()%200);
            ry1 = (60 + rand()%200);
           


        }while( rx <60 && ry <60  );
        rx = rx/10;
        rx = rx*10;

        ry = ry/10;
        ry = ry*10;
        rx1 = rx1/10;
        rx1 = rx1*10;

        ry1 = ry1/10;
        ry1 = ry1*10;

        
        setfillstyle(1,2);
        
    }
    
    };
class broccoli : public food
{
    public:
    void image()
    { readimagefile("broccoli.jpg",rx,ry,rx+20,ry+20);
    readimagefile("broccoli.jpg",rx1,ry1,rx1+20,ry1+20);}
};
class apple : public food
{
    public:
        void image()
        { 
        readimagefile("apple.jpg",rx,ry,rx+20,ry+20);
        readimagefile("apple.jpg",rx1,ry1,rx1+20,ry1+20);}

};
class cupcake :public food
{
    public:
    
    void image()
    {readimagefile("cupcake.jpg",rx,ry,rx+20,ry+20);
    readimagefile("cupcake.jpg",rx1,ry1,rx1+20,ry1+20);}
};
class skull
{
    public:
    void skull_location()
    {
        sx = 45+rand()%500;
        sy = 45+rand()%490;
    }
};

class score
{
    public:
    int score = {};
};
Lives live;
food f1;
skull s1;
apple a1;broccoli b1;
cupcake c1;
score score1;
int nom = rand() % 3;

class generate
{
    private:
    public:
    void render();
    void skull_image(){
         int skull_popout = 10;
        skull_popout = rand() % 10;
        
        switch (skull_popout)
        {
        case 2:
            readimagefile("skull.jpg",sx,sy,sx+20,sy+20);
            break;
        
        default:
            break;
        }
        if(x[0] == sx && y[0] == sy)
        {
            live.decrease();
            s1.skull_location();
            skull_popout = rand() % 10;
            
        switch (skull_popout)
        {
        case 3:
            readimagefile("skull.jpg",sx,sy,sx+20,sy+20);
            break;
        }
        }


    }

};

    void generate :: render()
    {
            f1.type = static_cast<FoodType>(random);
          switch (f1.type)
          {
          case FoodType ::APPLE:
            /* code */
            a1.image();

            break;
          case FoodType::BROCCOLI:
          b1.image();
          break;
          case FoodType::CUPCAKE:
          c1.image();
          
          
          break;
          }
        if(x[0] == rx && y[0] == ry || x[0] == rx1 && y[0] == ry1)
        {  
             f1.foodlocation();
     random = 1+rand()%3;   
      
            f1.type = static_cast<FoodType>(random);
          switch (f1.type)
          {
          case FoodType ::APPLE:
            /* code */
            a1.image();
            score1.score += 10;
            break;
          case FoodType::BROCCOLI:
          b1.image();
          score1.score += 20;
          break;
          case FoodType::CUPCAKE:
          score1.score += 30;
          c1.image();
          break;
          }
            
            length++;
            
        }
    }
class gameOverPage
{
public:
 void gameOverPagee()
    {
        std :: string score_counted =  "Score : " + std::to_string(score1.score);
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,5);
        std::string gameOver = "      game Over!!!";
        outtextxy(100,200,const_cast<char*>(gameOver.c_str()));
        settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
        outtextxy(200,400,const_cast<char*>(score_counted.c_str()));
        delay(1000);

    }
};
int main()
{
    
    obstacle walls;
    homepage page1;
    GameOver gameover;
    generate g1;
    gameOverPage over;
    initwindow(640,480,(char*)"snake Game"); 
    setcolor(WHITE);
    bar(35,45,35,610);
    
      
        char* label = (char*)"click to continue!!";
        bool buttonClicked = false;
    while(!buttonClicked)
    {
        page1.drawButton(label);
        if(page1.isButtonPressed(label))
        {
            setcolor(RED);
            bar(0,0,600,680);
            buttonClicked = true;
            cleardevice();
        }
    }
    p1.SnakePosition();
    f1.foodlocation();
    int j = 0;
    for(;;){
       
        readimagefile("gamelay.jpg",0,0,640,480); 
        setcolor(GREEN);
        walls.wall(live);
       

        setfillstyle(1,5);
        g1.render();
        g1.skull_image();
        
    
       direction direction1;
        direction1.checkDirection();

        bar(x[0],y[0],x[0]+20,y[0]+20);
        
        // if(x[0] == rx && y[0] == ry)
       
        //     for (int i = 1; i < length+1; i++) {
        //     x[i] = x[i - 1];
        //     y[i] = y[i - 1];
        //     bar(x[i], y[i], x[i] + 20, y[i] + 20);
        // }
        for(int  i =0;i<length ; i++)
        {
            bar(x[i],y[i],x[i]+20,y[i]+20);
        }
        for(int i = 199; i>0;i--)
        {
            x[i] = x[i-1];
            y[i] = y[i -1];

        }
        
        std :: cout <<" score  : "<<score1.score<<std:: endl;
        
        
            std::string livesText = "Lives : " + std::to_string(live.getCount());
            std :: string score_counted =  "Score : " + std::to_string(score1.score);
            setcolor(WHITE);
            setbkcolor(BLACK);
            std::cout <<" "<<length<<std::endl;
         outtextxy(10, 30, const_cast<char*>(livesText.c_str()));
         outtextxy(10,50,const_cast<char*>(score_counted.c_str()));

         if(live.getCount() <= 0 ){
         gameover.endfunc(score1.score);
         break;
         }
    g1.render();
               
    }
   cleardevice();
    over.gameOverPagee();
    

    
}
