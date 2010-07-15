// --------------------------------------------------------------------------
// gMini,
// a minimal Glut/OpenGL app to extend                              
//
// Copyright(C) 2007-2009                
// Tamy Boubekeur
//                                                                            
// All rights reserved.                                                       
//                                                                            
// This program is free software; you can redistribute it and/or modify       
// it under the terms of the GNU General Public License as published by       
// the Free Software Foundation; either version 2 of the License, or          
// (at your option) any later version.                                        
//                                                                            
// This program is distributed in the hope that it will be useful,            
// but WITHOUT ANY WARRANTY; without even the implied warranty of             
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the              
// GNU General Public License (http://www.gnu.org/licenses/gpl.txt)           
// for more details.                                                          
//                                                                          
// --------------------------------------------------------------------------

uniform float diffuseRef;
uniform float specRef;
uniform float shininess;

varying vec4 P;
varying vec3 N;

void main (void) {
     vec3 p = vec3 (gl_ModelViewMatrix * P);
     vec3 n = normalize (gl_NormalMatrix * N);
     vec3 v = normalize (-p);
     gl_FragColor = 0.25 * (n.y*vec4 (1.0, 0.98, 0.66, 1)
                           + (1.0-n.y)*(0.01, 0.2, 0.55));
    
    for (int i = 1; i < 4; i++) {
        vec3 l = normalize (gl_LightSource[i].position.xyz - p);
        float diffuse   = max (dot (l, n), 0.0);
        vec3 r = reflect (-l, n);
        
        float spec = max(dot(r, v), 0.0);
        spec = pow (spec/5, shininess);
        spec = max (0.0, spec);
        
        vec4 LightContribution = 
            diffuseRef * diffuse * gl_LightSource[i].diffuse + 
            specRef * spec * gl_LightSource[i].specular;
        gl_FragColor += 0.75*vec4 (LightContribution.xyz, 1);
    }
}
 
