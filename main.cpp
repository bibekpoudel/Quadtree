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
    std::vector < GameObject > object;
    for (int i = 0; i < NUM_OBJECT; ++i)
    {
        object.push_back(GameObject(rand() % W, rand() % H, 2, rand() % 8 + 2, rand() % 8 + 2, 255, 0, 0, surface));
        object.push_back(GameObject(rand() % W, rand() % H, 1, rand() % 8 + 2, rand() % 8 + 2, 255, 0, 0, surface));
        
        // object.push_back(GameObject(rand() % W, rand() % H, 1, 1, 2, 2, rand() % 256, rand() % 100, rand() % 100, surface));
        
        // object.push_back(GameObject(rand() % W, rand() % H, 1, 1, 3, 3, rand() % 100, rand() % 256, rand() % 100, surface));
        
        // object.push_back(GameObject(rand() % W, rand() % H, 1, 1, 4, 4, rand() % 256, rand() % 256, rand() % 256, surface));
       
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
        for (int i = 0; i < object.size(); ++i)
        {
            object[i].move();
        }
    
        surface.lock();
        surface.fill(BLACK);
        for (int i = 0; i < object.size(); ++i)
        {
            object[i].draw();
        }
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
