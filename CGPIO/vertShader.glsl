#version 410

layout (location=0) in vec3 position;  // coord

uniform mat4 mv_matrix;
uniform mat4 proj_matrix;

out vec4 varyingColor;  // be interpolated by the rasterizer

void main(void) {
    gl_Position = proj_matrix * mv_matrix * vec4(position, 1.0);  // right-to-left
    varyingColor = vec4(position, 1.0) * 0.5 + vec4 (0.5, 0.5, 0.5, 0.5);
}
