#include "Back_end.h"

Back_end::Back_end()
{
    points=0;
    actual_name="";
    actual_ball.constructor("graphics/kulki.png");
    next_ball.constructor("graphics/kulki.png");
    arrow.constructor("graphics/szczalka.png");
        arrow.set_origin(ARROW_X_ORIGIN,ARROW_Y_ORIGIN);
        arrow.set_position(ARROW_X,ARROW_Y);

    actual_ball.set_position(ARROW_X-17,ARROW_Y-16);
    next_ball.set_position(30,580);

    gray_ball_number=GRAY_BALLS_NUMBER;
    counter=0;

    for(int i=0; i<6; i++) existing_colors[i]=true;

    srand(time(NULL)); //for all rand()

    set_color_of_all_balls();
    random_next_ball_color();
    ball_to_throw();
}

void Back_end::set_color_of_all_balls()
{
    for(int i=0; i<ARRAY_X_SIZE; i++)
    {
        for(int j=0; j<ARRAY_Y_SIZE; j++)
        {
            int x;
            x=rand()%6;          //<-- manipulating randomize balls' colors
            switch(x)
            {
            case 0:
                if(!existing_colors[0]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=RED;
                break;
            case 1:
                if(!existing_colors[1]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=PURPLE;
                break;
            case 2:
                if(!existing_colors[2]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=BRIGHT_BLUE;
                break;
            case 3:
                if(!existing_colors[3]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=BLUE;
                break;
            case 4:
                if(!existing_colors[4]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=YELLOW;
                break;
            case 5:
                if(!existing_colors[5]) continue;
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=GREEN;
                break;
            default:
                balls[i][j].pkt.x=i;
                balls[i][j].pkt.y=j;
                balls[i][j].live_stage=0;
                balls[i][j].is_connected_with_roof=1;
                balls[i][j].ball_color=BLANK;
                break;
            }
        }
    }

    for(int i=0; i<ARRAY_X_SIZE; i++)
        for(int j=9; j<ARRAY_Y_SIZE; j++) balls[i][j].ball_color=BLANK; //TODO: change to 9
}

void Back_end::arrow_rotating(sf::RenderWindow &mouse)
{
    sf::Vector2i mouse_pos;
        mouse_pos=sf::Mouse::getPosition(mouse);

    arrow.set_rotate(atan2((ARROW_Y-mouse_pos.y),(ARROW_X-mouse_pos.x))*360/6.28+BASIC_ROTATION);
}

void Back_end::update_colors_existing()
{
    for(int i=0; i<6; i++) existing_colors[i]=false;
    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE-1; j++)
    {
        switch(balls[i][j].ball_color)
        {
        case RED:           existing_colors[0]=true; break;
        case PURPLE:        existing_colors[1]=true; break;
        case BRIGHT_BLUE:   existing_colors[2]=true; break;
        case BLUE:          existing_colors[3]=true; break;
        case YELLOW:        existing_colors[4]=true; break;
        case GREEN:         existing_colors[5]=true; break;
        }

        if(existing_colors[0]&&
           existing_colors[1]&&
           existing_colors[2]&&
           existing_colors[3]&&
           existing_colors[4]&&
           existing_colors[5]) break;
    }
}

void Back_end::random_next_ball_color()
{
    int x;
    for(;;)
    {
        x=rand()%6;
        switch(x)
        {
            case 0:
                if(!existing_colors[0]) continue;
                next_ball_color=RED;
                break;
            case 1:
                if(!existing_colors[1]) continue;
                next_ball_color=PURPLE;
                break;
            case 2:
                if(!existing_colors[2]) continue;
                next_ball_color=BRIGHT_BLUE;
                break;
            case 3:
                if(!existing_colors[3]) continue;
                next_ball_color=BLUE;
                break;
            case 4:
                if(!existing_colors[4]) continue;
                next_ball_color=YELLOW;
                break;
            case 5:
                if(!existing_colors[5]) continue;
                next_ball_color=GREEN;
                break;
        }
        break;
    }
}

void Back_end::ball_to_throw()
{
    update_colors_existing();

    actual_ball_color=next_ball_color;

    if( !existing_colors[0]&&
        !existing_colors[1]&&
        !existing_colors[2]&&
        !existing_colors[3]&&
        !existing_colors[4]&&
        !existing_colors[5])
        {
            next_ball_color=RED;
            actual_ball.set_position(ARROW_X-17,ARROW_Y-16);
            return;
        }

    random_next_ball_color();

    actual_ball.set_position(ARROW_X-17,ARROW_Y-16);
}

void Back_end::throwing_ball(float mouse_pos_x, float mouse_pos_y)
{
    if(!is_ball_moving)
    {
        is_ball_moving=true;
        actual_ball_x_speed=BALL_SPEED*sin((arrow.get_rotate()-10)*3.14/180);
        actual_ball_y_speed=-BALL_SPEED*cos((arrow.get_rotate()-10)*3.14/180);
    }
}

bool Back_end::moving_ball()
{
    if(is_ball_moving)
    {
        actual_ball.moving(actual_ball_x_speed,actual_ball_y_speed);
        return true;
    }
    else return false;
}

bool Back_end::saving_ball()
{
    float main_x;
    float main_y;
        actual_ball.get_position(main_x,main_y);

    float the_lowest=INT_MAX;
    int the_lowest_x=INT_MAX;
    int the_lowest_y=INT_MAX;
    float temp_number=INT_MAX;

    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE; j++)
    {
        temp_number=(main_x-(i*36+BASE_POINT_X+j%2*17))*(main_x-(i*36+BASE_POINT_X+j%2*17))+(main_y-(j*35+BASE_POINT_Y))*(main_y-(j*35+BASE_POINT_Y));
        if(temp_number<the_lowest)
        {
            the_lowest=temp_number;
            the_lowest_x=i;
            the_lowest_y=j;
        }
    }
    balls[the_lowest_x][the_lowest_y].ball_color=actual_ball_color;

    checking_size_of_the_color(the_lowest_x,the_lowest_y);

    return is_bot_reached();
}

bool Back_end::collision_detection()
{
    float main_x,main_y;

    actual_ball.get_position(main_x,main_y);

    //with roof or floor
    if(main_y<=24||main_y>=700)
    {
        is_ball_moving=false;
        saving_ball();
        ball_to_throw();
        return false;
    }

    //with walls:
    if(main_x<=45||main_x>=630)
    {
        actual_ball_x_speed=-actual_ball_x_speed;
        return false;
    }

    //with another balls:
    for(int i=0; i<ARRAY_X_SIZE; i++)
    {
        for(int j=0; j<ARRAY_Y_SIZE; j++)
        {
            if(balls[i][j].ball_color!=BLANK)
            if((main_x-(i*36+BASE_POINT_X+j%2*17))*(main_x-(i*36+BASE_POINT_X+j%2*17))+(main_y-(j*35+BASE_POINT_Y))*(main_y-(j*35+BASE_POINT_Y))<=750)
            {
                is_ball_moving=false;

                bool x;
                x=saving_ball();
                ball_to_throw();
                return x;
            }
        }
    }
    return false;
}

bool Back_end::is_on_map(int x, int y, DIRECTION d)
{
    //x
    if(y%2==1) if(x==ARRAY_X_SIZE-1&&d==NE)     return 0;
    if(x==ARRAY_X_SIZE-1&&d==E)                 return 0;
    if(y%2==1) if(x==ARRAY_X_SIZE-1&&d==SE)     return 0;
    if(y%2==0) if(x==0&&d==SW)                  return 0;
    if(y%2==0) if(x==0&&d==NW)                  return 0;
    if(x==0&&d==W)                              return 0;


    //y
    if(y==0&&d==N)                              return 0;
    if(y%2==1) if(y==0&&d==NE)                  return 0;
    if(y%2==1) if(y==ARRAY_Y_SIZE-1&&d==SE)     return 0;
    if(y==ARRAY_Y_SIZE-1&&d==S)                 return 0;
    if(y%2==0) if(y==ARRAY_Y_SIZE-1&&d==SW)     return 0;
    if(y%2==0) if(y==0&&d==NW)                  return 0;

    return 1; //:D
}

bool Back_end::is_in_closed_or_open(int x, int y, DIRECTION d)
{
    for(std::list<ball>::iterator it=closed.begin(); it!=closed.end(); it++)
    {
        if(d==N)            {if(it->pkt.x==x&&it->pkt.y==y-1)      return 1;}
        if(d==NE&&y%2==1)   {if(it->pkt.x==x+1&&it->pkt.y==y-1)    return 1;}
        if(d==E)            {if(it->pkt.x==x+1&&it->pkt.y==y)      return 1;}
        if(d==SE&&y%2==1)   {if(it->pkt.x==x+1&&it->pkt.y==y+1)    return 1;}
        if(d==S)            {if(it->pkt.x==x&&it->pkt.y==y+1)      return 1;}
        if(d==SW&&y%2==0)   {if(it->pkt.x==x-1&&it->pkt.y==y+1)    return 1;}
        if(d==W)            {if(it->pkt.x==x-1&&it->pkt.y==y)      return 1;}
        if(d==NW&&y%2==0)   {if(it->pkt.x==x-1&&it->pkt.y==y-1)    return 1;}

    }

    for(std::list<ball>::iterator it=open.begin(); it!=open.end(); it++)
    {
        if(d==N)            {if(it->pkt.x==x&&it->pkt.y==y-1)      return 1;}
        if(d==NE&&y%2==1)   {if(it->pkt.x==x+1&&it->pkt.y==y-1)    return 1;}
        if(d==E)            {if(it->pkt.x==x+1&&it->pkt.y==y)      return 1;}
        if(d==SE&&y%2==1)   {if(it->pkt.x==x+1&&it->pkt.y==y+1)    return 1;}
        if(d==S)            {if(it->pkt.x==x&&it->pkt.y==y+1)      return 1;}
        if(d==SW&&y%2==0)   {if(it->pkt.x==x-1&&it->pkt.y==y+1)    return 1;}
        if(d==W)            {if(it->pkt.x==x-1&&it->pkt.y==y)      return 1;}
        if(d==NW&&y%2==0)   {if(it->pkt.x==x-1&&it->pkt.y==y-1)    return 1;}

    }

    return 0;
}

bool Back_end::checking_color(int x, int y, DIRECTION d)
{
    if(d==N)            {if(balls[x][y-1].ball_color==considering_ball->ball_color)       return 1;}
    if(d==NE&&y%2==1)   {if(balls[x+1][y-1].ball_color==considering_ball->ball_color)     return 1;}
    if(d==E)            {if(balls[x+1][y].ball_color==considering_ball->ball_color)       return 1;}
    if(d==SE&&y%2==1)   {if(balls[x+1][y+1].ball_color==considering_ball->ball_color)     return 1;}
    if(d==S)            {if(balls[x][y+1].ball_color==considering_ball->ball_color)       return 1;}
    if(d==SW&&y%2==0)   {if(balls[x-1][y+1].ball_color==considering_ball->ball_color)     return 1;}
    if(d==W)            {if(balls[x-1][y].ball_color==considering_ball->ball_color)       return 1;}
    if(d==NW&&y%2==0)   {if(balls[x-1][y-1].ball_color==considering_ball->ball_color)     return 1;}
    else return 0;
}

bool Back_end::is_working(int x, int y, DIRECTION d)
{
    //is on map
    //is in closed list
    //checking color

    if(is_on_map(x,y,d)&&!is_in_closed_or_open(x,y,d)&&checking_color(x,y,d)) return 1;
    else return 0;
}

void Back_end::show() //logs
{
    std::cout<<"open list:\n";
    for(std::list<ball>::iterator it=open.begin(); it!=open.end(); it++)
    {
        printf("%-3i%-3i\n",it->pkt.x,it->pkt.y);
    }
    std::cout<<"closed list:\n";
    for(std::list<ball>::iterator it=closed.begin(); it!=closed.end(); it++)
    {
        printf("%-3i%-3i\n",it->pkt.x,it->pkt.y);
    }
}

void Back_end::deleting_balls_from_closed_list()
{
    for(std::list<ball>::iterator it=closed.begin(); it!=closed.end(); it++)
        balls[it->pkt.x][it->pkt.y].ball_color=BLANK;
}

void Back_end::are_all_balls_connected_with_roof()
{
    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE; j++)
    {
        balls[i][j].is_connected_with_roof=0;
    }

    for(int i=0; i<ARRAY_X_SIZE; i++) if(balls[i][0].ball_color!=BLANK) is_connected_with_roof(i);

    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE; j++)
    {
        if(!balls[i][j].is_connected_with_roof) balls[i][j].ball_color=BLANK;
    }
}

void Back_end::checking_size_of_the_color(int x, int y)
{
    ball temporary_ball;
    temporary_ball.pkt.x=x;
    temporary_ball.pkt.y=y;
    temporary_ball.live_stage=0;
    temporary_ball.ball_color=actual_ball_color;

    open.push_front(temporary_ball);

    ball adding_ball;

    while(!open.empty()) //main loop
    {
        considering_ball=open.begin();
        open.pop_front();
        closed.push_back(*considering_ball);
        counter++;

        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,N)) {adding_ball={considering_ball->pkt.x,considering_ball->pkt.y-1,considering_ball->live_stage, considering_ball->ball_color};     open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,NE)){adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y-1,considering_ball->live_stage, considering_ball->ball_color};   open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,E)) {adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y,considering_ball->live_stage, considering_ball->ball_color};     open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,SE)){adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y+1,considering_ball->live_stage, considering_ball->ball_color};   open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,S)) {adding_ball={considering_ball->pkt.x,considering_ball->pkt.y+1,considering_ball->live_stage, considering_ball->ball_color};     open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,SW)){adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y+1,considering_ball->live_stage, considering_ball->ball_color};   open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,W)) {adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y,considering_ball->live_stage, considering_ball->ball_color};     open.push_front(adding_ball);}
        if(is_working(considering_ball->pkt.x,considering_ball->pkt.y,NW)){adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y-1,considering_ball->live_stage, considering_ball->ball_color};   open.push_front(adding_ball);}
    }

    if(counter>=3)
    {
        points+=(counter*10);
        deleting_balls_from_closed_list();
    }
    else update_grey_balls();


    open.clear();
    closed.clear();
    counter=0;

    are_all_balls_connected_with_roof();

    return;
}

bool Back_end::is_in_closed(int x, int y)
{
    for(std::list<ball>::iterator it=closed.begin(); it!=closed.end(); it++)
    {
        if(it->pkt.x==x&&it->pkt.y==y)
        {
            //printf("considering ball: %3i %-3i\n",it->pkt.x, it->pkt.y);
            return 1;
        }
    }

    return 0;
}

bool Back_end::is_blank(int x, int y, DIRECTION d)
{
    if(d==N)            {if(balls[x][y-1].ball_color==BLANK)       return 1;}
    if(d==NE&&y%2==1)   {if(balls[x+1][y-1].ball_color==BLANK)     return 1;}
    if(d==E)            {if(balls[x+1][y].ball_color==BLANK)       return 1;}
    if(d==SE&&y%2==1)   {if(balls[x+1][y+1].ball_color==BLANK)     return 1;}
    if(d==S)            {if(balls[x][y+1].ball_color==BLANK)       return 1;}
    if(d==SW&&y%2==0)   {if(balls[x-1][y+1].ball_color==BLANK)     return 1;}
    if(d==W)            {if(balls[x-1][y].ball_color==BLANK)       return 1;}
    if(d==NW&&y%2==0)   {if(balls[x-1][y-1].ball_color==BLANK)     return 1;}

    return 0;
}

bool Back_end::can_go_this_way(int x, int y, DIRECTION d)
{
    if(d==NE&&y%2==1) return 1;
    if(d==SE&&y%2==1) return 1;
    if(d==SW&&y%2==0) return 1;
    if(d==NW&&y%2==0) return 1;
    if(d==N)          return 1;
    if(d==E)          return 1;
    if(d==S)          return 1;
    if(d==W)          return 1;

    return 0;
}

void Back_end::remove_from_closed(int x, int y)
{
    for(std::list<ball>::iterator it=closed.begin(); it!=closed.end(); it++)
    {
        if(it->pkt.x==x&&it->pkt.y==y)
        {
            closed.erase(it);
        }
    }
}

void Back_end::is_connected_with_roof(int x)
{
    ball temporary_ball;
    temporary_ball.pkt.x=x;
    temporary_ball.pkt.y=0;
    temporary_ball.live_stage=0;

    open.push_front(temporary_ball);

    ball adding_ball;

    while(!open.empty())
    {
        considering_ball=open.begin();
        open.pop_front();
        closed.push_back(*considering_ball);

        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,N)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,N)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,N)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,N))    {adding_ball={considering_ball->pkt.x,considering_ball->pkt.y-1,considering_ball->live_stage};    open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,NE)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,NE)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,NE)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,NE)){adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y-1,considering_ball->live_stage};  open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,E)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,E)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,E)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,E))    {adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y,considering_ball->live_stage};    open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,SE)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,SE)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,SE)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,SE)){adding_ball={considering_ball->pkt.x+1,considering_ball->pkt.y+1,considering_ball->live_stage};  open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,S)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,S)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,S)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,S))    {adding_ball={considering_ball->pkt.x,considering_ball->pkt.y+1,considering_ball->live_stage};    open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,SW)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,SW)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,SW)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,SW)){adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y+1,considering_ball->live_stage};  open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,W)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,W)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,W)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,W))    {adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y,considering_ball->live_stage};    open.push_front(adding_ball);}
        if(can_go_this_way(considering_ball->pkt.x,considering_ball->pkt.y,NW)&&is_on_map(considering_ball->pkt.x,considering_ball->pkt.y,NW)&&!is_in_closed_or_open(considering_ball->pkt.x,considering_ball->pkt.y,NW)&&!is_blank(considering_ball->pkt.x,considering_ball->pkt.y,NW)){adding_ball={considering_ball->pkt.x-1,considering_ball->pkt.y-1,considering_ball->live_stage};  open.push_front(adding_ball);}
    }

    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE; j++)
    {
        if(is_in_closed(i,j))
        {
            balls[i][j].is_connected_with_roof=1;
            remove_from_closed(i,j);
        }
    }

    open.clear();
    closed.clear();
    return;
}

bool Back_end::is_bot_reached()
{
    for(int i=0; i<ARRAY_X_SIZE; i++)
        if(balls[i][ARRAY_Y_SIZE-1].ball_color!=BLANK)
        {
            scoreboard_loading();
            return true;
        }
    return false;
}

void Back_end::falling()
{
    ball copy_of_balls[ARRAY_X_SIZE][ARRAY_Y_SIZE];

    for(int i=0; i<6; i++) existing_colors[i]=false;

    //copying:
    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE-1; j++)
    {
        copy_of_balls[i][j].ball_color=balls[i][j].ball_color;
        switch(copy_of_balls[i][j].ball_color)
        {
        case RED:           existing_colors[0]=true; break;
        case PURPLE:        existing_colors[1]=true; break;
        case BRIGHT_BLUE:   existing_colors[2]=true; break;
        case BLUE:          existing_colors[3]=true; break;
        case YELLOW:        existing_colors[4]=true; break;
        case GREEN:         existing_colors[5]=true; break;
        }
    }

    //falling:

    for(int i=0; i<ARRAY_X_SIZE; i++)
    for(int j=0; j<ARRAY_Y_SIZE-1; j++)
    {
        balls[i][j+1].ball_color=copy_of_balls[i][j].ball_color;
    }

    //adding new top line:
    int x;
    for(int i=0; i<ARRAY_X_SIZE; i++)
    {
        x=rand()%6;
        switch(x)
        {
        case 0:
            if(!existing_colors[0]) continue;
            balls[i][0].ball_color=RED;
            break;
        case 1:
            if(!existing_colors[3]) continue;
            balls[i][0].ball_color=BLUE;
            break;
        case 2:
            if(!existing_colors[2]) continue;
            balls[i][0].ball_color=BRIGHT_BLUE;
            break;
        case 3:
            if(!existing_colors[5]) continue;
            balls[i][0].ball_color=GREEN;
            break;
        case 4:
            if(!existing_colors[1]) continue;
            balls[i][0].ball_color=PURPLE;
            break;
        case 5:
            if(!existing_colors[4]) continue;
            balls[i][0].ball_color=YELLOW;
            break;
        }
    }
}

void Back_end::update_grey_balls()
{
    gray_ball_number--;
    if(gray_ball_number==0)
    {
        falling();
        gray_ball_number=GRAY_BALLS_NUMBER;
    }
}

//scoreboard:
void Back_end::scoreboard_loading()
{
    std::ifstream read;
        read.open("scoreboard.txt");
    score temp;
    for(int i=0; i<SCOREBOARD_SIZE;i++)
    {
        read>>temp.name;
        read>>temp.points;
        scoreboard.push_back(temp);
    }

    read.close();
}

void Back_end::name_load(char letter, bool backspace)
{
    if(backspace) actual_name = actual_name.substr(0, actual_name.size()-1);
    if(!backspace) actual_name+=letter;
    return;
}

void Back_end::update_scoreboard()
{
    score temp;

    temp.name=actual_name;
    temp.points=points;
    scoreboard.push_front(temp);
    score copy_list[SCOREBOARD_SIZE+1];

    std::list<score>::iterator it=scoreboard.begin();
    for(int i=0; i<SCOREBOARD_SIZE+1; i++)
    {
        copy_list[i]= *it;
        it++;
    }

    //bubble sort:
    for (int i = 0; i < SCOREBOARD_SIZE; i++)
    for (int j = 0; j < SCOREBOARD_SIZE-i; j++)
        if (copy_list[j].points > copy_list[j+1].points)
            std::swap(copy_list[j], copy_list[j+1]);

    scoreboard.clear();
    for(int i=0; i<SCOREBOARD_SIZE; i++) scoreboard.push_front(copy_list[i]);

    //save scoreboard:

    std::ofstream write;
    write.open("scoreboard.txt");
    for(std::list<score>::iterator it=scoreboard.begin(); it!=scoreboard.end(); it++)
    {
        write<<it->name;
        write<<std::endl;
        write<<it->points;
    }
    write.close();
}

void Back_end::reset()
{
    points=0;
    actual_name="";

    gray_ball_number=GRAY_BALLS_NUMBER;
    counter=0;

    for(int i=0; i<6; i++) existing_colors[i]=true;

    set_color_of_all_balls();
    random_next_ball_color();
    ball_to_throw();
}
