#ifndef QUADTREE_H
#define QUADTREE_H
//---------------------QUADTREE CLASS------------------//
#include "gameobject.h"
#include "Node.h"

class QuadTree
{

public:
QuadTree(Node * root, int Threshold, int MaxDepth)
        :root_(root), Threshold_(Threshold), MaxDepth_(MaxDepth)
    {}
    ~QuadTree()
    {
        delete root_;
    }
    
    void insert(GameObject *);
    void insert(Node * , GameObject * );
public:
    Node * root_;
    int Threshold_;
    int MaxDepth_;
    
};

void QuadTree::insert(GameObject * object)
{
    insert(root_, object);
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
    
    node->Objects.push_back(object);
//---------------------------------------
    //Insert all game objects into a vector in a Quad Tree
    
    if((node->NumOfObjects()) > Threshold_)
    {
        node->TopLeftNode = new Node(node->TopLeftPoint_,
                               (Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                          (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)));
        
        node->TopRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,node->TopLeftPoint_.y_),
                                (Point(node->BottomRightPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2)));

        node->BottomLeftNode = new Node(Point(node->TopLeftPoint_.x_,(node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2),
                                  Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2, node->BottomRightPoint_.y_));

        node->BottomRightNode = new Node(Point((node->TopLeftPoint_.x_+node->BottomRightPoint_.x_)/2,
                                               (node->TopLeftPoint_.y_+node->BottomRightPoint_.y_)/2), node->BottomRightPoint_);

        
    }
    
}
/* void Quadtree::AddObject(Object *object) { */
/* 	if (level == maxLevel) { */
/* 		objects.push_back(object); */
/* 		return; */
/* 	} */
/* 	if (contains(NW, object)) { */
/* 		NW->AddObject(object); return; */
/* 	} else if (contains(NE, object)) { */
/* 		NE->AddObject(object); return; */
/* 	} else if (contains(SW, object)) { */
/* 		SW->AddObject(object); return; */
/* 	} else if (contains(SE, object)) { */
/* 		SE->AddObject(object); return; */
/* 	} */
/* 	if (contains(this, object)) { */
/* 		objects.push_back(object); */
/* 	} */
/* } */
#endif
