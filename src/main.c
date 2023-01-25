#include <math.h>
#include <Windows.h>

void render() {
    const int width = 1024;
    const int height = 768;
    
}

int main(int argc, char *argv[]) {
    HDC hdc = GetDC(GetConsoleWindow());
    for(int x=0;x<256;++x)
        for(int y=0;y<256;++y)
            SetPixel(hdc, x, y, RGB(127, x, y));
}