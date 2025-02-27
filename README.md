# 🚦 Semáforo Inteligente

## 📌 Sumário

- 🎯 Objetivos
- 📖 Descrição do Projeto
- ⚙️ Funcionalidades Implementadas
- 🛠️ Requisitos do Projeto
- 📂 Estrutura do Repositório
- 🖥️ Como Compilar e Executar
- 🎦 Demonstração em Vídeo
- 🤝 Contribuições
- 📝 Autor

---

## 🎯 Objetivos

- Desenvolver um semáforo funcional utilizando a BitDogLab (Raspberry Pi Pico W).
- Implementar sinais sonoros distintos para cada fase do semáforo, auxiliando pessoas com deficiência visual.
- Exibir mensagens e contagens regressivas no display OLED SSD1306 para fornecer informações claras aos pedestres.
- Criar um projeto educacional acessível e replicável para ensino de sistemas embarcados.

---

## 📖 Descrição do Projeto

O **Semáforo Inteligente** é um sistema que simula um semáforo acessível com sinais visuais e sonoros. Ele é composto por:

- **LED RGB** para representar as cores do semáforo.
- **Buzzer** que emite diferentes sons para cada fase.
- **Display OLED SSD1306** para exibir mensagens e contagens regressivas.

O sistema segue um ciclo contínuo de funcionamento:

1. **Sinal Vermelho**
   - LED vermelho aceso.
   - Buzzer emite um som de alerta intenso.
   - Display mostra "Sinal Vermelho", "PARE" e contagem regressiva de 30s.

2. **Sinal Amarelo**
   - LED amarelo aceso.
   - Buzzer emite um som moderado.
   - Display mostra "Sinal Amarelo", "ALERTA" e contagem regressiva de 5s.

3. **Sinal Verde**
   - LED verde aceso.
   - Buzzer emite um som tranquilo.
   - Display mostra "Sinal Verde", "PROSSIGA" e contagem regressiva de 30s.

Esse projeto é uma solução acessível para melhorar a segurança e a inclusão em travessias de pedestres.

---

## ⚙️ Funcionalidades Implementadas

- Controle do LED RGB para representar as fases do semáforo.
- Emissão de sons distintos para cada cor do semáforo através do buzzer.
- Exibição de mensagens e contagens regressivas no display OLED SSD1306.
- Código modular e estruturado para facilitar futuras expansões.

---

## 🛠️ Requisitos do Projeto

- **Hardware:**
  - BitDogLab (Raspberry Pi Pico W)
  - LED RGB (Cátodo Comum) com resistores de 330Ω
  - Buzzer Piezoelétrico
  - Display OLED SSD1306 (I2C)

- **Software:**
  - VS Code com extensão para RP2040
  - SDK do Raspberry Pi Pico
  - Simulador Wokwi (opcional para testes virtuais)

---

## 📂 Estrutura do Repositório

```
├── Semaforo_Inteligente.c   # Código principal do projeto
├── buzzer.h                 # Controle do buzzer
├── rgb.c                    # Controle do LED RGB
├── rgb.h                    # Definições para o LED RGB
├── ssd1306.c                # Implementação do display OLED
├── ssd1306.h                # Cabeçalho do display OLED
├── font.h                   # Fonte utilizada no display
├── README.md                # Este arquivo
└── diagram.json             # Configuração do projeto no Wokwi
```

---

## 🖥️ Como Compilar e Executar

1. **Clone o repositório:**
   ```sh
   git clone https://github.com/zrcrd/Semaforo_Inteligente.git
   ```
2. **Acesse a pasta do projeto:**
   ```sh
   cd semaforo-inteligente
   ```
3. **Compile o projeto no ambiente configurado para RP2040.**
4. **Carregue o código na BitDogLab e teste a execução.**
5. **Caso utilize o Wokwi, importe o `diagram.json` para simular.**

---

## 🎦 Demonstração em Vídeo

A demonstração do projeto pode ser acessada pelo link: https://drive.google.com/file/d/1IoZrhQkCFuaROjRZil4apuY320b9iYGN/view?usp=drive_link


---

## 🤝 Contribuições

Contribuições são bem-vindas! Para contribuir, siga os passos abaixo:

1. Faça um **fork** do repositório.
2. Crie uma nova branch:
   ```sh
   git checkout -b minha-feature
   ```
3. Realize suas alterações e faça um commit:
   ```sh
   git commit -m 'Adicionando nova funcionalidade'
   ```
4. Envie suas alterações:
   ```sh
   git push origin minha-feature
   ```
5. Abra um **Pull Request**.

---

## 📝 Autor

Projeto desenvolvido por **José Ricardo de Souza Santos**.

Se tiver dúvidas ou sugestões, sinta-se à vontade para contribuir! 🚦🔊

