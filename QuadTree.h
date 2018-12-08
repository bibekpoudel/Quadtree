#ifndef QUADTREE_H
#define QUADTREE_H
//---------------------QUADTREE CLASS------------------//
#include "gameobject.h"
#include "Node.h"
#include <cmath>
//#include <iostream>

class QuadTree
{
public:
QuadTree()
    {
        root_ = new Node(Point(0,0), Point(640,480), NULL, 0);
        Threshold_ = 5;
        MaxLevel_ = 10;
        std::cout << root_ << '\n';
    }
    ~QuadTree()
    {
        delete root_;
    }
    
    void insert(GameObject*);
    void insert(Node * , GameObject * );
    void CheckCollision(Node * ,std::vector<GameObject*> &);
    bool Collide(GameObject * , GameObject *);
    std::vector< GameObject* > get_colliding_pairs(std::vector<GameObject * > );
   
public:
    Node * root_;
    int Threshold_;
    int MaxLevel_;
    
};

/* std::vector< std::vector< GameObject* > > QuadTree::get_colliding_pairs(std::vector<GameObject * > object) */
/* { */
/*     for(int i = 0; i < object.size(); ++i) */
/*     { */
/*         insert(object[i]); */
/*     } */

    
/*     return; */
/* } */

std::vector< GameObject* > QuadTree::get_colliding_pairs(std::vector<GameObject * > object)
{
   
    std::vector<GameObject* > collision_pairs;
    
    for(int i = 0; i < object.size(); ++i)
    {
        insert(object[i]);
    }
    CheckCollision(root_, collision_pairs);
    
    // std::cout << "Size: " << collision_pairs.size() << '\n';
    return collision_pairs;
}


void QuadTree::CheckCollision(Node * node, std::vector<GameObject*> & collision_pairs)
{
    if(!node->HasChildren()) 
     { 
     
        for(int i = 0; i < node->Objects.size(); ++i)
        {
            for(int j = i; i < node->Objects.size(); ++i)
            {
                if(i != j)
                {
                    if(Collide(node->Objects[i], node->Objects[j]))
                    {
                        std::cout << "-------------------\n";
                        std::cout << "Collide!!!" << '\n';
                        std::cout << "Collision between: \n"
                                  << node->Objects[i] << " & " << node->Objects[j] << '\n'
                                  << "i:" << *(node->Objects[i]) << "Level :" << node->level_
                                  << "\nj:" << *(node->Objects[j]) << '\n';
                        std::cout << "-------------------\n";
                        collision_pairs.push_back(node->Objects[i]);
                        collision_pairs.push_back(node->Objects[j]);
                    }
                
                }
            }
        }
         
     
    }
    if(node->HasChildren())
    {
        CheckCollision(node->TopLeftNode, collision_pairs);
        CheckCollision(node->TopRightNode, collision_pairs);
        CheckCollision(node->BottomLeftNode, collision_pairs);
        CheckCollision(node->BottomRightNode, collision_pairs);
    }
    
}


/* void QuadTree::MoveObjects(Node * node) */
/* { */
/*     // std::cout << node <<std::endl; */
/*     if(!node->HasChildren()) */
/*     { */
/*         //  std::cout << node->Objects.size() << '\n'; */
/*         for(int i=0; i < node->Objects.size(); ++i) */
/*         { */
/*             //           std::cout << "x: " << node->Objects[i]->x_ << '\n'; */
/*             // std::cout << *(node->Objects[i]); */
/*             node->Objects[i]->move(); */
/*         } */
     
/*     } */
/*     if(node->HasChildren()) */
/*     { */
/*         MoveObjects(node->TopLeftNode); */
/*         MoveObjects(node->TopRightNode); */
/*         MoveObjects(node->BottomLeftNode); */
/*         MoveObjects(node->BottomRightNode); */
/*     } */
    
/* } */

/* void QuadTree::MoveObjects() */
/* { */
/*     std::cout << "I'm here!\n"; */
   
/*     MoveObjects(this->root_); */
/* } */

/* void QuadTree::DrawObjects(Node * node) */
/* { */
/*     if(!node->HasChildren()) */
/*     { */
/*          for(int i=1; i < node->Objects.size(); ++i) */
/*          { */
/*              /\* std::cout << node->Objects[i]; *\/ */
/*              node->Objects[i]->draw(); */
/*         } */
       
/*         /\* for (auto p = node->Objects.begin(); p != node->Objects.end(); ++p) *\/ */
/*         /\* { *\/ */
/*         /\*     std::cout << "I'm here!\n"; *\/ */
/*         /\*     (*p)->draw(); *\/ */
/*         /\* } *\/ */
/*         /\* return; *\/ */
/*     } */
    
/*     if(node->HasChildren()) */
/*     { */
        
/*         DrawObjects(node->TopLeftNode); */
/*         DrawObjects(node->TopRightNode); */
/*         DrawObjects(node->BottomLeftNode); */
/*         DrawObjects(node->BottomRightNode); */
/*     } */
    
/* } */

/* void QuadTree::DrawObjects() */
/* { */
/*     DrawObjects(root_); */
/* } */

void QuadTree::insert(GameObject * object)
{
    insert(root_, object);
}

bool QuadTree::Collide(GameObject * object1, GameObject * object2)
{
    int dx = object1->x_- object2->x_;
    int dy = object1->y_- object2->y_;

   int  distance = pow((dx * dx + dy * dy), 0.5);
    
   return(distance <= (object1->r_+object2->r_));
}

/* void QuadTree::CheckCollision(Node *node) */
/* { */
/*     for(int i = 0; i < node->Objects.size(); ++i) */
/*     { */
/*         for(int j = i; i < node->Objects.size(); ++i) */
/*         { */
/*             if(i != j) */
/*             { */
/*                 if(Collide(*(node->Objects[i]), *(node->Objects[j]))) */
/*                 { */
/*                     node->Objects[i]->change_color(); */
/*                     node->Objects[j]->change_color(); */
/*                 } */
                
/*             } */
/*         }    */
/*     } */
    
/*     if(!node->HasChildren()) */
/*     { */
/*         return; */
/*     } */
/* } */

void QuadTree::insert(Node * node, GameObject * object)
{

   
    if ( node == NULL)
    {
        return;
    }
   
//---------------------------------------
    if(!node->InBound(object))//Checks if the node is in boundary else returns
    {
        return;
    }
   
    if(node->level_ == MaxLevel_+1)
    {
        return;
    }

    //   std::cout << *object << '\n';
    node->Objects.push_back(object);
    // std::cout << *node->Objects.back() << '\n';
  
//---------------------------------------
    //Insert all game objects into a vector in a Quad Tree

     std::cout << "Node: " << node << '\n';
     std::cout << "Level: " << node->level_ << '\n';
     std::cout << "Top Left Point: " << node->TopLeftPoint_.x_ << '\n';
     std::cout << "Bottom Right Point: " << node->BottomRightPoint_.x_ << '\n';
     std::cout << "________________________________________\n";
    if((node->NumOfObjects()) > Threshold_)
    {
        node->TopLeftNode = new Node(node->TopLeftPoint_,
                               (Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                      (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)),
                                     node , node->level_+1);
        node->TopRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,node->TopLeftPoint_.y_),
                                (Point(node->BottomRightPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)),
                                      node , node->level_+1);

        node->BottomLeftNode = new Node(Point(node->TopLeftPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2),
                                  Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2, node->BottomRightPoint_.y_),
                                        node , node->level_+1);

        node->BottomRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                               (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2), node->BottomRightPoint_,
                                         node , node->level_+1);        

        for(int i = 0; i < node->Objects.size(); ++i)
        {
            insert(node->TopLeftNode, node->Objects[i]);
            insert(node->TopRightNode, node->Objects[i]);
            insert(node->BottomLeftNode,node->Objects[i]);
            insert(node->BottomRightNode, node->Objects[i]);
        }
        node->Objects.clear();
        
    }
//    std::cout  << node <<std::endl;
}


/* std::ostream & operator<<(std::ostream & cout, const QuadTree * quad) */
/* { */
/*     cout << "------------------QuadTree------------------\n"; */
/*     Node * currentnode = quad->root_; */
/*     cout << "Root: " << currentnode << '\n'; */

/*         if(currentnode->HasChildren()) */
/*         { */
/*             cout << "Current Node: " << currentnode << '\n'; */
/*             cout << currentnode->TopLeftNode << '\n'; */
/*             cout << currentnode->TopRightNode << '\n'; */
/*             cout << currentnode->BottomLeftNode << '\n'; */
/*             cout << currentnode->BottomRightNode << '\n'; */
/*             /\* currentnode->TopLeftNode; *\/ */
/*             /\* currentnode->TopRightNode; *\/ */
/*             /\* currentnode->BottomLeftNode; *\/ */
/*             /\* currentnode->BottomRightNode; *\/ */
/*         } */
/*         else */
/*         { */
/*             cout << "Current Node: " << currentnode << '\n'; */
/*         } */
 
    
/*     return cout; */

    
/* } */

#endif
