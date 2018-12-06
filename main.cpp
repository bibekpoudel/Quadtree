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
    const int NUM_OBJECT = 50;
    Event event;
    Surface surface;
    Node * root = new Node (Point(0,0), Point(640,480), NULL, 0);
    QuadTree Quad(root, 5, 6);

    for(int i = 0; i < NUM_OBJECT; ++i)
    {
        Quad.insert(GameObject(rand() % W, rand() % H, 2, rand() % 8 + 2, rand() % 8 + 2, 255, 0, 0, surface));
    }

    while(1)
    {
        
        
         if(event.poll())
         {
             if(event.type() == QUIT)
             {
                 break;
             }
         }
         
         
         Quad.MoveObjects();
         
         surface.lock();
         surface.fill(BLACK);
         
         Quad.DrawObjects();
        
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
