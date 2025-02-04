# Temporizador com LEDs
Este projeto é um temporizador simples que controla três LEDs (vermelho, azul e verde) usando um Raspberry Pi Pico. O temporizador alterna entre os LEDs a cada 3 segundos.

## Estrutura do Projeto
.gitignore
.vscode/
build/
CMakeLists.txt
diagram.json
pico_sdk_import.cmake
Temporizador.c
wokwi.toml

## Configuração do Ambiente
1. Instale o SDK do Raspberry Pi Pico seguindo as instruções [aqui](https://github.com/raspberrypi/pico-sdk).
2. Clone este repositório:
   ```sh
   git clone https://github.com/Lawtrel/Temporizador-periodico---disparo-unico.git
   cd Temporizador

## Compilação e Upload
1. Crie um diretório de build e navegue até ele:
   ```sh
   mkdir build
   cd build
   ```
2. Execute o CMake para configurar o projeto:
   ```sh
   cmake ..
   ```
3. Compile o projeto:
   ```sh
   make
   ```
4. Faça o upload do arquivo `.uf2` gerado para o Raspberry Pi Pico.
