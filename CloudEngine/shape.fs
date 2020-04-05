#version 330 core

layout (location = 0) out vec4 fragColor;

in vec4 fragPos;
in vec2 TextCoords;

uniform sampler2D texture;
uniform bool useTexture;

void main()
{
    if(useTexture){
        fragColor = texture(texture, TextCoords);
	}
    else {
        fragColor = vec4(100, 0, 0, 1);
	}
    
}