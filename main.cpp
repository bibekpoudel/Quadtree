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

void Game()
{
    srand((unsigned int) time(NULL));
    const int NUM_OBJECT = 20;
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
        std::cout << &qtree << "a" << '\n';
     
       
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
