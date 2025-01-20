# CEPEDI

# Grupo 7 Subgrupo 8

# GPIO Control with a 4x4 Keypad - RP2040

## Tarefa 1- Controle de Pinos GPIO com um Teclado Matricial

### Descrição

GPIO Control with a 4x4 Keypad - RP2040
Grupo 7 Subgrupo 8
Tarefa 1 - Controle de Pinos GPIO com um Teclado Matricial
Descrição
Este repositório contém o código-fonte de um projeto desenvolvido em Linguagem C, utilizando o Pico SDK, para controlar os pinos GPIO de um microcontrolador RP2040. A aplicação simula o uso de um teclado matricial 4x4 para controlar LEDs RGB e um buzzer no simulador Wokwi. O objetivo é aplicar conceitos de programação embarcada, simulação eletrônica e versionamento com Git, em um ambiente colaborativo.

A solução implementa estratégias para:

1. Acionamento de LEDs RGB (três LEDs).
2. Controle do sinal sonoro de um buzzer.
3. Interação com um teclado matricial.

## Funcionalidades

1. Controle de LEDs: Acionamento e configuração de cores com base nos inputs do teclado.
2. Sinal Sonoro: Emissão de sons pelo buzzer a partir de combinações específicas de teclas.
3. Integração Simulada: Ambiente configurado no simulador Wokwi, com suporte ao Raspberry Pi Pico W.

## Pré-riquisitos

1. Ambiente de Desenvolvimento VS Code.
2. Pico SDK instalado.
3. Simulador Wokwi configurado.
4. Compilador de C, como GCC.

## Como Usar

1. Clone o repositório:

    ```bash
    git clone https://github.com/LuisMarioRC/TecladoMatricial.git
    ```

2. Navegue até o diretório do projeto:

    ```bash
    cd TecladoMatricial
    ```

3. Compile o código com o compilador de C:

    ```bash
    gcc TecladoMatricial.c -o main
    ```

4. Execute o programa:

    ```bash
    ./main
    ```

## Equipe

A equipe foi formada por membros com as seguintes responsabilidades:

### Líder do Projeto

- <b><a href="https://github.com/LuisMarioRC">Luis Mario</a></b> – Gerenciamento do repositório, revisão de código, integração e documentação.

### Desenvolvedores

- <b><a href="https://github.com/LeonardoGermano">Leonardo</a></b> – Controle de LEDs.
- <b><a href="https://github.com/koda159">Ary Allan</a></b>– Configuração do buzzer.
- <b><a href="https://github.com/vinicius-bash">Vinícius José</a></b>– Implementação do teclado matricial.
- <b><a href="https://github.com/icarosg">Ícaro Gonçalves</a></b> e <b><a href="https://github.com/M00NCX"> Adryelle Thayne</a></b> – Testes e simulação no Wokwi.

## Vídeo

Acesse o vídeo ensaio da solução no link: https://www.dropbox.com/scl/fi/sevkgpridxf9ni0aacf7h/2025-01-19-21-26-02.mkv?rlkey=rylluna7309gd5z1ymwyw3alz&st=7oe5m8l3&dl=0
