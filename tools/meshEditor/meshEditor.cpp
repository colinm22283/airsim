#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

void wi(std::ofstream* s, int x);
void wf(std::ofstream* s, float x);

int main()
{
    std::cout << "Filename: ";
    std::string fileName;
    std::cin >> fileName;
    std::ofstream s(fileName, std::ios::binary);

    int vertCount;
    std::cout << "Vert Count: ";
    std::cin >> vertCount;
    wi(&s, vertCount);

    for (int i = 0; i < vertCount; i++)
    {
        float x, y, z;
        float tx, ty;
        std::cout << "X: ";
        std::cin >> x;
        std::cout << "Y: ";
        std::cin >> x;
        std::cout << "Z: ";
        std::cin >> x;
        tx = 0;
        ty = 0;

        wf(&s, x); wf(&s, y); wf(&s, z);
        wf(&s, tx); wf(&s, ty);
    }

    int faceCount;
    std::cout << "Face Count: ";
    std::cin >> faceCount;
    wi(&s, faceCount);

    for (int i = 0; i < faceCount; i++)
    {
        int p[3];
        float x, y, z;
        std::cout << "P1: ";
        std::cin >> p[0];
        std::cout << "P2: ";
        std::cin >> p[1];
        std::cout << "P3: ";
        std::cin >> p[2];
        std::cout << "X: ";
        std::cin >> x;
        std::cout << "Y: ";
        std::cin >> x;
        std::cout << "Z: ";
        std::cin >> x;

        wi(&s, p[0]); wi(&s, p[1]); wi(&s, p[2]);
        wf(&s, x); wf(&s, y); wf(&s, z);
    }

    s.close();

    return 0;
}

void wi(std::ofstream* s, int x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + 4,
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}
void wf(std::ofstream* s, float x)
{
    char buf[4];
    std::copy(
        static_cast<const char*>(static_cast<const void*>(&x)),
        static_cast<const char*>(static_cast<const void*>(&x)) + sizeof(x),
        buf
    );
    for (int i = 0; i < 4; i++) *s << buf[i];
}