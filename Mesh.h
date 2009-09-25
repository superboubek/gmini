// --------------------------------------------------
// Author : Tamy Boubekeur.
// Copyright (C) 2006-2009 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------

#pragma once

#include <vector>

#include "Vertex.h"
#include "Triangle.h"
#include "Edge.h"

class Mesh {
public:
    inline Mesh () {} 
    inline Mesh (const std::vector<Vertex> & v) : vertices (v) {}
    inline Mesh (const std::vector<Vertex> & v, 
                 const std::vector<Triangle> & t) : vertices (v), triangles (t)  {}
    inline Mesh (const Mesh & mesh) : vertices (mesh.vertices), triangles (mesh.triangles) {}
    inline virtual ~Mesh () {}
    std::vector<Vertex> & getVertices () { return vertices; }
    const std::vector<Vertex> & getVertices () const { return vertices; }
    std::vector<Triangle> & getTriangles () { return triangles; }
    const std::vector<Triangle> & getTriangles () const { return triangles; }
    void clear ();
    void clearGeometry ();
    void clearTopology ();
    void recomputeSmoothVertexNormals (unsigned int weight);
    void computeTriangleNormals (std::vector<Vec3Df> & triangleNormals);  
    void collectOneRing (std::vector<std::vector<unsigned int> > & oneRing) const;
  
private:
    std::vector<Vertex> vertices;
    std::vector<Triangle> triangles;
};

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End:
