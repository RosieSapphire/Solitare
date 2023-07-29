#version 330 core
	
in vec2 o_uv;

uniform sampler2D u_suit_tex;
uniform bool u_is_visible;

out vec4 frag_color;

void main()
{
	if(u_is_visible) {
		vec4 tex = texture(u_suit_tex, o_uv);
		vec4 base = vec4(1, 1, 1, 1) - vec4(tex.a);
		frag_color = base + tex;
	} else {
		frag_color = vec4(0, 0, distance(o_uv, vec2(0.5)), 0);
	}
}
