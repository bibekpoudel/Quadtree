#ifndef NODE_H
#define NODE_H

#include <vector>
#include "gameobject.h"
//------------------------QUAD NODE CLASS---------------//
class Node
{
public:
Node(Point TopLeftPoint, Point BottomRightPoint)
    :TopLeftPoint_(TopLeftPoint), BottomRightPoint_(BottomRightPoint)
    {
        
    TopLeftNode = NULL;
    TopRightNode = NULL;
    BottomLeftNode = NULL;
    BottomRightNode = NULL;
    parent_ = NULL;
    
    }
    
    bool HasChildren()
    {
        return TopLeftNode != NULL;
    }

    bool InBound(GameObject object)
    {
        return(object.get_x() <= BottomRightPoint_.x_
               && object.get_x() >= TopLeftPoint_.x_
               && object.get_y() >= BottomRightPoint_.x_
               && object.get_y() <= TopLeftPoint_.y_
            );
    }

    bool is_root() const
    {
        return (parent_ == NULL);
    }

    
    const Node * const parent() const
    {
        return parent_;
    }
    
    int get_depth() const //depth
    {
        if(this->is_root())
        {
            return 0;
        }
        else
        {
            return (this->parent()->get_depth()+1);
        }
        
    }

    ~Node()
    {
        delete this->TopLeftNode;
        delete this->TopRightNode;
        delete this->BottomLeftNode;
        delete this->BottomRightNode;
    }
 
    
    

    
public:
    Point TopLeftPoint_;
    Point BottomRightPoint_;
    Node * parent_;
    Node * TopLeftNode;
    Node * TopRightNode;
    Node * BottomLeftNode;
    Node * BottomRightNode;
    std::vector<GameObject> Objects;
};
    
//-----------------------------------------------------//
#endif
//num of children
//parent
//children
//objects
/* Node::~Node() */
/* { */
/*     delete this->TopLeftNode; */
/*     delete this->TopRightNode; */
/*     delete this->BottomLeftNode; */
/*     delete this->BottomRightNode; */
/* } */
   

