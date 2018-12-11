#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include "Includes.h"
#include "Constants.h"
#include "compgeom.h"
#include "Surface.h"
#include "Event.h"

#include "Point.h"
#include "Node.h"
#include "QuadTree.h"
#include "gameobject.h"



void Draw_Quad(Node * node, Surface & surface)
{

    if(node == NULL)
    {
        return;
    }
    
    if(node->HasChildren())
    {
         
  
        int x1= (node->TopLeftPoint_.x_ + node->BottomRightPoint_.x_)/2;
        int y1= (node->TopLeftPoint_.y_ + node->BottomRightPoint_.y_)/2;
  
  
        surface.put_line(x1, node->BottomRightPoint_.y_ -1, x1, node->TopLeftPoint_.y_, 255, 0, 0);
        surface.put_line(node->TopLeftPoint_.x_, y1, node->BottomRightPoint_.x_-1, y1, 255, 0, 0);         
 
        Draw_Quad(node->TopLeftNode, surface);
        Draw_Quad(node->TopRightNode, surface);
        Draw_Quad(node->BottomLeftNode, surface);
        Draw_Quad(node->BottomRightNode, surface);
    }
    else
    {
        return;
    }
        
     
}

void Game()
{

    
    
    srand((unsigned int) time(NULL));
    const int NUM_OBJECT = 10;
    Event event;
    Surface surface;

    Music music("sounds/pop.wav");


    std::vector<GameObject *> object; // 
    for(int i = 0; i < NUM_OBJECT; ++i)
    {
        object.push_back(new GameObject(rand() % W, rand() % H, 2, rand() % 3 + 2, rand() % 3+ 2
                                        , 255, 0, 0, surface));
    }
    
 

    music.play();

    bool draw_lines = true;

    while(1)
    {

        KeyPressed keypressed = get_keypressed();
      
        QuadTree qtree;
     
        std::vector< GameObject* > CollidingPairs = qtree.get_colliding_pairs(object);
        // std::cout << &qtree << "a" << '\n';
     
       
        if(event.poll())
        {
            if(event.type() == QUIT)
            {
                break;
            }
            else if (event.type() == KEYDOWN)
            {
                if(keypressed[SPACE])
                {
                    draw_lines = !draw_lines;
                    
                }
            }
     
                if(mouse_left())
                {
                    //  std::cout << mouse_x() << ' ' << mouse_y() << '\n';
                    object.push_back(new GameObject(mouse_x(), mouse_y(), 2, rand() % 3 + 2, rand() % 3+ 2
                                                    , 255, 0, 0, surface));
                }
          
            
           
        }



        for(int i = 0; i < CollidingPairs.size(); ++i)
        {
            CollidingPairs[i]->change_color();
            CollidingPairs[i]->change_speed();
            
            CollidingPairs[i]->move();
            //   CollidingPairs[i]->x_ = ;
            
        }
        
        
        for(int i = 0; i < object.size(); ++i)
        {
            object[i]->move();
        }

          
         
         
        //      Quad.MoveObjects();
        //      // for(int i = 0; i < object.size(); ++i)
        //      // {
        //      //     object[i].move();
        //      // }
        surface.lock();
        surface.fill(BLACK);
         
     
        // std::cout << root->Objects.size() << '\n';
        for(int i = 0; i < object.size(); ++i)
        {
            object[i]->draw();
            // std::cout << "---------------\n";
            // std::cout << object[i] << '\n';
            // std::cout << "Object: " << *object[i];
        }
        if(draw_lines)
        {
            Draw_Quad(qtree.root_, surface);
        }
// for(int i = 0; i < CollidingPairs.size(); ++i)
        // {
        //     CollidingPairs[i]->draw();
              
        //    // std::cout << "Drawing---------------\n";
        //    // std::cout << CollidingPairs[i] << '\n';
        //    // std::cout << "Object: " << *CollidingPairs[i];
        // }
         
        surface.unlock();
         
        surface.flip();
         
        delay(20);
   
    }
}

int main()
{

    Game();
    return 0;
}
