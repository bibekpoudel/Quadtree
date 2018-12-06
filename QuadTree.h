#ifndef QUADTREE_H
#define QUADTREE_H
//---------------------QUADTREE CLASS------------------//
#include "gameobject.h"
#include "Node.h"
#include <cmath>

class QuadTree
{
public:
QuadTree(Node * root, int Threshold, int MaxLevel)
        :root_(root), Threshold_(Threshold), MaxLevel_(MaxLevel)
    {}
    ~QuadTree()
    {
        delete root_;
    }
    
    void insert(GameObject);
    void insert(Node * , GameObject * );
    void CheckCollision(Node *);
    void MoveObjects(Node * );
    void MoveObjects();
    void DrawObjects(Node * );
    void DrawObjects();
public:
    Node * root_;
    int Threshold_;
    int MaxLevel_;
    
};

void QuadTree::MoveObjects(Node * node)
{
    if(!node->HasChildren())
    {
        for (auto p = node->Objects.begin(); p > node->Objects.end(); ++p)
        {
            (*p)->move();
        }
    }
    if(node->HasChildren())
    {
        MoveObjects(node->TopLeftNode);
        MoveObjects(node->TopRightNode);
        MoveObjects(node->BottomLeftNode);
        MoveObjects(node->BottomRightNode);
    }
    
}

void QuadTree::MoveObjects()
{
    MoveObjects(root_);
}

void QuadTree::DrawObjects(Node * node)
{
    if(!node->HasChildren())
    {
        for (auto p = node->Objects.begin(); p > node->Objects.end(); ++p)
        {
            (*p)->draw();
        }
    }
    if(node->HasChildren())
    {
        MoveObjects(node->TopLeftNode);
        MoveObjects(node->TopRightNode);
        MoveObjects(node->BottomLeftNode);
        MoveObjects(node->BottomRightNode);
    }
    
}

void QuadTree::DrawObjects()
{
    DrawObjects(root_);
}

void QuadTree::insert(GameObject object)
{
    insert(root_, &object);
}

bool Collide(GameObject object1, GameObject object2)
{
    int Distance =pow(pow((object1.x_-object2.x_),2)+pow((object1.y_-object2.y_),2), 0.5);
    return(Distance <= object1.r_+object2.r_);
}

void QuadTree::CheckCollision(Node *node)
{
    for(int i = 0; i < node->Objects.size(); ++i)
    {
        for(int j = i; i < node->Objects.size(); ++i)
        {
            if(i != j)
            {
                if(Collide(*(node->Objects[i]), *(node->Objects[j])))
                {
                    node->Objects[i]->change_color();
                    node->Objects[j]->change_color();
                }
                
            }
        }   
    }
    
    if(!node->HasChildren())
    {
        return;
    }
}

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
    if(node->level_ == MaxLevel_)
    {
        return;
    }
    
    node->Objects.push_back(object);
//---------------------------------------
    //Insert all game objects into a vector in a Quad Tree
    
    if((node->NumOfObjects()) > Threshold_)
    {
        node->TopLeftNode = new Node(node->TopLeftPoint_,
                               (Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                      (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)),
                                     node , (node->level_)+1);
        
        node->TopRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,node->TopLeftPoint_.y_),
                                (Point(node->BottomRightPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)),
                                      node , (node->level_)+1);

        node->BottomLeftNode = new Node(Point(node->TopLeftPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2),
                                  Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2, node->BottomRightPoint_.y_),
                                        node , (node->level_)+1);

        node->BottomRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                               (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2), node->BottomRightPoint_,
                                         node , (node->level_)+1);        
        
        for(auto p=node->Objects.begin(); p < node->Objects.end(); ++p)
        {
            insert(node->TopLeftNode, *p);
            insert(node->TopRightNode, *p);
            insert(node->BottomLeftNode, *p);
            insert(node->BottomRightNode, *p);
        }

        node->Objects.clear();
        
    }
    
}
#endif
