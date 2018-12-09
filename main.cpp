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
    const int NUM_OBJECT = 100;
    Event event;
    Surface surface;


    std::vector<GameObject *> object; // 
    for(int i = 0; i < NUM_OBJECT; ++i)
    {
        object.push_back(new GameObject(rand() % W, rand() % H, 5, // rand() % 8 + 2, rand() % 8 + 2
                                        2,2
                                        , 255, 0, 0, surface));
    }

    // for(int i = 1; i < 30; ++i)
    // {
    //     object.push_back(new GameObject(i * 6,i * 4, 2, 0,0, 255, 0, 0, surface));
   
    // }
    // object.push_back(new GameObject(10,10, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(20,45, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(20,30, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(30,20, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(30,55, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(45,55, 5, 0,0, 255, 0, 0, surface));
    // object.push_back(new GameObject(400,35, 5, 0,0, 255, 0, 0, surface));
    

        

   
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
       
        Draw_Quad(qtree.root_, surface);
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
