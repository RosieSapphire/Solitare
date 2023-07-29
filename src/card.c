#include <stddef.h>
#include "card.h"
#include "texture.h"
#include "window.h"
#include <glad/glad.h>
#include "shader.h"

#define CARD_WIDTH 64
#define CARD_HEIGHT 100

static GLuint card_shader, vao, vbo, ebo;
static const GLuint indis[6] = {0, 1, 2, 2, 1, 3};
static GLuint heart_tex;

void cards_init(void)
{
	card_shader = shader_load("res/vert.glsl", "res/frag.glsl");

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE,
			sizeof(float) * 4, NULL);

	glGenBuffers(1, &ebo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,
			sizeof(indis), indis, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	heart_tex = texture_load("res/heart.png");
}

void card_draw(card c, int card_index, int stack_index)
{
	int card_x = CARD_WIDTH + (CARD_WIDTH * 1.2f * stack_index);
	int card_y = WIN_HEIGHT - (CARD_HEIGHT * 2) -
		((CARD_HEIGHT * 0.2f) * card_index);

	const float rect[4] = {
		(float)card_x / (float)WIN_WIDTH,
		(float)card_y / (float)WIN_HEIGHT,
		(float)CARD_WIDTH / (float)WIN_WIDTH,
		(float)CARD_HEIGHT / (float)WIN_HEIGHT,
	};

	float verts[4][4] = {
		{rect[0],           rect[1],           0, 1},
		{rect[0] + rect[2], rect[1],           1, 1},
		{rect[0],           rect[1] + rect[3], 0, 0},
		{rect[0] + rect[2], rect[1] + rect[3], 1, 0},
	};

	/*
	 * Normalizing the vertices to OpenGL's coordinate system.
	 */
	for(int i = 0; i < 2; i++) {
		for(int j = 0; j < 4; j++) {
			float *cur = &verts[j][i];
			*cur *= 2;
			*cur -= 1;
		}
	}

	glBindVertexArray(vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts,
			GL_DYNAMIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glUseProgram(card_shader);
	glUniform1i(glGetUniformLocation(card_shader, "u_is_visible"),
			c.is_visible);

	glBindTexture(GL_TEXTURE_2D, heart_tex);
	glDrawElements(GL_TRIANGLES, sizeof(indis) / sizeof(*indis),
			GL_UNSIGNED_INT, indis);
	glBindVertexArray(0);
}
