// --------------------------------------------------
// Author : Tamy Boubekeur.
// Copyright (C) 2006-2009 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------
  
#include "Triangle.h"

using namespace std;

ostream & operator<< (ostream & output, const Triangle & t) {
  output << t.getVertex (0) << " " << t.getVertex (1) << " " << t.getVertex (2);
  return output;
}
