// --------------------------------------------------
// Phong Fragment Shader.
// Author : Tamy Boubekeur.
// Copyright (C) 2008 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------

uniform float diffuseRef;
uniform float specRef;
uniform float shininess;

varying vec4 P;
varying vec3 N;

void main (void) {
    gl_FragColor = vec4 (0.0, 0.0, 0.0, 1);
    
    for (int i = 1; i < 4; i++) {
        vec3 p = vec3 (gl_ModelViewMatrix * P);
        vec3 n = normalize (gl_NormalMatrix * N);
        vec3 l = normalize (gl_LightSource[i].position.xyz - p);
        float diffuse   = max (dot (l, n), 0.0);
        vec3 r = reflect (l, n);
        vec3 v = normalize (-p);
        
        float spec = max(dot(r, v), 0.0);
        spec = pow (spec, shininess);
        spec = max (0.0, spec);
        
        vec4 LightContribution = 
            diffuseRef * diffuse * gl_LightSource[i].diffuse + 
            specRef * spec * gl_LightSource[i].specular;
        gl_FragColor += vec4 (LightContribution.xyz, 1);
    }
}
 
