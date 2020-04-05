#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
class Shader
{
	public:
		unsigned int shaderProgram;

		Shader(const char* vertexPath, const char* fragmentPath);
		Shader() = default;
		void Use();

		void setVec4(const std::string& name, float x, float y, float z, float w) const;
		void setInt(const std::string& name, int val) const;
		void setBool(const std::string& name, bool val) const;
};
#endif
