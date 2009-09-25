// --------------------------------------------------
// Author : Tamy Boubekeur.
// Copyright (C) 2006-2009 Tamy Boubekeur.
// All rights reserved.
// --------------------------------------------------
  
#pragma once

#include <string>

#define GLEW_STATIC 1
#include <GL/glew.h>

  
class Shader {
public:
	Shader ();
	virtual ~Shader ();
	inline bool hasVertexShader () const { return (vertexShaderSize > 0); }
	inline bool hasFragmentShader () const { return (fragmentShaderSize > 0); }
	inline GLuint getShaderProgram () { return shaderProgram; }
	inline GLuint getVertexShader () { return vertexShader; }
	inline GLuint getFragmentShader () { return fragmentShader; }
	void loadFromFile (const std::string & vertexShaderFilename, 
					   const std::string & fragmentShaderFilename);
	inline void loadFromFile (const std::string & vertexShaderFilename) { 
        loadFromFile (vertexShaderFilename, ""); 
	}
	void bind ();
	void unbind ();
	
protected:
	GLchar * readShaderSource (const std::string & shaderFilename, unsigned int & shaderSize);
	GLint getUniLoc (GLuint program, const GLchar *name);
	inline GLint getUniLoc( const GLchar*name) { return getUniLoc (shaderProgram, name); }
	void compileAttach (GLuint & shader, GLenum type, const GLchar ** source);
	static void printShaderInfoLog (GLuint shader);
	static void printProgramInfoLog (GLuint program);
	/// Returns the size in bytes of the shader fileName. If an error occurred, it returns -1.
	static unsigned int getShaderSize (const std::string & shaderFilename);
	
private:
	GLuint shaderProgram, vertexShader, fragmentShader;
	unsigned int vertexShaderSize, fragmentShaderSize;
};
  
  
class ShaderException  {
public:
	ShaderException (const std::string & msg) : message (msg) {}
	virtual ~ShaderException () {}
	const std::string & getMessage () const { return message; }
private:
	std::string message;
};

// Some Emacs-Hints -- please don't remove:
//
//  Local Variables:
//  mode:C++
//  tab-width:4
//  End:
