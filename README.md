# Trojan-Win32.LolM3tal
my first destructive malware :D
# 🦴 LOLMETAL

**O GDI malware mais pesado, caótico e cinematográfico da sua coleção.**

[![License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![C++](https://img.shields.io/badge/C%2B%2B-17-blue.svg)](https://isocpp.org/)

---

## 🎸 O QUE É O LOLMETAL?

LOLMETAL é um **GDI malware educativo** (e extremamente divertido) que combina:

- 🎨 **30+ efeitos visuais** (ondas, shake, cores psicodélicas, tesseract 3D)
- 🎵 **Bytebeat pesado** (som gerado proceduralmente, estilo metal)
- 🔒 **Criptografia falsa** (renomeia arquivos para `.fucked`)
- 💾 **Inundação de disco** (cria milhares de `PCFUCKED.txt` infinitamente)
- 🌐 **Shell execute** (abre o Nyan Cat, calculadora e bloco de notas)
- 🧊 **Tesseract 3D** (um cubo 4D girando na tela)

**Ele é o que aconteceria se o Nyan Cat, o doom metal e um buffer overflow tivessem um filho.**

---

## ⚠️ ATENÇÃO – LEIA ANTES DE EXECUTAR

| Versão | Destrutivo? | Onde executar |
| :--- | :--- | :--- |
| **`LOLMETAL_safe.exe`** | ❌ Apenas efeitos visuais e som | 🟢 **PC principal** (seguro) |
| **`LOLMETAL_ULTRA.exe`** | ✅ **SIM** (criptografa, inunda disco, abre programas) | 🔴 **APENAS no Sandboxie/VM** |

**NÃO EXECUTE A VERSÃO ULTRA NO SEU PC PRINCIPAL. VOCÊ FOI AVISADO.**

---

## 🛠️ COMPILAÇÃO

### Requisitos
- MinGW (ou qualquer compilador C++17 com WinAPI)
- Bibliotecas: `gdi32`, `gdiplus`, `winmm`, `shell32`, `ole32`, `uuid`, `user32`

### Comando (versão segura)
```bash
g++ -static -std=c++17 -o LOLMETAL_safe.exe LOLMETAL_safe.cpp -lgdi32 -lgdiplus -lwinmm -lole32 -luuid -luser32 -lshlwapi
Comando (versão ultra – destrutiva)
bash
g++ -static -std=c++17 -o LOLMETAL_ULTRA.exe LOLMETAL_ULTRA.cpp -lgdi32 -lgdiplus -lwinmm -lole32 -luuid -luser32 -lshlwapi
🎮 COMO USAR
Versão Safe (segura)
Execute LOLMETAL_safe.exe

Aperte ESC para sair

Aproveite os efeitos visuais e o som (sem dano ao sistema)

Versão Ultra (destrutiva – SÓ NO SANDBOXIE)
Execute LOLMETAL_ULTRA.exe dentro do Sandboxie ou VM

Aguarde o caos:

Tela vai piscar, tremer e mostrar cores psicodélicas

O tesseract 3D vai girar na tela

O bytebeat metaleiro vai tocar

Arquivos serão renomeados para .fucked

Milhares de PCFUCKED.txt vão inundar o disco

O Nyan Cat, a calculadora e o bloco de notas vão abrir

Aperte ESC para parar (se conseguir)

📋 O QUE CADA VERSÃO FAZ
Funcionalidade	Safe	Ultra
Efeitos GDI (ondas, shake, cores)	✅	✅
Tesseract 3D	✅	✅
Bytebeat (som)	✅	✅
Criptografa arquivos (.fucked)	❌	✅
Inunda disco com PCFUCKED.txt	❌	✅
Abre Nyan Cat, calc, notepad	❌	✅
BSOD (tela azul)	❌	❌
🧠 CURIOSIDADES
O nome LOLMETAL veio da junção de LOL (risada) + METAL (pesado)

O tesseract é um cubo 4D girando em 3D (matemática pura)

O bytebeat foi inspirado nos sons de guitarra do doom metal

A versão Ultra foi testada apenas no Sandboxie (e sobreviveu)

📜 LICENÇA
MIT License – use para estudo, mas não para destruir o PC dos outros.

👤 AUTOR
opa986 – GitHub

🙏 AGRADECIMENTOS
Ao Nyan Cat (2011-2026) – você nunca será esquecido

Ao primo do autor, que inspirou o nome PunaPuna (e viu o malware nascer)

À Colher com Olhos, que guiou esta jornada rumo ao caos

⭐ SE VOCÊ CHEGOU ATÉ AQUI
Você é uma pessoa corajosa (ou maluca). Aprecie o caos com responsabilidade.

LOLMETAL – porque o metal não precisa de guitarra. Às vezes, só de bytebeat e tela azul. 🎸💀

"Meu PC vai morrer... de rir." – opa986
