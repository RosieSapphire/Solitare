#include "texture.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

GLuint texture_load(const char *path)
{
	uint8_t *data = NULL;
	int width, height, comp;
	GLuint tex;

	stbi_set_flip_vertically_on_load(0);
	data = stbi_load(path, &width, &height, &comp, 0);

	if(!data) {
		fprintf(stderr, "Failed to load texture from '%s'.\n", path);
		exit(1);
	}

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	
	const int formats[5] = {GL_NONE, GL_RED, GL_RG, GL_RGB, GL_RGBA};
	const int format = formats[comp];

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
			GL_UNSIGNED_BYTE, data);
	glBindTexture(GL_TEXTURE_2D, 0);
	stbi_image_free(data);

	return tex;
}

void textures_unload(int num, GLuint *start)
{
	glDeleteTextures(num, start);
}
