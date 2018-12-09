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
    std::cout << "I'm here!!" << std::endl;     
    int x1= (node->TopLeftPoint_.x_ + node->BottomRightPoint_.x_)/2;
    int y1= (node->TopLeftPoint_.y_ + node->BottomRightPoint_.y_)/2;
    std::cout << "I'm here1!!" << std::endl;     
    std::cout << x1 << " " <<  node->BottomRightPoint_.y_<< " " << x1 << " " << node->TopLeftPoint_.y_ << std::endl;
    surface.put_line(x1, node->BottomRightPoint_.y_ -1, x1, node->TopLeftPoint_.y_, 255, 0, 0);
    surface.put_line(node->TopLeftPoint_.x_, y1, node->BottomRightPoint_.x_-1, y1, 255, 0, 0);         
  std::cout << "I'm here2!!" << std::endl;
   std::cout << "I'm here2!!" << std::endl;     

   
    if(node->HasChildren())
    {
        Draw_Quad(node->TopLeftNode, surface);
        Draw_Quad(node->TopRightNode, surface);
        Draw_Quad(node->BottomLeftNode, surface);
        Draw_Quad(node->BottomRightNode, surface);
    }
        
        

    if(!(node->HasChildren()))
    {
        return;
    }
              
}

void Game()
{
    srand((unsigned int) time(NULL));
    const int NUM_OBJECT = 100;
    Event event;
    Surface surface;


    std::vector<GameObject *> object;
    for(int i = 0; i < NUM_OBJECT; ++i)
    {
        object.push_back(new GameObject(rand() % W, rand() % H, 5, rand() % 8 + 2, rand() % 8 + 2, 255, 0, 0, surface));
    }


        

   
    // std::vector< std::vector< GameObject* > > CollidingPairs = qtree.get_colliding_pairs(object);

  
   
// std::cout << root << '\n';
    // // std::vector<GameObject> object;
    // // for(int i = 0; i < 50; ++i)
    // // {
    // //     object.push_back();
    // // }
    
    // for(int i = 0; i < NUM_OBJECT; ++i)
    // {
    //     Quad.insert(GameObject(rand() % W, rand() % H, 2, rand() % 8 + 2, rand() % 8 + 2, 255, 0, 0, surface));
    // }

  

    while(1)
    {
     
        QuadTree qtree;
     
        std::vector< GameObject* > CollidingPairs = qtree.get_colliding_pairs(object);
        // std::cout << &qtree << "a" << '\n';
     
       
        if(event.poll())
        {
            if(event.type() == QUIT)
            {
                break;
            }
        }
         
        for(int i = 0; i < object.size(); ++i)
        {
            object[i]->move();
        }

        for(int i = 0; i < CollidingPairs.size(); ++i)
        {
            CollidingPairs[i]->change_color();
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
        std::cout << "I'm working!!!" << std::endl;
        Draw_Quad(qtree.root_, surface);
           std::cout << "I'm working!!!" << std::endl;
        // for(int i = 0; i < CollidingPairs.size(); ++i)
        // {
        //     CollidingPairs[i]->draw();
              
        //    // std::cout << "Drawing---------------\n";
        //    // std::cout << CollidingPairs[i] << '\n';
        //    // std::cout << "Object: " << *CollidingPairs[i];
        // }
         
        surface.unlock();
         
        surface.flip();
         
        delay(25);
    }
}

int main()
{

    Game();
    return 0;
}
