// --------------------------------------------------
// Author : Tamy Boubekeur.
// Copyright (C) 2006-2009 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------

#pragma once

#include "Vec3D.h"

class Camera {
public:
    Camera ();
  virtual ~Camera () {}
  
  inline float getFovAngle () const { return fovAngle; }
  inline void setFovAngle (float newFovAngle) { fovAngle = newFovAngle; }
  inline float getAspectRatio () const { return aspectRatio; }
  inline float getNearPlane () const { return nearPlane; }
  inline void setNearPlane (float newNearPlane) { nearPlane = newNearPlane; }
  inline float getFarPlane () const { return farPlane; }
  inline void setFarPlane (float newFarPlane) { farPlane = newFarPlane; }
  inline unsigned int getScreenWidth () const { return W; }
  inline unsigned int getScreenHeight () const { return H; }
  
  void resize (int W, int H);
  
  void initPos ();

  void move (float dx, float dy, float dz);
  void beginRotate (int u, int v);
  void rotate (int u, int v);
  void endRotate ();
  void zoom (float z);
  void apply ();
  
  void getPos (float & x, float & y, float & z);
  inline void getPos (Vec3Df & p) { getPos (p[0], p[1], p[2]); }
  
private:
  float fovAngle;
  float aspectRatio;
  float nearPlane;
  float farPlane;
  
  int spinning, moving;
  int beginu, beginv;
  int H, W;
  float curquat[4];
  float lastquat[4];
  float x, y, z;
  float _zoom;
};

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End: