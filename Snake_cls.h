class Snake
{
     private:
          int headx,heady;
          int Snake_xy[120][2];
          char s[80][25];
          int length;
          char dir;
          int feedx,feedy;
     public:
          Snake()
          { headx=5; dir='d'; heady=6; length=4; clean(); first_position(); feed(); srand(time(NULL)); New_s(); }
          void feed();
          void gameover();
          void move();
          void New_s();
          void clean();
          void first_position();
          void printf2();
};
