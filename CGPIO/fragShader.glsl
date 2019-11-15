#version 410

in vec2 tc;  // interpolated incoming texture coordinate

out vec4 color;

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

layout (binding=0) uniform sampler2D samp;

void main(void) {
    color = texture(samp, tc);
}
