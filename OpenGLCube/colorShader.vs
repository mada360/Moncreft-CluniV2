attribute vec3 aPositionVertex;

void main(){
    gl_Position = gl_ModelViewProjectionMatrix * aPositionVertex;
}