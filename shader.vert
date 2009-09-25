// --------------------------------------------------
// Phong Vertex Shader.
// Author : Tamy Boubekeur.
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------

varying vec4 P;
varying vec3 N;

void main(void)
{
    P = gl_Vertex;
    N = gl_Normal;
    
    gl_Position = ftransform ();
    gl_FrontColor = gl_Color;
}
