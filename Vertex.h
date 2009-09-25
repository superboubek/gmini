// --------------------------------------------------
// Author : Tamy Boubekeur.
// Copyright (C) 2006-2009 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------
   
#pragma once

#include <iostream>
#include <vector>

#include "Vec3D.h"

class Vertex {
public:
    inline Vertex () 
        : pos (Vec3Df (0.0,0.0,0.0)), normal (Vec3Df (0.0, 0.0, 1.0)) {}
    inline Vertex (const Vec3Df & pos) 
        : pos (pos), normal (Vec3Df (0.0, 0.0, 1.0)) {}
    inline Vertex (const Vec3Df & pos, const Vec3Df & normal) : pos (pos), normal (normal) {}
    inline Vertex (const Vertex & v) : pos (v.pos), normal (v.normal) {}
    inline virtual ~Vertex () {}
    inline Vertex & operator= (const Vertex & vertex) {
        pos = vertex.pos;
        normal = vertex.normal;
        return (*this);
    }
    inline const Vec3Df & getPos () const { return pos; }
    inline const Vec3Df & getNormal () const { return normal; }  
    inline void setPos (const Vec3Df & newPos) { pos = newPos; }
    inline void setNormal (const Vec3Df & newNormal) { normal = newNormal; }
    inline bool operator== (const Vertex & v) { return (v.pos == pos && v.normal == normal); }
    void interpolate (const Vertex & u, const Vertex & v, float alpha = 0.5);

    static void computeAveragePosAndRadius (std::vector<Vertex> & vertices, 
                                            Vec3Df & center, float & radius);
    static void scaleToUnitBox (std::vector<Vertex> & vertices, 
                                Vec3Df & center, float & scaleToUnitBox);
    static void normalizeNormals (std::vector<Vertex> & vertices);

private:
    Vec3Df pos;
    Vec3Df normal;
};

extern std::ostream & operator<< (std::ostream & output, const Vertex & v);

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End:
