#include "Front_end.h"

Front_end::Front_end()
{
    game_over=false;
    level= -1;

    window.create(sf::VideoMode(687,646),"kulki dla tatusia <3");

    window.setFramerateLimit(FPS);

    background.constructor("graphics/background.png");
    balls.constructor("graphics/kulki.png");
    gray_ball.constructor("graphics/szara kulka.png");
        gray_ball.set_position(200,600);
    enter_your_nickname.constructor("graphics/enter your nickname.png");
        enter_your_nickname.set_position(159,192);
    your_score.constructor("graphics/score.png");
        your_score.set_position(134,86);
    top10Scores.constructor("graphics/scoreboard.png");
        top10Scores.set_position(158,48);

    font.loadFromFile("font/Sketch 3D.otf");

    tech_stuff.ball_to_throw();
    showing_points.setFont(font);
    showing_points.setColor(sf::Color::Black);
    showing_points.setCharacterSize(50);
    showing_points.setPosition(400,560);

    scoreboard_text.setFont(font);
    scoreboard_text.setColor(sf::Color::Black);
    scoreboard_text.setCharacterSize(25);

    name.setFont(font);
    name.setColor(sf::Color::Black);
    name.setCharacterSize(30);
    name.setPosition(180,290);
}

Front_end::~Front_end()
{
    //dtor
}

void Front_end::show_score()
{
    if(game_over)
    {   if(level==0)
        {
            window.draw(your_score.get());
            return;
        }
        if(level==1)
        {
            window.draw(enter_your_nickname.get());

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {tech_stuff.name_load('a',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {tech_stuff.name_load('b',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {tech_stuff.name_load('c',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {tech_stuff.name_load('d',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {tech_stuff.name_load('e',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {tech_stuff.name_load('f',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {tech_stuff.name_load('g',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {tech_stuff.name_load('h',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {tech_stuff.name_load('i',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {tech_stuff.name_load('j',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {tech_stuff.name_load('k',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {tech_stuff.name_load('l',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {tech_stuff.name_load('m',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {tech_stuff.name_load('n',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {tech_stuff.name_load('o',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {tech_stuff.name_load('p',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {tech_stuff.name_load('r',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {tech_stuff.name_load('s',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {tech_stuff.name_load('t',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {tech_stuff.name_load('u',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {tech_stuff.name_load('w',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {tech_stuff.name_load('z',0); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {tech_stuff.name_load('a',1); Sleep(150);}
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) level=2;

            name.setString(tech_stuff.get_name());
            window.draw(name);

            return;
        }
        if(level==2||level==3)
        {
            window.draw(top10Scores.get());
            if(level==2)
            {
                tech_stuff.update_scoreboard();
                level=3;

            }

            std::list<score>::iterator it;
            it=tech_stuff.scoreboard.begin();

            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,132);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,134);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,168);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,170);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,204);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,206);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,240);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,242);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,276);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,278);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,312);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,314);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,348);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,350);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,384);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,386);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,420);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,422);
            window.draw(scoreboard_text);
            it++;
            scoreboard_text.setString(it->name);
            scoreboard_text.setPosition(180,456);
            window.draw(scoreboard_text);
            scoreboard_text.setString(std::to_string(it->points));
            scoreboard_text.setPosition(400,458);
            window.draw(scoreboard_text);

            return;
        }

    }

}

void Front_end::update_SFML_events()
{
    while(window.pollEvent(eve))
    {
        if(eve.type==sf::Event::Closed) window.close();
    }
}

void Front_end::update()
{
    update_SFML_events();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Tab)) tech_stuff.ball_to_throw(); //cheats
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) tech_stuff.increase_gray_ball_number(); //cheats

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();

    tech_stuff.arrow_rotating(window);

    if(tech_stuff.collision_detection())
    {
        std::cout<<"wtf";
        game_over=true;  //game over (lost)
    }

    if(tech_stuff.moving_ball())
    {
        return;
    }

        bool end_game=true;
        for(int i=0; i<ARRAY_X_SIZE; i++)
        for(int j=0; j<ARRAY_Y_SIZE; j++)
        {
            if(tech_stuff.balls[i][j].ball_color!=BLANK)
                {
                    end_game=false;
                    break;
                }
        }

        if(end_game) game_over=true;

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) system("cls"); //logs

        if(game_over&&level== -1) level=0;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)&&
           sf::Mouse::getPosition(window).x>40&&
           sf::Mouse::getPosition(window).x<669&&
           sf::Mouse::getPosition(window).y>8&&
           sf::Mouse::getPosition(window).y<548)
        {
            if(sf::Mouse::getPosition(window).x>297&&
               sf::Mouse::getPosition(window).x<374&&
               sf::Mouse::getPosition(window).y>481&&
               sf::Mouse::getPosition(window).y<557&&
               level==0)
               {
                   level=1;
                   return;
               }
            if(sf::Mouse::getPosition(window).x>354&&
               sf::Mouse::getPosition(window).x<430&&
               sf::Mouse::getPosition(window).y>373&&
               sf::Mouse::getPosition(window).y<450&&
               level==1)
               {
                    level=2;
                    return;
               }
            if(sf::Mouse::getPosition(window).x>304&&
               sf::Mouse::getPosition(window).x<381&&
               sf::Mouse::getPosition(window).y>517&&
               sf::Mouse::getPosition(window).y<596&&
               (level==2||level==3))
               {
                   tech_stuff.reset();
                   level= -1;
                   Sleep(100);
                   game_over=false;
                   return;
               }
               else if(game_over) return;
            sf::Vector2i mouse_pos;
            mouse_pos=sf::Mouse::getPosition(window);
            tech_stuff.throwing_ball(mouse_pos.x,mouse_pos.y);
        }
        showing_points.setString(std::to_string(tech_stuff.get_points()));

}

void Front_end::render()
{
    window.clear(sf::Color(sf::Color::Black));

    window.draw(background.get());

    //drawing all balls:
    for(int i=0; i<ARRAY_X_SIZE; i++)
    {
        for(int j=0; j<ARRAY_Y_SIZE; j++)
        {
            balls.set_position(i*36+BASE_POINT_X+j%2*17,j*35+BASE_POINT_Y);
            window.draw(balls.get(tech_stuff.balls[i][j].ball_color));
        }
    }


    //drawing gray ball
    for(int i=0; i<tech_stuff.get_gray_ball_number(); i++)
    {
        gray_ball.set_position(28+40*i,578);
        window.draw(gray_ball.get());
    }

    window.draw(tech_stuff.get_arrow());
    window.draw(tech_stuff.get_actual_ball());
    window.draw(tech_stuff.get_next_ball());
    window.draw(showing_points);

    show_score();

    window.display();

}

void Front_end::run()
{
    while(window.isOpen())
    {
        update();
        render();
    }

}
