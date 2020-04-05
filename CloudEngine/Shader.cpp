#include "Shader.h"

Shader::Shader(const char* vertexPath, const char* fragmentPath)
{
	std::string vertexCode;
	std::string fragmentCode;
	std::ifstream vShaderFile;
	std::ifstream fShaderFile;

	vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	//reading from file
	try {
		vShaderFile.open(vertexPath);
		fShaderFile.open(fragmentPath);

		std::stringstream vShaderStream, fShaderStream;

		vShaderStream << vShaderFile.rdbuf();
		fShaderStream << fShaderFile.rdbuf();

		vShaderFile.close();
		fShaderFile.close();

		vertexCode = vShaderStream.str();
		fragmentCode = fShaderStream.str();
	}

	catch (std::ifstream::failure e) {
		std::cout << "ERROR:SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
	}

	const char* vShaderCode = vertexCode.c_str();
	const char* fShaderCode = fragmentCode.c_str();

	//creating the shaders
	unsigned int vertex, fragment;

	vertex = glCreateShader(GL_VERTEX_SHADER);
	//setting the source and compiling
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);

	int success;
	char infoLog[512];
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	// checking for errors
	if (!success) {
		glGetShaderInfoLog(vertex, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	//setting the srouce and compiling
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);

	//checking for errors
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);

	if (!success) {
		glGetShaderInfoLog(fragment, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	//creating the shader program and linking with the previously created shaders

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertex);
	glAttachShader(shaderProgram, fragment);
	glLinkProgram(shaderProgram);

	//checking for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::LINKING_FAILED\n" << infoLog << std::endl;
	}


	glGetShaderInfoLog(vertex, sizeof(infoLog), NULL, infoLog);
	std::cout << infoLog << std::endl;

	glGetShaderInfoLog(fragment, sizeof(infoLog), NULL, infoLog);
	std::cout << infoLog << std::endl;

	//deleting the shaders as we don't need them anymore
	glDeleteShader(vertex);
	glDeleteShader(fragment);
}
void Shader::Use()
{
	glUseProgram(shaderProgram);
}

void Shader::setVec4(const std::string& name, float x, float y, float z, float w) const
{
	glUniform4f(glGetUniformLocation(shaderProgram, name.c_str()), x, y, z, w);
}
