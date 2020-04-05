#version 330 core

layout (location = 0) out vec4 fragColor;

in vec4 fragPos;
in vec2 TextCoords;


void main()
{
    fragColor = vec4(0.5, 0.5, 0.5, 1.0);
}