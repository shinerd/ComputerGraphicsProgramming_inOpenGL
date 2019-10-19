#version 410
uniform float offset;
void main(void) {
    if (gl_VertexID == 0) gl_Position = vec4(0.25 + offset, -0.25, 0.0, 1.0);
    else if (gl_VertexID == 1) gl_Position = vec4(-0.25 + offset, -0.25, 0.0, 1.0);
    else gl_Position = vec4(0.25 + offset, 0.25, 0.0, 1.0);
}
