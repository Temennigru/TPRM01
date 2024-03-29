//
//  RRT.h
//  TPRM01
//
//  Created by Jean-Luc Nacif Coelho on 9/30/14.
//  Copyright (c) 2014 GrupoRM. All rights reserved.
//

#ifndef __TPRM01__RRT__
#define __TPRM01__RRT__

#include <stdio.h>
#include "Graph2D.h"
#include "MovementRestrictions.h"


class RRT_t {
private:
    // The nodes in the graph
    std::vector<graph2D::node_t *> G;
    size_t nodeCnt;

    // The obstacles and restrictions
    MovementRestrictions_t *restrictions;

    // Adds a node to the graph, computing it's visibility towards all other nodes already in the graph
    bool addNode(graph2D::node_t * node);

public:

    // Constructor/Destructor
    RRT_t(MovementRestrictions_t *restrictions);
    ~RRT_t(void);

    // Finds a path between two points using the visibility graph
    void findPath(
                  uint16_t srcX, uint16_t srcY, uint16_t dstX, uint16_t dstY,
                  uint16_t * &x, uint16_t * &y, uint16_t &cnt
                  );

};



#endif /* defined(__TPRM01__RRT__) */
